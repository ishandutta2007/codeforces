#include <bits/stdc++.h>

using namespace std;
#define MN 200005 
typedef long long ll;

ll W;
int n;

struct wgh {
	int id;
	ll w;
	wgh(int id = 0, ll w = 0) : id(id), w(w) {}
	void in(int i) { id = i; cin >> w; }
} w[MN];

bool operator< (wgh w1, wgh w2) {
	if (w1.w != w2.w) return w1.w < w2.w;
	return w1.id < w2.id;
}

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> n >> W;
		for (int i = 0; i < n; i++) w[i].in(i);
		sort(w, w + n);
		n = lower_bound(w, w + n, wgh(n, W)) - w;
		int jj = lower_bound(w, w + n, wgh(-1, (W + 1) / 2)) - w;
		if (jj != n) {
			cout << 1 << endl;
			cout << w[jj].id + 1 << endl;
			continue;
		}
		ll ww = 0;
		for (int i = 0; i < n; i++) {
			ww += w[i].w;
			if (ww >= (W + 1) / 2) {
				assert(ww <= W);
				cout << i + 1 << endl;
				for (int j = 0; j <= i; j++) cout << w[j].id + 1 << ' ';
				cout << endl;
				break;
			}
		}
		if (ww < (W + 1) / 2) cout << -1 << endl;
	}
	
	return 0;
	
}