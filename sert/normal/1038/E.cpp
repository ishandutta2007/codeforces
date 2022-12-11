#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)10;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

ll sum[N][N];
ll num[N][N];
int minE[N][N];

vector<pair<int, int>> es = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};

void solve() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= i; j++) {
			minE[j][i] = INF;
			sum[j][i] = num[j][i] = 0;
		}
	}

	while (m--) {
		int v1, v2, val;
		scanf("%d%d%d", &v1, &val, &v2);
		v1--;
		v2--;
		if (v1 > v2) swap(v1, v2);
		sum[v1][v2] += val;
		num[v1][v2]++;
		minE[v1][v2] = min(minE[v1][v2], val);
	}

	ll ans = 0;
	for (int maskV = 1; maskV < 16; maskV++) {
		int st = -1;
		for (int i = 0; st == -1 && i < 4; i++) if (maskV & (1 << i)) st = i;

		for (int maskE = 0; maskE < 64; maskE++) {
			ll cur = 0;
			bool fail = false;
			vector<int> deg(4, 0);
			for (int i = 0; i < 6; i++) {
				int v1 = es[i].first;
				int v2 = es[i].second;
				if ((maskV & (1 << v1)) == 0 || (maskV & (1 << v2)) == 0) continue;
				if (maskE & (1 << i)) {
					deg[v1]++;
					deg[v2]++;
					if (num[v1][v2] == 0) fail = true;
					if (num[v1][v2] % 2) cur += sum[v1][v2];
					else cur += sum[v1][v2] - minE[v1][v2];
				} else {
					if (num[v1][v2] % 2) cur += sum[v1][v2] - minE[v1][v2];
					else cur += sum[v1][v2];
				}
				//if (maskV == 3 && maskE == 0 && D) cout << i << " " << cur << "\n";
			} 

			int numOdd = 0;
			for (int i = 0; i < 4; i++) if (deg[i] % 2) numOdd++;
			if (numOdd > 2) fail = true;

			//if (maskV == 15 && maskE == 36 && D) cout << cur << "\n";

			for (int i = 0; i < 4; i++) {
				if (maskV & (1 << i)) cur += sum[i][i];
			}
			//if (maskV == 15 && maskE == 36 && D) cout << cur << "\n";

			if (fail) continue;

			int msk = (1 << st);
			for (int it = 0; it < 10; it++) {
				for (int i = 0; i < 6; i++) {
					int v1 = es[i].first;
					int v2 = es[i].second;
					if ((maskV & (1 << v1)) == 0 || (maskV & (1 << v2)) == 0) continue;
					if (((maskE & (1 << i)) && num[v1][v2] > 0) || num[v1][v2] > 1){
						if (msk & (1 << v1)) msk |= (1 << v2);
						if (msk & (1 << v2)) msk |= (1 << v1);
					}
					//if (maskV == 15 && maskE == 36 && D) cout << msk << " " << v1 + 1 << " " << v2 + 1 << "\n";
				}
			}
			if (msk != maskV) continue;
			ans = max(ans, cur);

			/*if (cur == 425 && D) {
				cout << maskV << " " << maskE << "\n";
			}*/
		}
	}
	cout << ans << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}