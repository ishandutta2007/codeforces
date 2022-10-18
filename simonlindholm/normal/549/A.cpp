#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
bool face(char a, char b, char c, char d) {
	s = "";
	s += a;
	s += b;
	s += c;
	s += d;
	sort(all(s));
	return s == "acef";
}

int main() {
	cin.sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<string> board(H);
	rep(i,0,H) cin >> board[i];
	int res = 0;
	rep(i,0,H-1) {
		rep(j,0,W-1) {
			if (face(board[i][j], board[i][j+1], board[i+1][j], board[i+1][j+1]))
				++res;
		}
	}
	cout << res << endl;
}