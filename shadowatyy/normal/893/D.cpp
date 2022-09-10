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
using namespace std;

#define int long long
const int N = 1e5+7;

int n, d, res;

int a[N];
int od_teraz[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> d;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = n; i >= 1; --i)
	{
		od_teraz[i] = max(od_teraz[i], a[i]);
		od_teraz[i] = max(od_teraz[i], a[i]+od_teraz[i+1]);
	}

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==0)
		{
			if(curr<0)
			{
				++res;
				curr += d-curr-od_teraz[i];

				if(curr<0)
				{
					cout << -1;
					return 0;
				}
			}
		}
		else
			curr += a[i];

		if(curr>d)
		{
			cout << -1;
			return 0;
		}
	}

	cout << res;
}