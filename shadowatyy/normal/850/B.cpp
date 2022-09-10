#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 10000000000000007LL
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

const int N = 2e6+7;

int n, x, y;

ll ile[N];
ll sum[N];

ll res = INF;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x >> y;

	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		sum[a] += a;
		ile[a] += 1;
	}

	for(int i = 1; i < N; ++i)
	{
		ile[i] += ile[i-1];
		sum[i] += sum[i-1];
	}

	int op = x/y;

	for(int i = 2; i < N; ++i)
	{
		ll curr = 0;

		int skok = min(op, i-1);

		for(int j = i; j < N; j += i)
		{
			ll c = ((ile[j]-ile[j-skok-1])*j-(sum[j]-sum[j-skok-1]));

			if(c>INF/y)
			{
				curr = INF;
				break;
			}

			curr += y*c;
			curr += x*(ile[j-skok-1]-ile[j-i]);

			if(curr>res)
				break;
		}

		res = min(res, curr);
	}

	cout << res;
}