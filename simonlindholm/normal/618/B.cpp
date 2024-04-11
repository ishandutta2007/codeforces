#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vi> a(N, vi(N));
	rep(i,0,N) {
		rep(j,0,N) cin >> a[i][j];
	}
	vi skipped(N);
	vi out(N, -1);
	rep(target,1,N+1) {
		rep(i,0,N) {
			if (skipped[i]) continue;
			rep(j,0,N) {
				if (skipped[j]) continue;
				if (a[i][j] == 0) continue;
				if (a[i][j] != target) goto fail;
			}
			skipped[i] = true;
			out[i] = target;
			break;
fail:;
		}
	}
	rep(i,0,N) cout << out[i] << ' ';
	cout << endl;
}