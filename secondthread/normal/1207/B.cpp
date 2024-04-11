
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int h, w; cin>>h>>w;
	vector<vector<bool>> board(h, vector<bool>(w));
	vector<vector<bool>> target(h, vector<bool>(w));
	for (int y=0; y<h; y++)
		for (int x=0; x<w; x++) {
			int i; cin>>i;
			board[y][x]=(i==1);
		}
	vector<pair<int, int>> ans;
	for (int x=0; x+1<w; x++) 
		for (int y=0; y+1<h; y++) {
			if (board[y][x]&&board[y+1][x]&&board[y][x+1]&&board[y+1][x+1]) {
				ans.push_back({y, x});
				target[y][x]=target[y+1][x]=target[y][x+1]=target[y+1][x+1]=true;
			}
		}
	bool works=true;
	for (int x=0; x<w; x++)
		for (int y=0; y<h; y++)
			if (target[y][x]!=board[y][x]) works=false;
	if (works) {
		cout<<ans.size()<<'\n';
		for (auto ii:ans)
			cout<<ii.first+1<<" "<<ii.second+1<<'\n';
	}
	else {
		cout<<-1<<'\n';
	}
	return 0;
}