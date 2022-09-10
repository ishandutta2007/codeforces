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

const int N = (1<<22)+7;

int n, m;

bitset<N> in;
bitset<N> vis;

int neg(int a)
{
	return ((1<<n)-1)&(~a);
}

queue<int> Q;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a;
		cin >> a;
		in[a] = 1;
	}

	int ans = 0;

	for(int i = 0; i < 1<<n; ++i)
	{
		if(in[i] && !vis[i])
		{
			++ans;
			Q.push(i);
			vis[i] = 1;

			while(!Q.empty())
			{
				int v = Q.front();
				Q.pop();

				if(in[v] && !vis[neg(v)])
				{
					Q.push(neg(v));
					vis[neg(v)] = 1;
				}

				for(int j = 0; j < n; ++j)
				{
					if((v&(1<<j)) && !vis[v^(1<<j)])
					{
						Q.push(v^(1<<j));
						vis[v^(1<<j)] = 1;
					}
				}
			}
		}
	}

	cout << ans << endl;
}