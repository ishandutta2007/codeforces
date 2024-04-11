#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int main() {
	int N; ll x; cin >> N >> x;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	rep(i, N) {
		while (x * 2 < a[i]) x *= 2, ans++;
		x = max(x, a[i]);
	}
	cout << ans << endl;
}