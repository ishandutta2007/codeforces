#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef long long ll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi> vvi;

struct Event
{
	ll fromBegin, toBegin;
	bool isPoint;
};

struct List
{
	int x;
	ll left, right;
};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

vector < List > tree;
int curk;

int n;
ll g, r, p;
vll len;
vll sum;
vll query;
vll time_to;
int q;

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifndef _DEBUG
	ios_base::sync_with_stdio(false);
	cin >> n >> g >> r;
#else
	if (!(cin >> n >> g >> r))
	{
		return false;
	}
#endif
	len.resize(n + 1);
	sum.resize(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		cin >> len[i];
	}
	for (int i = n; i >= 0; --i)
	{
		sum[i] = len[i] + ((i == n) ? 0LL : sum[i + 1]);
#ifdef _DEBUG
		cerr << "sum[" << i << "] = " << sum[i] << endline;
#endif
	}
	cin >> q;
	query.resize(q);
	for (int i = 0; i < q; ++i)
	{
		cin >> query[i];
	}
#ifdef _DEBUG
	return true;
#endif
}

void add_id(const ll pos, const int v, const int val)
{
#ifdef _DEBUG
	cerr << "add " << pos << " " << v << " " << val << endline;
#endif
	if (pos >= tree[v].left && pos <= tree[v].right)
	{
		if (tree[v].left == tree[v].right)
		{
			tree[v].x = min(tree[v].x, val);
		}
		else
		{
			add_id(pos, v * 2, val);
			add_id(pos, v * 2 + 1, val);
			tree[v].x = min(tree[v * 2].x, tree[v * 2 + 1].x);
		}
	}
}

int get_min(const ll l, const ll r, const int v)
{
#ifdef _DEBUG
	cerr << "(query " << l << " " << r << " " << v << endline;
#endif
	ll l1 = tree[v].left, r1 = tree[v].right;
	int res = n + 2;
	if (max(l1, l) <= min(r1, r))
	{
		if (l <= l1 && r >= r1)
		{
			res = min(res, tree[v].x);
		}
		else
		{
			res = min(get_min(l, r, v * 2),
					get_min(l, r, v * 2 + 1));
		}
	}
#ifdef _DEBUG
	cerr << "return " << res << ")" << endline;
#endif
	return res;
}

ll get_id(const ll x)
{
	ll left_b = (g - x % p + p) % p,
	   right_b = (g + r - x % p - 1 + p) % p;
#ifdef _DEBUG
	cerr << "get_id " << x << " conv to [" << left_b << "; " << right_b << "]" << endline;
#endif
	int cur_res = n + 2;
	if (left_b <= right_b)
	{
		cur_res = min(cur_res, get_min(left_b, right_b, 1));
	}
	else
	{
		cur_res = min(cur_res, min(get_min(0, right_b, 1), 
					get_min(left_b, p, 1)));
	}
	ll res = 0LL;
	if (cur_res == n + 2)
	{
		res = x;
	}
	else
	{
		ll t_add = (p - (x - sum[cur_res]) % p) % p + (x - sum[cur_res]);
		res = t_add + time_to[cur_res];
	}
	return res;
}

void calc()
{
	vll stp;
	p = r + g;
	for (int i = 1; i <= n; ++i)
	{
		stp.pb((p - sum[i] % p) % p);
	}
	sort(stp.begin(), stp.end());
	int un = unique(stp.begin(), stp.end()) - stp.begin();
	stp.resize(un);
	curk = 2;
	while (curk < un)
	{
		curk *= 2;
	}
	tree.resize(2 * curk);
	for (int i = 0; i < un; ++i)
	{
		tree[i + curk].x = n + 2;
		tree[i + curk].left = tree[i + curk].right = stp[i];
	}
	for (int i = un; i < curk; ++i)
	{
		tree[i + curk].x = n + 2;
		tree[i + curk].left = tree[i + curk].right = LINF;
	}
	for (int i = curk - 1; i > 0; --i)
	{
		tree[i].x = n + 2;
		tree[i].left = tree[i * 2].left;
		tree[i].right = tree[i * 2 + 1].right;
	}
	time_to.assign(n + 1, 0LL);
	for (int i = n; i > 0; --i)
	{
		time_to[i] = get_id(sum[i]);
		add_id((p - sum[i] % p) % p, 1, i);
#ifdef _DEBUG
		cerr << "time[" << i << "] = " << time_to[i] << endline;
#endif
	}
#ifdef _DEBUG
	for (int i = 0; i < un; ++i)
	{
		cerr << "x = " << tree[i + curk].left << "; val = " << tree[i + curk].x << endline;
	}
#endif
	for (int i = 0; i < q; ++i)
	{
		cout << get_id(sum[0] + query[i]) << endline;
	}
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {
#else
	input_data();
#endif
	calc();
#ifdef _DEBUG
	}
#endif
	return 0;
}