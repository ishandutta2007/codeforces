#include <bits/stdc++.h>

using namespace std;
#define maxn 101
#define pii pair<int, int>
#define ld long double

const ld inf = 1e99;
int n;
ld C, T;
ld mintime[101][1001]; //use the first i guys, get a score of j

ld p9pow[101];

bool canfit (ld req, ld excess) {
	//implement this and it should pass
	ld t = max((ld) 0.0, (sqrt(excess*C) - 1.0)/C);


	return req + t + excess/(1.0 + C*t) <= T +  1e-3;


}

void solve() {
	cin >> n;
	cin >> C >> T;
	int ai, pi;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 1000; j++) {
			mintime[i][j] = inf;
		}
	}
	mintime[0][0] = 0.0;
	vector<pii> stuff;
	for (int i = 0; i < n; i++) {
		cin >> ai >> pi;
		stuff.push_back(pii(ai, pi));
	}
	sort(stuff.begin(), stuff.end());
	reverse(stuff.begin(), stuff.end());
	for (pii val : stuff) {
		ai = val.first;
		pi = val.second;

		for (int j = n; j >= 1; j--) {
			for (int k = 1000; k >= 0; k--) {
				int prevpt = k-pi;
				if (prevpt < 0) continue;

				if (mintime[j-1][prevpt] == inf) continue;

				mintime[j][k] = min(mintime[j][k], 
					mintime[j-1][prevpt] + 10 + 
					ai*1.0 / p9pow[j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 1000; j++) {
			ld req = 10*i;
			ld excess = mintime[i][j] - req;

			if (canfit(req, excess)) {
				ans = max(ans, j);
			}
		}
	}

	// cout << "thing: " << mintime[1][5] << endl;

	cout << ans << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	p9pow[0] = 1.0;

	for (int i = 1; i <= 100; i++) {
		p9pow[i] = p9pow[i-1] * 0.9;
	}
	while (tc--) {
		solve();
	}
	cout.flush();
}