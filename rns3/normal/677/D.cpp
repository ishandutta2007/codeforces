#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int M = 311;

vector<pii> v[M * M];

int pad[M][M];
int f[M][M];
int n, m, p;
int vis[M][M];
int bit[M][M];

int T;
void add(int tp, int x, int y, int val) {
	if(tp == 0) {
		for(int i = x; i <= n; i += i & -i) {
			for(int j = y; j <= m; j += j & -j) {
				if(vis[i][j] == T) {
					bit[i][j] = min(bit[i][j], val);
				}
				else {
				   vis[i][j] = T;
					bit[i][j] = val;
				}
			}
		}
	}
    if(tp == 1) {
		for(int i = x; i <= n; i += i & -i) {
			for(int j = y; j ; j -= j & -j) {
				if(vis[i][j] == T) {
					bit[i][j] = min(bit[i][j], val);
				}
				else {
				   vis[i][j] = T;
					bit[i][j] = val;
				}
			}
		}
    }
    if(tp == 2) {
		for(int i = x; i; i -= i & -i) {
			for(int j = y; j <= m; j += j & -j) {
				if(vis[i][j] == T) {
					bit[i][j] = min(bit[i][j], val);
				}
				else {
				   vis[i][j] = T;
					bit[i][j] = val;
				}
			}
		}
    }
    if(tp == 3) {
		for(int i = x; i ; i -= i & -i) {
			for(int j = y; j; j -= j & -j) {
				if(vis[i][j] == T) {
					bit[i][j] = min(bit[i][j], val);
				}
				else {
				   vis[i][j] = T;
					bit[i][j] = val;
				}
			}
		}
    }
}

int calc(int tp, int x, int y) {
    int res = 1e9;
    if(tp == 0) {
		for(int i = x; i; i -= i & -i) {
			for(int j = y; j; j -= j & -j) {
				if(vis[i][j] != T) continue;
				res = min(res, bit[i][j]);
			}
		}
		return res;
    }
    if(tp == 1) {
		for(int i = x; i ; i -= i & -i) {
			for(int j = y; j <= m; j += j & -j) {
				if(vis[i][j] != T) continue;
				res = min(res, bit[i][j]);
			}
		}
		return res;
    }
    if(tp == 2) {
		for(int i = x; i <= n; i += i & -i) {
			for(int j = y; j; j -= j & -j) {
				if(vis[i][j] != T) continue;
				res = min(res, bit[i][j]);
			}
		}
		return res;
    }
    if(tp == 3) {
        for(int i = x; i <= n; i += i & -i) {
			for(int j = y; j <= m; j += j & -j) {
				if(vis[i][j] != T) continue;
				res = min(res, bit[i][j]);
			}
		}
		return res;
    }
}

void update(vector<pii> v, vector<pii> w) {
    int sz1 = v.size(), sz2 = w.size();
    for(int step = 0; step < 4; step ++) {
		++T;
		for(int i = 0; i < sz1; i ++) {
			int x = v[i].first, y = v[i].second;
			if(!step) add(step, x, y, f[x][y] - x - y);
			else if (step == 1) add(step, x, y, f[x][y] + y - x);
			else if(step == 2) add(step, x, y, f[x][y] + x - y);
			else if(step == 3) add(step, x, y, f[x][y] + x + y);
		}
		for(int i = 0; i < sz2; i ++) {
			int x = w[i].first, y = w[i].second;
			int z = calc(step, x, y);
			if(!step) f[x][y] = min(f[x][y], x + y + z);
			else if(step == 1) f[x][y] = min(f[x][y], x - y + z);
			else if(step == 2) f[x][y] = min(f[x][y], y - x + z);
			else f[x][y] = min(f[x][y], z - x - y);
		}
    }
}

int main() {
	///freopen("3.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
		int x;
		scanf("%d", &x);
		pad[i][j] = x;
		v[x].push_back(make_pair(i, j));
    }
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) f[i][j] = 1e9;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(pad[i][j] == 1) {
		f[i][j] = i - 1 + j - 1;
    }
    for(int i = 1; i < p; i ++) {
        update(v[i], v[i+1]);
    }
    printf("%d\n", f[v[p][0].first][v[p][0].second]);
}