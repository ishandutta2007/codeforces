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
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 2e5+7;
const int M = (1<<18);

int n, q;

int t[N];
int b[N];

struct gauss
{	
	VI m;

	void merge(const gauss &s)
	{
		for(auto x:s.m)
		{
			int tmp = x;

			for(auto it:m)
			{
				if(it&-it&tmp)
					tmp ^= it;
			}

			if(!tmp)
				continue;

			for(auto &it:m)
			{
				if(tmp&-tmp&it)
					it ^= tmp;
			}

			m.pb(tmp);
		}
	}

	void insert(int tmp)
	{
		for(auto it:m)
		{
			if(it&-it&tmp)
				tmp ^= it;
		}

		if(!tmp)
			return;

		for(auto &it:m)
		{
			if(it&-it&tmp)
				it ^= tmp;
		}

		m.pb(tmp);
	}

	gauss(){};
};

gauss tree[2*M];

void update(int a, int k)
{
	a += M;
	tree[a].m.clear();	
	tree[a].insert(k);
	a /= 2;

	while(a>=1)
	{
		tree[a] = tree[2*a];
		tree[a].merge(tree[2*a+1]);
		a /= 2;
	}
}

gauss get(int a, int b)
{
	if(a>b)
		return gauss();

	a += M;
	b += M;

	gauss res = tree[a];

	if(a!=b)
		res.merge(tree[b]);

	while(a<b-1)
	{
		if(a%2==0)
			res.merge(tree[a+1]);

		if(b%2==1)
			res.merge(tree[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int load[2*M];

void insert(int a, int b, int k)
{
	a += M;
	b += M;

	load[a] ^= k;

	if(a!=b)
		load[b] ^= k;

	while(a<b-1)
	{
		if(a%2==0)
			load[a+1] ^= k;

		if(b%2==1)
			load[b-1] ^= k;

		a /= 2;
		b /= 2;
	}
}

int query(int a)
{
	int res = t[a];
	a += M;

	while(a>=1)
	{
		res ^= load[a];
		a /= 2;
	}

	return res;
}

void build()
{
	for(int i = 2; i <= n; ++i)
	{
		tree[i+M].insert(b[i]);
	}

	for(int i = M-1; i >= 1; --i)
	{
		tree[i] = tree[2*i];
		tree[i].merge(tree[2*i+1]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}

	for(int i = 2; i <= n; ++i)
	{
		b[i] = t[i-1]^t[i];
	}

	build();

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int a, b, k;
			cin >> a >> b >> k;

			insert(a, b, k);
			
			if(a>=2)
				update(a, query(a-1)^query(a));

			if(b+1<=n)
				update(b+1, query(b)^query(b+1));
		}
		else
		{
			int a, b;
			cin >> a >> b;

			if(a==b)
			{
				if(query(a))
					cout << 2 << endl;
				else
					cout << 1 << endl;
			}
			else
			{
				gauss g = get(a+1, b);
				//cerr << query(a) << endl;
				g.insert(query(a));
				cout << (1<<g.m.size()) << endl;
			}
		}
	}
}