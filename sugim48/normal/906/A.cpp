#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<ll, int> ll_i;
struct edge { int v, w, h; };
const int INF = INT_MAX / 10;
const int MOD = 1e9 + 7;

int main() {
	vector<bool> a(26, true);
	int ans = 0;
	int Q; cin >> Q;
	rep(q, Q) {
		int cnt = 0;
		rep(k, 26) if (a[k]) cnt++;
		string s, t; cin >> s >> t;
		if (q != Q - 1 && cnt == 1 && (s == "!" || s == "?")) ans++;
		if (s == "." || s == "?") {
			vector<bool> b(26);
			for (char c: t) b[c - 'a'] = true;
			rep(k, 26) if (b[k]) a[k] = false;
		}
		if (s == "!") {
			vector<bool> b(26);
			for (char c: t) b[c - 'a'] = true;
			rep(k, 26) if (!b[k]) a[k] = false;
		}
	}
	cout << ans << endl;
}