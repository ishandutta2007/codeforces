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
	int N;
	cin >> N;
	vector<string> board(N);
	rep(i,0,N)
		cin >> board[i];
	vi avoid(N);
	vi counts(N);
	vi q;
	rep(i,0,N) {
		cin >> avoid[i];
		if (avoid[i] == 0) q.push_back(i);
	}
	vi add;
	while (!q.empty()) {
		int i = q.back();
		q.pop_back();
		if (counts[i] != avoid[i]) continue; // already solved
		add.push_back(i);
		rep(j,0,N) if (board[i][j] == '1') {
			++counts[j];
			if (counts[j] == avoid[j]) q.push_back(j);
		}
	}
	cout << sz(add) << endl;
	trav(x, add) cout << x+1 << ' ';
	cout << endl;
}