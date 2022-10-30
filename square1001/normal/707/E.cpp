#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
char tp[12];
int main() {
	int R, C, K;
	scanf("%d %d %d", &R, &C, &K);
	vector<vector<pair<int, int> > > board(R, vector<pair<int, int> >(C, make_pair(-1, -1)));
	vector<vector<pair<int, int> > > garland(K);
	vector<vector<long long> > gsum(K);
	for (int i = 0; i < K; ++i) {
		int len;
		scanf("%d", &len);
		garland[i].resize(len);
		gsum[i].resize(len + 1);
		for (int j = 0; j < len; ++j) {
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c); --x, --y;
			garland[i][j] = make_pair(x, y);
			gsum[i][j + 1] = gsum[i][j] + c;
			board[x][y] = make_pair(i, j);
		}
	}
	int Q;
	scanf("%d", &Q);
	vector<int> press(K, 1);
	while (Q--) {
		scanf("%s", tp);
		if (tp[0] == 'S') {
			int pos;
			scanf("%d", &pos); --pos;
			press[pos] ^= 1;
		}
		else {
			int xa, ya, xb, yb;
			scanf("%d %d %d %d", &xa, &ya, &xb, &yb); --xa, --ya, --xb, --yb;
			vector<vector<int> > changes(K, { 0 });
			for (int i = xa; i <= xb; ++i) {
				if (ya >= 1 && board[i][ya].first == board[i][ya - 1].first && board[i][ya].first != -1 && abs(board[i][ya].second - board[i][ya - 1].second) == 1) {
					changes[board[i][ya].first].push_back(max(board[i][ya].second, board[i][ya - 1].second));
				}
				if (yb <= C - 2 && board[i][yb].first == board[i][yb + 1].first && board[i][yb].first != -1 && abs(board[i][yb].second - board[i][yb + 1].second) == 1) {
					changes[board[i][yb].first].push_back(max(board[i][yb].second, board[i][yb + 1].second));
				}
			}
			for (int i = ya; i <= yb; ++i) {
				if (xa >= 1 && board[xa][i].first == board[xa - 1][i].first && board[xa][i].first != -1 && abs(board[xa][i].second - board[xa - 1][i].second) == 1) {
					changes[board[xa][i].first].push_back(max(board[xa][i].second, board[xa - 1][i].second));
				}
				if (xb <= R - 2 && board[xb][i].first == board[xb + 1][i].first && board[xb][i].first != -1 && abs(board[xb][i].second - board[xb + 1][i].second) == 1) {
					changes[board[xb][i].first].push_back(max(board[xb][i].second, board[xb + 1][i].second));
				}
			}
			long long ans = 0;
			for (int i = 0; i < K; ++i) {
				if (!press[i]) continue;
				changes[i].push_back(garland[i].size());
				sort(changes[i].begin(), changes[i].end());
				int fx = garland[i][0].first, fy = garland[i][0].second;
				int parity = (xa <= fx && fx <= xb && ya <= fy && fy <= yb ? 1 : 0);
				for (int j = 1; j < changes[i].size(); ++j) {
					if (j % 2 == parity) {
						ans += gsum[i][changes[i][j]] - gsum[i][changes[i][j - 1]];
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}