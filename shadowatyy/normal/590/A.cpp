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

#define N 500007

int n, ans;

int a[N];

bitset<N> stable;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	a[0] = a[1];
	a[n+1] = a[n];

	for(int i = 1; i <= n+1; ++i)
	{
		if(a[i]==a[i-1])
			stable[i] = stable[i-1] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!stable[i])
		{
			int j = i;

			while(j<n && !stable[j+1])
				++j;

			if((j-i+1)%2)
			{
				ans = max(ans, (j-i+2)/2);

				for(int k = i; k <= j; ++k)
				{
					a[k] = a[i-1];
				}
			}
			else
			{
				ans = max(ans, (j-i+1)/2);

				if(a[i-1]==1)
				{
					for(int k = i; k <= (i+j)/2; ++k)
					{
						a[k] = 1;
					}

					for(int k = (i+j)/2+1; k <= j; ++k)
					{
						a[k] = 0;
					}
				}
				else
				{
					for(int k = i; k <= (i+j)/2; ++k)
					{
						a[k] = 0;
					}

					for(int k = (i+j)/2+1; k <= j; ++k)
					{
						a[k] = 1;
					}
				}
			}

			i = j;
		}
	}

	cout << ans << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";
	}
}