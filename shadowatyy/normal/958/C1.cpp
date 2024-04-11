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

const int N = 1e5+7;

int n, p, ans;

int a[N];
int suf[N];
int pref[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> p;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		pref[i] = pref[i-1] + a[i];
		pref[i] %= p;
	}

	for(int i = n; i >= 1; --i)
	{
		suf[i] = suf[i+1] + a[i];
		suf[i] %= p;

		if(i!=1)
			ans = max(ans, pref[i-1] + suf[i]);
	}

	cout << ans << endl;
}