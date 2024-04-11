#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, k;

void println(string message, vector<bool> board) {
	cout<<message<<" ";
	for (int i=0; i<board.size(); i++) cout<<(board[i]?'0':'1');
	cout<<endl;
}

int firstOn(vector<bool> board) {
	for (int i=0; i<n; i++)
		if (board[i]) return i;
	return -99999999;
}
int firstOff(vector<bool> board) {
	for (int i=0; i<n; i++)
		if (!board[i]) return i;
	return -99999999;
}
int lastOn(vector<bool> board) {
	for (int i=n-1; i>=0; i--)
		if (board[i]) return i;
	return -99999999;
}
int lastOff(vector<bool> board) {
	for (int i=n-1; i>=0; i--)
		if (!board[i]) return i;
	return -99999999;
}

bool canWinNow(vector<bool> board) {
	if (lastOn(board)-firstOn(board)+1<=k)
		return true;
	if (lastOff(board)-firstOff(board)+1<=k)
		return true;
	return false;
}

bool canWinAfterMove(vector<bool> board, int moveStart, bool setOn) {
	if (moveStart<0||moveStart+k>n) return true;
	for (int i=0; i<k; i++)
		board[moveStart+i]=setOn;
	//println("after move: ", board);
	return canWinNow(board);
}

bool canForceDraw(vector<bool> board) {
	vector<int> candSpots;
	candSpots.push_back(0);
	candSpots.push_back(n-k);
	candSpots.push_back(firstOn(board)+1);
	candSpots.push_back(firstOff(board)+1);
	candSpots.push_back(lastOn(board)+1);
	candSpots.push_back(lastOff(board)+1);
	for (int &start:candSpots) {
		//println("trying start ", board);
		if (!canWinAfterMove(board, start, true)) {
			return true;
		}
		//println("trying start ", board);
		if (!canWinAfterMove(board, start, false)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>k;
	string line; cin>>line;

	vector<bool> board;
	for (int i=0; i<n; i++)
		board.push_back(line[i]=='0');
	if (canWinNow(board)) {
		cout<<"tokitsukaze\n";
	}
	else if (canForceDraw(board)) {
		cout<<"once again\n";
	}
	else {
		cout<<"quailty\n";
	}
	return 0;
}