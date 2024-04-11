#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
pair<int, vector<string> > solve(int H, int W, vector<string> S) {
	vector<string> top = { "AC", "AG", "AT", "CG", "CT", "GT" };
	vector<string> bottom = { "GT", "CT", "CG", "AT", "AG", "AC" };
	int ans = inf, id = -1;
	for (int i = 0; i < 6; ++i) {
		int sub = 0;
		for (int j = 0; j < H; ++j) {
			string target = (j % 2 == 0 ? top[i] : bottom[i]);
			int cost1 = 0, cost2 = 0;
			for (int k = 0; k < W; ++k) {
				if (S[j][k] != target[k % 2]) ++cost1;
				if (S[j][k] != target[(k + 1) % 2]) ++cost2;
			}
			sub += min(cost1, cost2);
		}
		if (ans > sub) {
			ans = sub;
			id = i;
		}
	}
	vector<string> board(H);
	for (int i = 0; i < H; ++i) {
		string target = (i % 2 == 0 ? top[id] : bottom[id]);
		int cost1 = 0, cost2 = 0;
		for (int j = 0; j < W; ++j) {
			if (S[i][j] != target[j % 2]) ++cost1;
			if (S[i][j] != target[(j + 1) % 2]) ++cost2;
		}
		for (int j = 0; j < W; ++j) {
			board[i] += (cost1 < cost2 ? target[j % 2] : target[(j + 1) % 2]);
		}
	}
	return make_pair(ans, board);
}
int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int i = 0; i < H; ++i) {
		cin >> S[i];
	}
	pair<int, vector<string> > ans1 = solve(H, W, S);
	vector<string> T(W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			T[j] += S[i][j];
		}
	}
	pair<int, vector<string> > ans2 = solve(W, H, T);
	vector<string> ans(H);
	if (ans1.first < ans2.first) {
		ans = ans1.second;
	}
	else {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				ans[i] += ans2.second[j][i];
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}