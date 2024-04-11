#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char board[105][105];
char ans[105][105];
string chi = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int r, c, k;

void nxt(int &cr, int &cc) {
	if(cr % 2 == 0) {
		if(cc == c - 1) {
			cr++;
			return;
		}
		cc++;
		return;
	}
	if(cc == 0) {
		cr++;
		return;
	}
	cc--;
}

void solve() {
	cin >> r >> c >> k;
	int rc = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++) {
			cin >> board[i][j];
			rc += (board[i][j] == 'R');
		}

	vector<int> amt(k), cnt(k);
	for(int i = 0; i < k; i++)
		amt[i] = rc / k;
	rc -= k * (rc / k);
	for(int i = 0; i < rc; i++)
		amt[i]++;
	int cr = 0, cc = 0, p = 0;
	while(cr < r) {
		ans[cr][cc] = chi[p];
		if(board[cr][cc] == 'R')
			cnt[p]++;
		if(cnt[p] == amt[p] && p < k - 1)
			p++;
		nxt(cr, cc);
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			cout << ans[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}