#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

int n, l, r, ans = 0;

struct node
{
	node* left;
	node* right;
	int sub, lazy, dp, prior;

	node(int _dp)
	{
		left = NULL;
		right = NULL;
		dp = _dp;
		sub = 1;
		lazy = 0;
		prior = rand();
	}
};

void shift(node* v)
{	
	if(v->lazy)
	{
		if(v->left)
		{
			v->left->dp += v->lazy;
			v->left->lazy += v->lazy;
		}

		if(v->right)
		{
			v->right->dp += v->lazy;
			v->right->lazy += v->lazy;
		}

		v->lazy = 0;
	}
}

void attach(node* v, node *l, node *r)
{
	v->left = l;
	v->right = r;
	v->sub = 1;

	if(v->left)
		v->sub += v->left->sub;

	if(v->right)
		v->sub += v->right->sub;
}

pair<node*, node*> split(node *v, int k)
{
	if(v==NULL)
		return mp(v, v);

	shift(v);

	int left_sub = 1;

	if(v->left)
		left_sub += v->left->sub;

	if(left_sub<=k)
	{
		auto s = split(v->right, k-left_sub);
		attach(v, v->left, s.st);
		return mp(v, s.nd);
	}
	else
	{
		auto s = split(v->left, k);
		attach(v, s.nd, v->right);
		return mp(s.st, v);
	}
}

pair<node*, node*> split_dp(node *v, int k)
{
	if(v==NULL)
		return mp(v, v);

	shift(v);

	if(v->dp<=k)
	{
		auto s = split_dp(v->right, k);
		attach(v, v->left, s.st);
		return mp(v, s.nd);
	}
	else
	{
		auto s = split_dp(v->left, k);
		attach(v, s.nd, v->right);
		return mp(s.st, v);
	}
}

node* merge(node* v, node* u)
{
	if(v==NULL)
		return u;

	if(u==NULL)
		return v;

	shift(v);
	shift(u);

	if(v->prior>u->prior)
	{
		attach(v, v->left, merge(v->right, u));
		return v;
	}
	else
	{
		attach(u, merge(v, u->left), u->right);
		return u;
	}
}

void dfs(node* v, int ind)
{
	if(v->left)
	{
		dfs(v->left, ind);
		ind += v->left->sub;
	}

	if(v->dp<inf)
		ans = max(ans, ind);

	++ind;

	if(v->right)
		dfs(v->right, ind);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	auto root = new node(0);

	for(int i = 2; i <= n+1; ++i)
	{
		auto foo = new node(inf);
		root = merge(root, foo);
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> l >> r;

		auto s1 = split_dp(root, l-1);
		auto s2 = split_dp(s1.nd, r-1);

		auto *a = s1.st;
		auto *m = s2.st;
		auto *b = s2.nd;

		if(m)
		{
			m->dp++;
			m->lazy++;
		}	

		auto tmp = new node(l);
		a = merge(a, tmp);

		auto s3 = split(b, 1);
		b = s3.nd;

		root = merge(a, m);
		root = merge(root, b);
	}

	dfs(root, 0);

	cout << ans;
}