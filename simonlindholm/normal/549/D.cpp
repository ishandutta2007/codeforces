#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<vi> board(H, vi(W));
	rep(i,0,H) {
		string s;
		cin >> s;
		rep(j,0,W)
			board[i][j] = s[j] == 'B' ? 1 : -1;
	}

	int res = 0;
	for (int i = H; i --> 0; ) {
		for (int j = W; j --> 0; ) {
			if (board[i][j]) {
				++res;
				int v = board[i][j];
				rep(a,0,i+1) rep(b,0,j+1) board[a][b] -= v;
			}
		}
	}
	cout << res << endl;
}