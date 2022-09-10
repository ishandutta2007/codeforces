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
	
#define N 100007
#define M 1000000007

int n;

ll res;

int a[N], m[N], cnt[N];

ll pot(int w)
{
	ll p = 2, res = 1;

	for(int i = 0; i < 31; ++i)
	{
		if(w&(1<<i))
			res = (res*p)%M;

		p = (p*p)%M;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	m[1] = 1;

	for(int i = 1; i < N; ++i)
	{
		for(int j = 2*i; j < N; j += i)
		{
			m[j] -= m[i];
		}
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		for(int j = 1; j*j <= a[i]; ++j)
		{
			if(a[i]%j==0)
			{
				++cnt[j];

				if(a[i]/j!=j)
					++cnt[a[i]/j];
			}
		}
	}

	for(int i = 1; i < N; ++i)
	{
		res = ((res+m[i]*(pot(cnt[i])-1))%M+M)%M;
	}

	cout << res;
}