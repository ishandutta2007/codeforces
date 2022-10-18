#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<array<int, 5>> tm(N);
	array<int, 5> solves{};
	rep(i,0,N) {
		rep(j,0,5) {
			cin >> tm[i][j];
			if (tm[i][j] != -1) solves[j]++;
		}
	}

	auto works = [&](int ext) {
		int tot = 0;
		rep(i,0,5) {
			if (tm[0][i] == -1 && tm[1][i] == -1) continue;
			if (tm[0][i] != -1 && tm[1][i] == -1) {
				int prop = (32 * solves[i] - 1) / (N + ext);
				int sc = -1000000;
				if (prop < 1) sc = 3000;
				else if (prop < 2) sc = 2500;
				else if (prop < 4) sc = 2000;
				else if (prop < 8) sc = 1500;
				else if (prop < 16) sc = 1000;
				else if (prop < 32) sc = 500;
				else assert(0);
				sc = sc * (250 - tm[0][i]) / 250;
				tot += sc;
				continue;
			}
			if (tm[0][i] == -1 && tm[1][i] != -1) {
				int prop = (32 * solves[i] - 1) / (N + ext); // cannot solve :*(
				int sc = -1000000;
				if (prop < 1) sc = 3000;
				else if (prop < 2) sc = 2500;
				else if (prop < 4) sc = 2000;
				else if (prop < 8) sc = 1500;
				else if (prop < 16) sc = 1000;
				else if (prop < 32) sc = 500;
				else assert(0);
				sc = sc * (250 - tm[1][i]) / 250;
				tot -= sc;
				continue;
			}
			assert(tm[0][i] != -1 && tm[1][i] != -1);
			int sc = -1000000;
			auto test = [&](ll lo, ll hi, int v) {
				// Does there exist e such that:
				// double prop = (solves[i] + e) / (N + ext) * 32;
				// is in (lo, hi]?
				lo *= N + ext;
				hi *= N + ext;
				// (solves[i] + e) * 32 in (lo, hi]
				lo -= solves[i] * 32;
				hi -= solves[i] * 32;
				// e * 32 in (lo, hi]
				// also, 0 <= e <= ext
				hi = min(hi >> 5, (ll)ext); // e <= hi
				lo = max(lo >> 5, (ll)-1) + 1; // lo <= e
				if (lo > hi) return;
				sc = max(sc, v * (tm[1][i] - tm[0][i]) / 250);
			};
			test(0,1,3000);
			test(1,2,2500);
			test(2,4,2000);
			test(4,8,1500);
			test(8,16,1000);
			test(16,33,500);
			tot += sc;
		}
		return tot > 0;
	};

	rep(ext,0,1000000) {
		if (works(ext)) {
			cout << ext << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	exit(0);
}