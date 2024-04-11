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

const int N = 1e5+7;

int n, m;

int a[N];
int b[N];

int u[N];
int v[N];

VI in, out;

bool comp(int p, int q)
{
	return a[p]<a[q];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];

		if(b[i]==1)
			in.pb(i);
		else
			out.pb(i);
	}

	sort(ALL(in), comp);
	sort(ALL(out), comp);

	for(int i = 0; i < in.size(); ++i)
	{
		u[in[i]] = 1;
		v[in[i]] = i+2;
	}

	int i = 0, j = 1;
	
	for(auto it:out)
	{
		if(a[it]<a[in[j]])
		{
			cout << -1;
			return 0;
		}

		u[it] = i+2;
		v[it] = j+2;

		++i;

		if(i==j)
		{
			++j;
			i = 0;
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << u[i] << " " << v[i] << endl;
	}
}