#include <bits/stdc++.h>
using namespace std;
#define N 1001001

int n, p[N], T, vis[N], id[N];
vector <int> v[N];

bool cmp(int i, int j) {
	return v[i].size() < v[j].size();
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		T ++;
		for (int j = i; !vis[j]; j = p[j]) vis[j] = 1, v[T].push_back(j);
	}
	for (int i = 1; i <= T; i ++) id[i] = i;
	sort(id + 1, id + T + 1, cmp);
	for (int i = 1; i <= T; i ++) {
		int sz = v[id[i]].size();
		if (sz & 1) {
			for(int j = 0; j < sz; j++) p[v[id[i]][j]] = v[id[i]][(j+sz/2+1)%sz];
		}
		else {
			if (i < T && v[id[i+1]].size() == v[id[i]].size()){
				for(int j = 0; j < sz; j++){
                    p[v[id[i]][j]] = v[id[i+1]][j];
					p[v[id[i+1]][j]] = v[id[i]][(j + 1) % sz];
				}
				i ++;
			}
			else {
				puts("-1"); return 0;
			}
		}
	}
	for (int i = 1; i <= n; i ++) printf("%d ", p[i]); puts("");
	return 0;
}