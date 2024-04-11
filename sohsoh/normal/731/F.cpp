#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

bool B[MAXN];
ll cnt[MAXN], ps[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		cnt[x]++;
	}	

	for (int i = 1; i < MAXN; i++) ps[i] = ps[i - 1] + cnt[i];

	sort(all(v));
	ll ans = 0;

	for (int e : v) {
		if (B[e]) continue;
		ll tans = 0;
		for (int i = 1; (i + 1) * e < MAXN; i++)
			tans += 1ll * i * e * (ps[(i + 1) * e - 1] - ps[i * e - 1]);
		
		for (int j = e; j < MAXN; j += e) B[j] = true;
		ans = max(ans, tans);
	}

	cout << ans << endl;
	return 0;
}