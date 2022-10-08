#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin>>T;
	while (T--) {
		int h, w; cin>>h>>w;
		vector<vector<bool> > board;
		for (int x=0; x<w; x++) {
			board.push_back(vector<bool>());
			board[x].resize(h);
		}
		for (int y=0; y<h; y++) {
			string line; cin>>line;
			for (int x=0; x<w; x++)
				board[x][y]=line[x]=='*';
		}
		vector<int> missingFromX, missingFromY;
		for (int y=0; y<h; y++) {
			int missing=w;
			for (int x=0; x<w; x++) 
				if (board[x][y])
					missing--;
			missingFromY.push_back(missing);
		}
		for (int x=0; x<w; x++) {
			int missing=h;
			for (int y=0; y<h; y++)
				if (board[x][y])
					missing--;
			missingFromX.push_back(missing);
		}
		int bestAns=w*h;
		for (int x=0; x<w; x++)
			for (int y=0; y<h; y++) {
				int takes=missingFromX[x]+missingFromY[y]-(board[x][y]?0:1);
				bestAns=min(bestAns, takes);
			}
		cout<<bestAns<<'\n';
	}

	return 0;
}