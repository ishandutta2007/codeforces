#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2002;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

bool u[N][N];
bool isDed[N];
int deg[N];
int col[N];

int n;

void go() {
	int v = -1;
	for (int i = 0; i < n; i++) {
		if (!isDed[i] && deg[i] % 2 == 1 && v == -1) {
			v = i;
		}
	}

	//cout << v + 1 << " v\n";

	if (v == -1) {
		for (int i = 0; i < n; i++) {
			if (!isDed[i]) {
				col[i] = 0;
			}
		}
		return;
	}

	vector<int> w;
	for (int i = 0; i < n; i++) {
		if (u[v][i] && !isDed[i]) {
			w.push_back(i);
		}
	}

	for (int i = 0; i < (int)w.size(); i++) {
		int v2 = w[i];

		u[v2][v] = false;
		deg[v2]--;

		for (int j = 0; j < i; j++) {
			int v1 = w[j];

			if (u[v1][v2]) {
				u[v1][v2] = u[v2][v1] = false;
				deg[v1]--;
				deg[v2]--;
			} else {
				u[v1][v2] = u[v2][v1] = true;
				deg[v1]++;
				deg[v2]++;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		cout << deg[i] << " ";
	}
	cout << " deg\n";*/

	isDed[v] = true;
	go();
	isDed[v] = false;

	int num0 = 0, num1 = 0;
	for (int i = 0; i < n; i++) {
		if (!u[v][i] || isDed[i]) continue;
		if (col[i] == 0) num0++;
		else num1++;
 	}

 	assert((num0 + num1) % 2 == 1);

 	if (num0 % 2 == 0) col[v] = 0;
 	if (num1 % 2 == 0) col[v] = 1;
}

void solve() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			u[i][j] = false;
		}
		isDed[i] = false;
		deg[i] = 0;
		col[i] = -1;
	}	

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		u[v1][v2] = u[v2][v1] = true;
		deg[v1]++;
		deg[v2]++;
	}

	go();

	bool is2 = false;
	for (int i = 0; i < n; i++) {
		if (col[i] == 1) is2 = true;
	}

	cout << (is2 ? "2\n" : "1\n");
	for (int i = 0; i < n; i++) {
		cout << col[i] + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	cin >> tst;
#ifdef MADE_BY_SERT
	D = true;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}