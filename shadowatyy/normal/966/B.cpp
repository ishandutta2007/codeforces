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

#define int long long
const int N = 3e5+7;
const int M = 1<<19;

int n, x1, x2;

ll c[N];

VI v;

struct tree_fun
{
	ll cA[2*M];
	int cB[2*M];

	inline void insert(ll A, int B, int v = 1, int l = 0, int r = M-1)
	{
		if(cA[v]*-l+cB[v]>=A*-l+B && cA[v]*-r+cB[v]>=A*-r+B)
			return;

		if(cA[v]*-l+cB[v]<=A*-l+B && cA[v]*-r+cB[v]<=A*-r+B)
		{
			cA[v] = A;
			cB[v] = B;
			return;
		}

		insert(A, B, 2*v, l, (l+r)/2);
		insert(A, B, 2*v+1, (l+r)/2+1, r);
	}

	inline ll query(int a)
	{
		int x = a;
		ll ans = 0;
		a += M;

		while(a)
		{
			ans = max(ans, cA[a]*-x+cB[a]);
			a /= 2;
		}

		return ans;
	}
}TF;

struct tree
{
	int load[2*M];

	inline void insert(int a, int v)
	{
		a += M;

		while(a)
		{
			load[a] = max(load[a], v);
			a /= 2;
		}
	}

	inline int query(int a, int b)
	{
		if(a>b)
			return 0;

		a += M;
		b += M;

		int ans = max(load[a], load[b]);

		while(a<b-1)
		{
			if(a%2==0)
				ans = max(ans, load[a+1]);

			if(b%2==1)
				ans = max(ans, load[b-1]);

			a /= 2;
			b /= 2;
		} 

		return ans;
	}
}T;

void ok(int a, int b, int s)
{
	VI v1, v2;

	for(int i = a; i <= b; ++i)
	{
		v1.pb(v[i]);
	}

	for(int i = s; i < n; ++i)
	{
		if(i<a || i>b)
			v2.pb(v[i]);
	}

	cout << "Yes" << endl;	
	cout << v1.size() << " " << v2.size() << endl;

	for(auto it:v1)
		cout << it << " ";

	cout << endl;

	for(auto it:v2)
		cout << it << " ";

	cout << endl;
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x1 >> x2;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		v.pb(i);
	}

	sort(ALL(v), [](int a, int b)
	{
		return c[a]<c[b];
	});

	for(int i = 0; i < n; ++i)
	{
		T.insert(i, (n-i)*c[v[i]]);
	}

	for(int i = 0; i < n; ++i)
	{
		int l = (x1+c[v[i]]-1)/c[v[i]];

		if(i+l-1<n)
		{
			if(T.query(i+l, n-1)>=x2)
			{
				for(int j = i+l; j < n; ++j)
				{
					if((n-j)*c[v[j]]>=x2)
						ok(i, i+l-1, j);
				}
			}

			if(TF.query(l)>=x2)
			{
				for(int j = 0; j < i; ++j)
				{
					if((n-j-l)*c[v[j]]>=x2)
						ok(i, i+l-1, j);
				}
			}
		}

		TF.insert(c[v[i]], (n-i)*c[v[i]]);
	}

	cout << "No" << endl;
}