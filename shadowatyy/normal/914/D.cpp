#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 5e5+7;
const int M = 1<<19;

int n, q;

int a[N];
int g[2*M];

void insert(int a, int v)
{
	a += M;
	g[a] = v;
	a /= 2;

	while(a)
	{
		g[a] = __gcd(g[2*a], g[2*a+1]);
		a /= 2;
	}
}

int query(int a, int b, int x, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b)
		return 0;

	if(a<=l && r<=b)
	{
		if(g[v]%x==0)
			return 0;
		else
		{	
			if(l==r)
				return 1;

			if(g[2*v]%x!=0 && g[2*v+1]%x!=0)
				return 2;

			if(g[2*v]%x!=0)
				return query(a, b, x, 2*v, l, (l+r)/2);
			else
				return query(a, b, x, 2*v+1, (l+r)/2+1, r);
		}
	}

	return query(a, b, x, 2*v, l, (l+r)/2)+query(a, b, x, 2*v+1, (l+r)/2+1, r);
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		insert(i, a[i]);
	}

	cin >> q;

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{	
			int l, r, x;
			cin >> l >> r >> x;

			if(query(l, r, x)<=1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			int i, y;
			cin >> i >> y;
			insert(i, y);
		}
	}
}