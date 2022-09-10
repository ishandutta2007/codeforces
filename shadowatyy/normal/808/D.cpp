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

int n;

ll a[N];
ll sum[N];

map<ll, ll> Max;
map<ll, ll> Min;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];

		Max[a[i]] = i;

		if(Min.find(a[i])==Min.end())
			Min[a[i]] = i;
	}

	for(int i = 1; i < n; ++i)
	{
		if((sum[n]-sum[i])-sum[i]==0)
		{
			cout << "YES";
			return 0;
		}
	}

	for(int i = 0; i <= n-2; ++i)
	{
		ll suf = (sum[n]-sum[i])-sum[i];

		if(suf%2==0 && Max.find(suf/2)!=Max.end() && Max[suf/2]>i)
		{
			cout << "YES";
			return 0;
		}
	}

	for(int i = 2; i <= n; ++i)
	{
		ll pref = sum[i]-(sum[n]-sum[i]);

		if(pref%2==0 && Min.find(pref/2)!=Min.end() && Min[pref/2]<=i)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

}