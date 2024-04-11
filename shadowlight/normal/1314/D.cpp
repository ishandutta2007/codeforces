#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 87;
const int INF = 1e9 + 7;

set <pair <int, int> > long_edges[N * N];

int edges[N * N];

int need;

int res = INF;

int find_min(int v, int u, ll mask1, ll mask2) {
	for (auto now : long_edges[v * N + u]) {
		if (now.y < 40 && mask1 & (1LL << now.y)) continue;
		if (now.y >= 40 && mask2 & (1LL << (now.y - 40))) continue;
		return now.x;
	}
	return INF;
} 

int n, k;

char order[10];

void rec(int now, ll mask1, ll mask2) {
	if (now == need) {
		int sum = 0;
		for (int i = 1; i < need; i++) {
			if (sum >= INF) break;
			sum += find_min(order[i - 1], order[i], mask1, mask2);
		}
		if (sum >= INF) return;
		sum += find_min(order[need - 1], order[0], mask1, mask2);
		res = min(res, sum);
		return;
	}
	for (int u = 0; u < n; u++) {
		order[now] = u;
		if (u < 40) {
			rec(now + 1, mask1 | (1LL << u), mask2);
		} else {
			rec(now + 1, mask1, mask2 | (1LL << (u - 40)));
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	need = k / 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> edges[i * N + j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k || j == k || k == 0) continue;
				long_edges[i * N + j].insert({edges[i * N + k] + edges[k * N + j], k});
			}
		}
	}

	ll mask1 = 1, mask2 = 0;
	rec(1, mask1, mask2);

	cout << res << "\n";
}