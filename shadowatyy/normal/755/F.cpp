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

#define N 1000007

int n, k, ile2, ile1, Max;

VI r, w;

int p[N];

bitset<N> vis;
bitset<N> dp;

queue<PII> Q;

int ile[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			int curr = 1, v = i;
			vis[v] = 1;

			while(!vis[p[v]])
			{
				++curr;
				v = p[v];
				vis[v] = 1;
			}

			r.pb(curr);
		}
	}

	for(auto it:r)
	{
		ile2 += it/2;
		ile1 += it%2;
	}

	int curr = k;

	while(curr>0 && ile2>0)
	{
		--ile2;
		--curr;
		Max += 2;
	}

	while(curr>0 && ile1>0)
	{
		--ile1;
		--curr;
		Max += 1;
	}

	for(auto it:r)
	{
		++ile[it];
	}

	dp[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; ile[i] > 0; ++j)
		{
			int q = min(ile[i], (1<<j));
			dp |= (dp<<(q*i));
			ile[i] -= q;
		}		
	}

	if(dp[k])
		cout << k << " " << Max;
	else
		cout << k+1 << " " << Max;
}