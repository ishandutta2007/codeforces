#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll MOD = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> p(n), q(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> q[i];
		q[i]--;
	}
	ll hp = 0, hq = 0;
	vector <ll> pws(n, 0);
	pws[0] = 1;
	for (ll i = 1; i < n; i++) {
		pws[i] = (pws[i - 1] * 2) % MOD;
	}
	vector <int> col(n, -1);
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (hp == hq) {
			now++;
		}
		if (now >= k) break;
		hp = (hp + pws[p[i]]) % MOD;
		hq = (hq + pws[q[i]]) % MOD;
		col[p[i]] = now - 1;
	}
	if (now < k) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << (col[i] == -1 ? (char) ('a' + now - 1) : (char) ('a' + col[i]));
	}
	cout << "\n";
}