#include <bits/stdc++.h>
using namespace std;

const int M = 1000001;

int f[M];
vector<int> v[M];
int p[M];
double g[M];

void DFS(int u) {
	int tot = 0;
	for(int i = 0; i < v[u].size(); i ++) {
		int x = v[u][i];
		tot += f[x];
	}
    for(int i = 0; i < v[u].size(); i ++) {
        int x = v[u][i];
		g[x] = g[u] + 1. * (tot - f[x]) / 2 + 1;
		DFS(x);
    }
}

int main() {
	///freopen("D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &p[i]);
		v[p[i]].push_back(i);
	}
    for(int i = n; i; i --) {
        f[i] ++;
        f[p[i]] += f[i];
    }
    g[1] = 1;
    DFS(1);
    for(int i = 1; i <= n; i ++) printf("%.9lf ", g[i]); puts("");
}