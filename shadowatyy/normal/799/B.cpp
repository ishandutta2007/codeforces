#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 200007

int n, q, c;

int p[N];
int a[N];
int b[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return p[a]<p[b];
	}
};

set<int, comp> F[4], B[4];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		F[a[i]].insert(i);
		B[b[i]].insert(i);
	}

	cin >> q;

	while(q--)
	{
		cin >> c;

		if(F[c].empty() && B[c].empty())
		{
			cout << -1 << " ";
		}
		else if(F[c].empty())
		{
			int t = *B[c].begin();
			F[a[t]].erase(t);
			B[b[t]].erase(t);

			cout << p[t] << " ";
		}
		else if(B[c].empty())
		{
			int t = *F[c].begin();
			F[a[t]].erase(t);
			B[b[t]].erase(t);

			cout << p[t] << " ";
		}
		else if(p[*F[c].begin()]<p[*B[c].begin()])
		{
			int t = *F[c].begin();
			F[a[t]].erase(t);
			B[b[t]].erase(t);

			cout << p[t] << " ";
		}
		else
		{
			int t = *B[c].begin();
			F[a[t]].erase(t);
			B[b[t]].erase(t);

			cout << p[t] << " ";
		}
	}
}