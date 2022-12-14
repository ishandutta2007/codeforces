#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define M 100100


int n, m;
struct edge{
	int i, w;
	bool bf;
} e[M];
bool operator<(edge a, edge b) {
	return a.w < b.w;
}

int x[M], y[M];
int wei[M];

bool solve() {
	int X = 0, Y = 2;
	for (int i = 1; i <= m; i++) if (!e[i].bf) {
		if (++X == Y - 1) {
			++Y;
			X = 1;
		}
		if (Y > n) return 0;
		if (wei[Y] > e[i].w) return 0;
		int j = e[i].i;
		x[j] = X;
		y[j] = Y;
	}
	return 1;
}

int main() {
	//freopen("335_B2.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d %d", &e[i].w, &e[i].bf), e[i].i = i;
	sort(e + 1, e + m + 1);
	for (int k = 1, i = 1; i <= m; i++) if (e[i].bf) {
		int j = e[i].i;
        x[j] = k;
        y[j] = ++k;
        wei[k] = e[i].w;
	}
	if (!solve()) {
		puts("-1");
	} else {
		for (int i = 1; i <= m; i++) printf("%d %d\n", x[i], y[i]);
	}
	return 0;
}