//2016-06-12 22:47:42.357000
#include <bits/stdc++.h>

using namespace std;

#define NN 1010
#define rep(i, a, b) for (int i = (a); i < (b); i ++)
#define clr(a, b) memset(a, b, sizeof(a))
#define beyond(r, c)((r < 0) | (r >= N) | (c < 0) | (c >= M))
 
queue<int> q;
char board[NN][NN];
int col[NN][NN], cnt[NN * NN];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int N, M;

int BFS() {
	clr(col, 0xff);
	clr(cnt, 0);
	int rid = 0, r, c, rr, cc;
	rep(i, 0, N) rep(j, 0, M) {
		if (board[i][j] != '.') continue ;
		if (col[i][j] != -1) continue ;
		col[i][j] = rid;
		q = queue<int> ();
		q.push(i); q.push(j);
		while (!q.empty()) {
			r = q.front(); q.pop();
			c = q.front(); q.pop();
			rep(d, 0, 4) {
				rr = r + dr[d];
				cc = c + dc[d];
				if (beyond(rr, cc)) continue ;
				if (board[rr][cc] != '.') continue ;
				if (col[rr][cc] == rid) continue ;
				q.push(rr); q.push(cc);
				col[rr][cc] = rid;
			}
		}
		rid ++;
	}
	
	rep(i, 0, N) rep(j, 0, M)
		if (col[i][j] != -1) cnt[col[i][j]] ++;
	return rid;
}

int main() {
	
	int c, ans, a[5], r;
	scanf("%d%d", &N, &M);
	rep(i, 0, N) scanf("%s", board[i]);
	BFS(); 
	rep(i, 0, N) {
		rep(j, 0, M) {
			if (board[i][j] == '.') printf("%c", board[i][j]);
			else {
				int cc = 0;
				rep(d, 0, 4) {
					r = i + dr[d];
					c = j + dc[d];
					if (beyond(r, c)) continue ;
					if (col[r][c] != -1) a[cc ++] = col[r][c];
				}
				ans = 1;
				if (cc) {
					sort(a, a + cc);
					cc = unique(a, a + cc) - a;
					rep(d, 0, cc) ans += cnt[a[d]];
				}
				printf("%d", ans % 10);
			}
			
		}
		puts("");
	}
	return 0;
}