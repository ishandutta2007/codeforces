#include <bits/stdc++.h>

using namespace std;

#define N 500500
#define L 40
#define ep 1e-8

int q, n, pa[N], d[N];
double f[N][L], tmp[L], ttmp[L];

void update(int x) {
	f[x][0] = 1.;
	int y = pa[x], k = d[y];
	tmp[0] = 1.;
	for(int i = 1; i < L; i ++) {
		tmp[i] = 2. - f[y][i];
		f[y][i] = 1. - (1. - f[y][i]) * (1. - f[x][i-1] * 0.5);
		tmp[i] = (2. - f[y][i]) / tmp[i];
	}
	x = y;
	for(int j = 1; j < L && pa[x]; j ++) {
		y = pa[x];
		k = d[y];
		for(int i = 1; i < L; i ++) {
			ttmp[i] = 2. - f[y][i];
			f[y][i] = 1. - (1. - f[y][i]) * tmp[i - 1];
			ttmp[i] = (2. - f[y][i]) / ttmp[i];
		}
		for(int i = 1; i < L; i ++) tmp[i] = ttmp[i];
		x = y;
	}
}

void query(int type, int v) {
	if(type == 1) {
		++ n;
		pa[n] = v; d[v] ++;
		update(n);
	} else {
		double ans = 0.;
		for(int i = 1; i < L; i ++) ans += f[v][i];
		printf("%.10lf\n", ans);
	}
}

void input(int &x) {
	x = 0;
	char c = getchar();
	while(c <= 32) c = getchar();
	while(c > 32) x = x * 10 + (c ^ 48), c = getchar();
}

int main() {
	//freopen("in.txt", "r", stdin);
	n = 1;
	input(q);
	while(q --) {
		int type, v;
		input(type); input(v);
		query(type, v);
	}
	return 0;
}