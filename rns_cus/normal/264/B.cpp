#include <bits/stdc++.h>

using namespace std;

#define N 100100

int flag[N], p[N], cnt, n, inv[N], pr[N];
int f[N];

vector <int> v[N];

void init() {
	for(int i = 2; i < N; i ++) if(!flag[i]) {
		inv[i] = cnt;
		p[cnt ++] = i;
		for(int j = i + i; j < N; j += i) flag[j] = 1;
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	init();
	scanf("%d", &n);
	for(int x, i = 1; i <= n; i ++) {
		scanf("%d", &x);
		for(int j = 0; j < cnt; j ++) {
			if(p[j] * p[j] > x) break;
			if(x % p[j] == 0) {
				while(x % p[j] == 0) x /= p[j];
				v[i].push_back(j);
			}
		}
		if(x > 1) v[i].push_back(inv[x]);
	}
	int mx = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < (int)v[i].size(); j ++) {
			f[i] = max(f[pr[v[i][j]]] + 1, f[i]);
		}
		mx = max(mx, f[i]);
		for(int j = 0; j < (int)v[i].size(); j ++) pr[v[i][j]] = i;
	}
	if(mx == 0) mx ++;
	cout << mx << endl;
	return 0;
}