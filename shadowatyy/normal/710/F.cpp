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

const int MOD = 1e9+7;
const int P = 31;
const int N = 3e5+7;

int n, t;

char s[N];

set<ll> S[N];
set<int> len;

int p[N];

int h[N];

int32_t main()
{
	p[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		p[i] = ((ll)P*p[i-1])%MOD;
	}

	scanf("%d\n", &n);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%d ", &t);

		int r = 0;

		while((s[++r] = getchar())!='\n');

		--r;

		if(t==1 || t==2)
		{
			if(t==1)
				len.insert(r);

			int h = 0;

			for(int i = 1; i <= r; ++i)
			{
				h = (h+(ll)(s[i]-96)*p[i])%MOD;
			}

			h = ((ll)h*p[N-r])%MOD;

			if(t==1)
				S[r].insert(h);
			else
				S[r].erase(h);
		}
		else
		{
			int ans = 0;

			for(int i = 1; i <= r; ++i)
			{
				h[i] = (h[i-1]+(ll)(s[i]-96)*p[i])%MOD;
			}

			for(auto it:len)
			{
				for(int i = it; i <= r; ++i)
				{
					int ha = (ll)(h[i]-h[i-it]+MOD)*p[N-i]%MOD;

					if(S[it].find((ll)ha)!=S[it].end())
						++ans;
				}
			}

			printf("%d\n", ans);
			fflush(stdout);
		}
	}


}