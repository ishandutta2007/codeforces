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

#define N (1<<17)

int n;

int deg[N];
int s[N];

queue<int> Q;

VPII res;

bitset<N> vis;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> deg[i] >> s[i];
	}

	for(int i = 0; i < n; ++i)
	{
		if(deg[i]==1)
		{
			Q.push(i);
			vis[i] = 1;
		}
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		if(deg[v]==0)
			continue;

		if(deg[s[v]]>=1)
		{
			res.eb(v, s[v]);
			--deg[v];
			--deg[s[v]];
			s[s[v]] ^= v;

			if(deg[s[v]]<=1 && !vis[s[v]])
			{
				Q.push(s[v]);
				vis[s[v]] = 1;
			}
		}
	}

	cout << res.size() << endl;

	for(auto it:res)
		cout << it.st << " " << it.nd << endl;
}