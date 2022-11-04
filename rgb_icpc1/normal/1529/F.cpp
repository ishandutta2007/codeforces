#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

void chkmin(LL &a, LL b) {
	if (b < a) a = b;
}

const int N = 605;
const LL INF = 1000000000000005;
int n, m;

LL w[N][N];
LL W[N], d[N];
int p[N];
int vis[N];
vector<int> con[N];

void init() {
	fill_n(d, n, INF);
	fill_n(p, n, -1);
	fill_n(vis, n, 0);
}

void Dijkstra(int s) {
	int i, j;
	LL tp;
	init();
	d[s] = 0;
	while (1) {
		i = -1;
		for (j = 0; j < n; j++) {
			if (vis[j]) continue;
			if (i == -1 || d[i] > d[j]) i = j;
		}
		if (i == -1) break;
		vis[i]++;
		for (j = 0; j < n; j++) {
			if (vis[j]) continue;
			tp = d[i] + w[i][((j - d[i]) % n + n) % n];
			if (d[j] > tp) {
				d[j] = tp;
				p[j] = i;
			}
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n ; i ++) for (int j = 0; j < n; j ++) w[i][j] = INF;
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		LL c; cin >> a >> b >> c;
		for (int j = 0; j < n; j ++) {
			chkmin(w[a][(b + j) % n], c + j);
		}
	}
	for (int i = 0; i < n; i ++) {
		Dijkstra(i);
		for (int j = 0; j < n; j ++) cout << d[j] << " \n"[j == n - 1];
	}
}