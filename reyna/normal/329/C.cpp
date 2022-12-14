//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int Que[N],bg,ed;
int mark[N];
int mat[49][49];
int deg[49];
vector<int> al[N];
void bfs(int v) {
	Que[ed++] = v;
	mark[v] = 1;
	while(ed != bg) {
		int u = Que[bg++];
		for(auto w : al[u]) {
			if(!mark[w]) {
				Que[ed++] = w;
				mark[w] = 1;
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,m; cin >> n >> m;
//	if((n * (n - 1)) / 2 < 2 * m) {
//		cout << -1 << endl;
//		return 0;
//	}
	for(int i = 0; i < m; ++i) {
		int u,v; cin >> u >> v; --u,--v;
		al[u].push_back(v);
		al[v].push_back(u);
		if(u < 10 && v < 10) mat[u][v]++,mat[v][u]++;
	}
	if(n <= 6) {
		int k = (n * (n - 1)) / 2;
		for(int i = 0; i < 1 << k; ++i) {
			if(__builtin_popcount(i) == m) {
				memset(deg,0,sizeof deg);
				int x = 0,y = 0;
				for(int r = 1; r < n; ++r) {
					for(int l = 0; l < r; ++l) {
						if(i >> x & 1) {
							if(!mat[r][l]) y++;
							deg[r]++,deg[l]++;
						}
						x++;
					}
				}
				for(int j = 0; j < n; ++j) if(deg[j] > 2) y = -1;
				if(y == m) {
					int x = 0;
					for(int r = 1; r < n; ++r) {
						for(int l = 0; l < r; ++l) {
							if(i >> x & 1) {
								cout << l + 1 << ' ' << r + 1 << '\n';
							}
							x++;
						}
					}
					return 0;
				}
			}
		}
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		if(!mark[i]) {
			bfs(i);
		}
	}
	for(int i = 0; i < m; ++i) {
		cout << (Que[i % n] + 1) << ' ' << (Que[(i + 3) % n] + 1) << '\n';
	}
	return 0;
}