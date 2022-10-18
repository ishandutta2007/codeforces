#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<string> board(H+2);
	rep(i,0,H) {
		cin >> board[i];
		board[i] += "##";
	}
	board[H+0] = string(W+2, '#');
	board[H+1] = string(W+2, '#');
	vector<vi> vert(H+1, vi(W+1, -1000)), hor = vert, tot = vert;
	rep(i,0,H) {
		int c = 0;
		rep(j,0,W+1) {
			vert[i][j] = c;
			c += (board[i][j] == '.' && board[i+1][j] == '.');
		}
	}
	rep(i,0,W) {
		int c = 0;
		rep(j,0,H+1) {
			hor[j][i] = c;
			c += (board[j][i] == '.' && board[j][i+1] == '.');
		}
	}
	rep(i,0,H+1) {
		int c = 0;
		rep(j,0,W+1) {
			assert(c >= 0);
			tot[i][j] = c;
			c += hor[i][j];
		}
	}
	rep(i,0,W+1) {
		int c = 0;
		rep(j,0,H+1) {
			assert(c >= 0);
			tot[j][i] += c;
			c += vert[j][i];
		}
	}
	int Q;
	cin >> Q;
	rep(i,0,Q) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1;
		--c1;
		int t = tot[r2][c2] - tot[r2][c1] - tot[r1][c2] + tot[r1][c1];
		int v = vert[r2-1][c2] - vert[r2-1][c1];
		int h = hor[r2][c2-1] - hor[r1][c2-1];
		cout << t - v - h << endl;
	}
}