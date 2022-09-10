#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 2e5+7;

int n, ans = INF;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= 2*n; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+2*n+1);

	ans = min(ans, (a[n]-a[1])*(a[2*n]-a[n+1]));

	for(int i = 2; i <= n; ++i)
	{
		ans = min(ans, (a[2*n]-a[1])*(a[i+n-1]-a[i]));
	}

	cout << ans << endl;
}