#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, p[N], vis[N], ban[N];
vector<int> v[N];
void gen(int x){
	int pos = x;
	while (vis[x] == 0) {
		vis[x] = 1;
		v[pos].push_back(x);
		x = p[x];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i] == 0) gen(i);
	}
	bool ok = 0; int id = -1;
	for (int i = 1; i <= n; i ++)
		if (v[i].size() == 1 || v[i].size() == 2) {
			ok = 1; id = i; 
			if (v[i].size() == 1) break;
		}

	if (!ok) return !printf("NO\n");
	for (int i = 1; i <= n; i ++) {
		if (v[i].size() % v[id].size()) return !printf("NO\n");
	}
	printf("YES\n");
	for (int i = 1; i <= n; i ++) {
		if (i != id && v[i].size()) {
			int sz = v[id].size();
			for (int j = 0; j < v[i].size(); j ++) {
				printf("%d %d\n", v[i][j], v[id][j%sz]);
			}
		}
	}
	if (v[id].size() == 2) printf("%d %d\n", v[id][0],v[id][1]);
}