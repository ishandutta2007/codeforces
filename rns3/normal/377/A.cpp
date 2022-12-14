#include <bits/stdc++.h>
using namespace std;

#define N 505

int m, n, k, d[N*N], id[N][N];
char s[N][N];
bool vis[N*N];

typedef pair<int, int> pii;

pii a[N*N], r[4] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
int q[N*N];

void putans() {
	for (int i = 1; i <= n; i ++) puts(s[i] + 1);
}

bool cmp(pii a, pii b) {
	return d[id[a.first][a.second]] > d[id[b.first][b.second]];
}

int main() {
	scanf("%d %d %d\n", &n, &m, &k);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
	int kk = 0, cnt = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (s[i][j] == '.') {
		a[++cnt] = make_pair(i, j);
		id[i][j] = cnt;
	}
	if (cnt == 0) putans();
	int e = 1;
	q[1] = 1;
	d[1] = 1;

	vis[1] = 1;
    for (int f = 1; f <= e; f ++) {
		int i = a[q[f]].first, j = a[q[f]].second;
		for (int h = 0; h < 4; h ++) {
			int ii = i + r[h].first, jj = j + r[h].second;
            if (id[ii][jj] && !vis[id[ii][jj]]) {
				q[++e] = id[ii][jj];
                d[q[e]] = d[q[f]] + 1;
                vis[q[e]] = 1;
            }
		}
    }

    sort (a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= k; i ++) {
        pii now = a[i];
        s[now.first][now.second] = 'X';
    }
    putans();
	return 0;
}