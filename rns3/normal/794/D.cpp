#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, m, x[N], y[N], col[N], id[N];
int rmh[N];

vector <int> v[N], c[N];

bool vis[N];

bool cmp(int a, int b) {
	return v[a] < v[b];
}

void insert(vector <int> &tmp, int val){
	for(auto t : tmp){
		if(t == val) return;
	}
	tmp.push_back(val);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x[i], &y[i]);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	for (int i = 1; i <= n; i ++) {
		id[i] = i;
		v[i].push_back(i);
		sort(v[i].begin(), v[i].end());
	}
    sort(id + 1, id + n + 1, cmp);
    int cnt = 0;
    col[id[1]] = ++ cnt;
    for (int i = 2; i <= n; i ++) {
        if (v[id[i]] != v[id[i-1]]) col[id[i]] = ++ cnt;
        else col[id[i]] = col[id[i-1]];
    }
    if (cnt == 1) {
		puts("YES");
		while (n --) printf("1 ");
		return 0;
    }
    for (int i = 1; i <= n; i ++) {
		for (auto u : v[i]) {
            if (col[u] != col[i]) insert(c[col[i]], col[u]);
		}
		if (c[col[i]].size() >= 3) {
			puts("NO");
			return 0;
		}
    }
    int cur = 0;
    for (int i = 1; i <= cnt; i ++) {
		if (c[i].size() == 1) {
			cur = i;
			break;
		}
    }
    if (!cur) {
		puts("NO");
		return 0;
    }
    memset(vis, 0, sizeof vis);

    rmh[cur] = 1;
    vis[cur] = 1;
    int i = c[cur][0], ris = 1;
    while(i) {
		vis[i] = 1;
    	rmh[i] = ++ ris;
    	int tag = 0;
    	for (auto j : c[i]) if (!vis[j]) {
			tag = j;
			break;
    	}
    	i = tag;
    }
    puts("YES");
    for (int i = 1; i <= n; i ++) printf("%d ", rmh[col[i]]);
	return 0;
}