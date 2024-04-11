#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;
const ll N = 3e5 + 7;

ll fact[N];

void init() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * (ll) i % MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	int n;
	cin >> n;
	set <int> sa, sb;
	set <pair <int, int> > sc;
	map <int, int> a, b;
	map <pair <int, int>, int> c;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sa.insert(x), sb.insert(y), sc.insert({x, y});
		a[x]++, b[y]++, c[mp(x, y)]++;
	}
	ll cnt = 0;
	ll now = 1;
	for (ll x : sa) {
		now = now * fact[a[x]] % MOD;
	}
	cnt = (cnt + now) % MOD;
	now = 1;
	for (ll y : sb) {
		now = now * fact[b[y]] % MOD;
	}
	cnt = (cnt + now) % MOD;
	pair <ll, ll> pr = {-1, -1};
	now = 1;
	for (auto t : sc) {
		if (t.first < pr.first || t.second < pr.second) {
			now = 0;
			break;
		}
		pr = t;
		now = now * fact[c[t]] % MOD;
	}
	cnt = (cnt - now + MOD) % MOD;
	cout << (fact[n] - cnt + MOD) % MOD;
}