#include <bits/stdc++.h>

using namespace std;
const int maxn = 100010;
#define ll long long
int n;

const ll inf = 1000000007;

vector<int> ch[maxn];
int par[maxn];

ll s[maxn];

bool ok;

ll ans = 0LL;

void go(int u, int d) {
	if (d%2 == 0) {

		if (ch[u].size() == 0) return;

		ll minb = inf;
		for (int v : ch[u]) {
			minb = min(minb, s[v]);
		}

		if (minb < s[par[u]]) {
			ok = false;
			return;
		}

		s[u] = minb;
		ans += minb - s[par[u]];



	}
	else {
		if (s[u] < s[par[u]]) {
			ok = false;
			return;
		}
		ans += s[u] - s[par[u]];

	}

	// cout << "after " << u << " : " << ans << endl;

	for (int v : ch[u]) {
		go(v, d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		ch[par[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	ok = true;
	go(1, 1);

	if (!ok) cout << -1 << endl;
	else cout << ans << endl;

}