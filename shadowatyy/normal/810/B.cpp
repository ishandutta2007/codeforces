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

#define int long long
#define N 100007

int n, f, res;

int k[N];
int l[N];

VI v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> f;

	for(int i = 1; i <= n; ++i)
	{
		cin >> k[i] >> l[i];

		int a = min(k[i], l[i]);
		int b = min(2*k[i], l[i]);

		v.pb(b-a);

		res += a;
	}

	sort(ALL(v));
	reverse(ALL(v));

	for(int i = 0; i < f; ++i)
		res += v[i];

	cout << res;
}