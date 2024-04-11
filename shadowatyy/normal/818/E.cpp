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

#define N 100007

int n, k;

VPII f;

int a[N];
int pref[11][N];

ll res;

bool check(int a, int b)
{
	for(int i = 0; i < f.size(); ++i)
	{
		if(f[i].nd>pref[i][b]-pref[i][a])
			return 0;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	int curr = k;

	for(int i = 2; i*i <= k; ++i)
	{
		if(curr%i==0)
		{
			f.eb(i, 1);
			curr /= i;
		}

		while(curr%i==0)
		{
			++f.back().nd;
			curr /= i;
		}
	}

	if(curr>1)
		f.eb(curr, 1);
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < f.size(); ++j)
		{
			while(a[i]%f[j].st==0)
			{
				a[i] /= f[j].st;
				++pref[j][i];
			}

			pref[j][i] += pref[j][i-1];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int l = i+1, r = n;

		while(l<r)
		{
			int m = (l+r)/2;

			if(m==r)
				--m;

			if(check(i, m))
				r = m;
			else
				l = m+1;
		}

		if(check(i, l))
			res += n-l+1;
	}

	cout << res;
}