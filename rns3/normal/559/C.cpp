#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

#define N 2000010

int jego(int a, int b) {
	if (!b) return 1;
	int rlt = jego(a, b / 2);
	rlt = 1ll * rlt * rlt % P;
	if (b % 2) rlt = 1ll * rlt * a % P;
	return rlt;
}

int u[N], v[N];

void prep() {
	u[0] = 1;
	v[0] = 1;
	for (int i = 1; i < N; i ++) {
		u[i] = 1ll * u[i-1] * i % P;
		v[i] = jego(u[i], P - 2);
	}
}

int func(int a, int b, int aa, int bb) {
	if (aa < a || bb < b) return 0;
	int rlt = 1ll * (1ll * u[aa+bb-a-b] * v[aa-a] % P) * v[bb-b] % P;
	return rlt;
}

int x, y, n, now[2020];

pair <int, int> black[2020];

int main() {
	prep();
	scanf("%d %d %d", &x, &y, &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &black[i].first, &black[i].second);
    sort (black + 1, black + n + 1);
    black[n+1] = make_pair(x, y);
    for (int i = 1; i <= n + 1; i ++) {
		now[i] = func(1, 1, black[i].first, black[i].second);
    }
    for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n + 1; j ++) {
			now[j] = (now[j] + P - (1ll * now[i] * func(black[i].first, black[i].second, black[j].first, black[j].second) % P)) % P;
		}
    }
    printf("%d\n", now[n+1]);
	return 0;
}