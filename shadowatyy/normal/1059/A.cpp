#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1e5+7;

int n, L, a, ans;

int t[N];
int l[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> L >> a;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> l[i];
	}

	t[n+1] = L;
	l[n+1] = 0;

	for(int i = 0; i <= n; ++i)
	{
		ans += (t[i+1]-t[i]-l[i])/a;
	}

	cout << ans << endl;
}