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

#define N 400007

int n, k, res;

int a[N];
int nast[N];
int last[N];
int curr[N];

struct comp
{
	bool operator()(int a, int b)
	{
		if(curr[a]==curr[b])
			return a>b;

		return curr[a]>curr[b];
	}
};

multiset<int, comp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = n; i >= 1; --i)
	{
		if(!last[a[i]])
			nast[i] = inf;
		else
			nast[i] = last[a[i]];

		last[a[i]] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(S.find(a[i])!=S.end())
		{
			S.erase(a[i]);
			curr[a[i]] = nast[i];
			S.insert(a[i]);
			continue;
		}
		else if(S.find(a[i])==S.end() && S.size()<k)
		{
			curr[a[i]] = nast[i];
			S.insert(a[i]);
			++res;
		}
		else
		{
			S.erase(S.begin());
			curr[a[i]] = nast[i];
			S.insert(a[i]);
			++res;
		}
	}

	cout << res;
}