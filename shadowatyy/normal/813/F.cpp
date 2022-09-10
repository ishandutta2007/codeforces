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

#define N 100007
#define z pair<PII, PII>

int n, q, a, b;

int f[N];
int w[N];
int r[N];

map<PII, VI> M;

int res[N];

int Find(int a, int &d)
{
	d += w[a];

	if(f[a]!=a)
		return Find(f[a], d);

	return f[a];
}

void solve(int a, int b, vector<z> v, int c)
{
	vector<pair<PII, int> > u;

	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i].nd.st>b || a>v[i].nd.nd)
		{
			swap(v.back(), v[i]);
			v.pop_back();
			--i;
		}
	}

	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i].nd.st<=a && b<=v[i].nd.nd)
		{
			int p = v[i].st.st, q = v[i].st.nd, dp = 0, dq = 0, P = Find(p, dp), Q = Find(q, dq);

			if(P==Q)
			{
				if(dp%2==dq%2)
					++c;
			}
			else
			{
				if(r[P]>r[Q])
				{	
					u.eb(mp(P, Q), r[Q]);
					r[P] += r[Q];
					f[Q] = P;
					w[Q] = dp+1+dq;
				}
				else
				{
					u.eb(mp(Q, P), r[P]);
					r[Q] += r[P];
					f[P] = Q;
					w[P] = dq+1+dp;
				}
			}

			swap(v[i], v.back());
			v.pop_back();
			--i;
		}
	}

	if(a==b)
		res[a] = c;
	else
	{
		int k = (a+b)/2;

		solve(a, k, v, c);
		solve(k+1, b, v, c);
	}

	reverse(ALL(u));
		
	for(auto it:u)
	{
		f[it.st.nd] = it.st.nd;
		w[it.st.nd] = 0;
		r[it.st.st] -= it.nd;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	cin >> n >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> a >> b;

		if(a>b)
			swap(a, b);

		M[{a, b}].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		f[i] = i;
		r[i] = 1;
	}

	vector<z> s;

	for(auto it:M)
	{
		if(it.nd.size()%2==1)
			it.nd.pb(q+1);

		for(int i = 0; i < it.nd.size(); i += 2)
		{
			s.eb(mp(it.st.st, it.st.nd), mp(it.nd[i], it.nd[i+1]-1));
		}
	}

	solve(1, q, s, 0);

	for(int i = 1; i <= q; ++i)
	{
		if(res[i])
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}