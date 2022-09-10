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
#define flush fflush(stdout)
using namespace std;

#define N 200007
#define LOG 18

int n, f;

int d[N];
int p[LOG][N];

bool child(int a, int b)
{
	for(int i = LOG-1; i >= 0; --i)
	{
		if(p[i][a]>=b)
			a = p[i][a];
	}

	return a==b;
}

int lca(int a, int b)
{
	if(child(a, b))
		return b;

	if(child(b, a))
		return a;

	int l = LOG-1;

	while(l>=0)
	{
		if(child(b, p[l][a]))
			--l;
		else
			a = p[l][a];
	}

	return p[0][a];
}

int dist(int a, int b)
{
	return d[a]+d[b]-2*d[lca(a, b)];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < LOG; ++i)
	{
		p[i][1] = 1;
	}

	int a = 1, b = 1, curr = 0;

	for(int i = 2; i <= n; ++i)
	{
		cin >> f;
		d[i] = d[f]+1;
		p[0][i] = f;

		for(int j = 1; j < LOG; ++j)
		{
			p[j][i] = p[j-1][p[j-1][i]];
		}

		//cerr << child(2, 1) << endl;

		int d1 = dist(a, i);

		if(d1>curr)
		{
			curr = d1;
			b = i;
		}

		int d2 = dist(i, b);

		if(d2>curr)
		{
			curr = d2;
			a = i;
		}

		cout << curr << " ";
	}
}