#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, vector<string>> solve2(const vector<string>& board, const string& order) {
	int N = sz(board), M = sz(board[0]);
	vector<string> res(N, string(M, 'x'));
	res[0][0] = order[0];
	res[1][0] = order[1];
	res[0][1] = order[2];
	res[1][1] = order[3];
	int out = 0;
	rep(i,0,2) rep(j,0,2) out += (res[i][j] == board[i][j]);
	rep(i,0,2) rep(j,2,M) {
		res[i][j] = res[i][j & 1];
		out += (res[i][j] == board[i][j]);
	}
	string line1(M, 'x'), line2(M, 'x');
	rep(i,2,N) {
		int out1 = 0, out2 = 0;
		line2[1] = line1[0] = res[i-2][0];
		line2[0] = line1[1] = res[i-2][1];
		rep(j,2,M) {
			line1[j] = (char)('A' + 'T' + 'G' + 'C' - (res[i-1][j] + res[i-1][j-1] + line1[j-1]));
			line2[j] = (char)('A' + 'T' + 'G' + 'C' - (res[i-1][j] + res[i-1][j-1] + line2[j-1]));
		}
		rep(j,0,M) out1 += (line1[j] == board[i][j]);
		rep(j,0,M) out2 += (line2[j] == board[i][j]);
		if (out1 > out2) res[i] = line1, out += out1;
		else res[i] = line2, out += out2;
	}

	return {out, res};
}

pair<int, vector<string>> solve(const vector<string>& board, const vector<string>& board2, const string& order) {
	auto pa1 = solve2(board, order);
	auto pa2 = solve2(board2, order);
	if (pa1.first >= pa2.first) return pa1;
	int N = sz(board), M = sz(board2);
	vector<string> res2(N, string(M, 'x'));
	rep(i,0,N) rep(j,0,M) res2[i][j] = pa2.second[j][i];
	pa2.second = res2;
	return pa2;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<string> board(N);
	rep(i,0,N) {
		cin >> board[i];
	}

	vector<string> board2(M, string(N, 'x'));
	rep(i,0,N) rep(j,0,M) board2[j][i] = board[i][j];

	pair<int, vector<string>> res{-1, {}};
	string order = "ACGT";
	do {
		auto blah = solve(board, board2, order);
		// rep(i,0,N)
			// cout << blah.second[i] << endl;
		// cerr << blah.first << endl;
		res = max(res, blah);
	} while (next_permutation(all(order)));
	// cerr << res.first << endl;
	rep(i,0,N)
		cout << res.second[i] << endl;
	exit(0);
}