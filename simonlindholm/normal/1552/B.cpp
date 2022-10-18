#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int N;
	cin >> N;
	vector<array<int, 5>> a(N);
	rep(i,0,N) rep(j,0,5) cin >> a[i][j];
	int best = 0;
	rep(i,1,N) {
		int b = 0;
		rep(j,0,5) if (a[i][j] < a[best][j]) b++;
		if (b >= 3) best = i;
	}
	rep(i,0,N) if (i != best) {
		int b = 0;
		rep(j,0,5) if (a[i][j] < a[best][j]) b++;
		if (b >= 3) {
			cout << "-1\n";
			return;
		}
	}
	cout << best + 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	rep(i,0,N) solve();
	exit(0);
}