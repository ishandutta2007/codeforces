// Sohsoh84 :)))
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

const ll MAXN = 1e6 + 10;

int cnt[MAXN], n, m, q, ans;

inline void Add(int u, int v) {
	if (v > u) swap(v, u);
	if (cnt[v] == 0) ans--;
	cnt[v]++;
}

inline void Remove(int u, int v) {
	if (v > u) swap(v, u);
	cnt[v]--;
	if (cnt[v] == 0) ans++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ans = n;

	while (m--) {
		int u, v;
		cin >> u >> v;
		Add(u, v);
	}

	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int u, v;
			cin >> u >> v;
			Add(u, v);
		} else if (c == 2) {
			int u, v;
			cin >> u >> v;
			Remove(u, v);
		} else cout << ans << endl;
	}
	return 0;
}