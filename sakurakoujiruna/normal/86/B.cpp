#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

const int N = 1e3L + 11, M = N * N;
char c[N][N];
bool v[N][N];

int p[M];
int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b) {
	a = find(a); b = find(b);
	if(a != b) p[a] = b;
}

vector <int> e[M];
int col[M];

int main() {
	//ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	auto f = [&](int i, int j) {
		return (i - 1) * m + j;
	};
	for(int i = 1; i <= n; i ++)
		scanf("%s", c[i] + 1);

	iota(p, p + M, 0);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) if(c[i][j] == '.') {
			if(c[i - 1][j] == '.' && !v[i - 1][j]) {
				v[i - 1][j] = v[i][j] = 1;
				merge(f(i - 1, j), f(i, j));
			} else if(c[i][j - 1] == '.' && !v[i][j - 1]) {
				v[i][j - 1] = v[i][j] = 1;
				merge(f(i, j - 1), f(i, j));
			}
		}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) if(c[i][j] == '.' && !v[i][j]) {
			bool d = 0;
			for(int k = 0; k < 4; k ++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(v[nx][ny]) {
					merge(f(nx, ny), f(i, j));
					d = 1;
					break;
				}
			}
			if(!d) {
				cout << "-1\n";
				return 0;
			}
		}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) if(c[i][j] == '.')
			for(int k = 0; k < 4; k ++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(c[nx][ny] == '.') {
					int a = find(f(i, j)), b = find(f(nx, ny));
					if(a != b) {
						e[a].pb(b);
						e[b].pb(a);
					}
				}
			}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) if(c[i][j] == '.' && find(f(i, j)) == f(i, j)) {
			bool v[10]; fill(v, v + 10, 0);
			for(int x : e[f(i, j)]) if(x < f(i, j))
				v[col[x]] = 1;
			for(int k = 0; k < 10; k ++) if(!v[k]) {
				col[f(i, j)] = k;
				break;
			}
		}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++)
			if(c[i][j] == '.') printf("%d", col[find(f(i, j))]);
			else printf("#");
			puts("");
	}
}