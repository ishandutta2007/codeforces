#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
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

#define N 500

int n, m, a, b, t;

ll res;

struct mat
{
	bitset<N> m[N];
	mat();
};

mat::mat()
{
	for(int i = 0; i < N; ++i)
	{
		m[i].reset();
	}
}

mat p[67];
mat r[67];

mat operator*(const mat &a, const mat &b)
{
	mat r, q;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			q.m[i][j] = b.m[j][i];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			r.m[i][j] = (a.m[i]&q.m[j]).any();
		}
	}

	return r;
}

bool dobra(const mat &a)
{
	for(int i = 0; i < n; ++i)
	{
		if(a.m[0][i])
			return 1;
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> m;

	mat P, R, A, B;

	for(int i = 0; i < n; ++i)
	{
		A.m[i][i] = 1;
	}

	while(m--)
	{
		cin >> a >> b >> t;
		--a;
		--b;

		if(t==0)
			P.m[a][b] = 1;
		else
			R.m[a][b] = 1;
	}

	p[0] = P;
	r[0] = R;

	for(int i = 1; i <= 60; ++i)
	{
		p[i] = p[i-1]*r[i-1];
		r[i] = r[i-1]*p[i-1];
	}

	for(int i = 60; i >= 0; --i)
	{
		if(__builtin_popcountll(res)%2==0)
			B = A*p[i];
		else
			B = A*r[i];

		if(dobra(B))
		{
			A = B;
			res += (1ll<<i);
		}
			
	}

	if(res>1000000000000000000ll)
		cout << -1;
	else
		cout << res;

}