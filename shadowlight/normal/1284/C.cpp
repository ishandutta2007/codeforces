#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 3e5 + 7;

int fact[N];

int mod;

void add(ll &x, ll y) {
	x += y;
	x %= mod;
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdou t);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> mod;
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * (ll) i % mod;
	}
	ll res = 0;
	for (int len = 1; len <= n; len++) {
		int cnt = n - len + 1;
		ll now = cnt * (ll) fact[len] % mod;
		now = now * (ll) fact[n - len] % mod;
		now = now * (ll) cnt % mod;
		add(res, now);
	}
	cout << res << "\n";

}