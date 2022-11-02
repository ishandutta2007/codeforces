#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;
const int MAXN = 2 * 1e5 + 10, MAXSZ = 26;
int help[MAXN][MAXSZ];

int n, q;
string s;

void make() {
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXSZ; j++)
			help[i][j] = INF;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < MAXSZ; j++) {
			help[i][j] = help[i + 1][j];
		}
		help[i][s[i] - 'a'] = i;
	}
}

void read() {
	cin >> n >> q;
	cin >> s;
	make();
}

const int MAXLEN = 250 + 10;
int dp[MAXLEN][MAXLEN][MAXLEN];
char have[3][MAXLEN];
int sz[3];

void add(int pos, char x) {
	have[pos - 1][sz[pos - 1]] = x;
	sz[pos - 1]++;
}

void del(int pos) {
	sz[pos - 1]--;
}

void clear() {
	for (int i = 0; i <= sz[0]; i++) {
		for (int j = 0; j <= sz[1]; j++) {
			for (int k = 0; k <= sz[2]; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
}

bool check(int new_pos) {
	new_pos--;

	for (int i = 0; i <= sz[0]; i++) {
		if (new_pos == 0)
				i = sz[0];
		for (int j = 0; j <= sz[1]; j++) {
			if (new_pos == 1)
					j = sz[1];
			for (int k = 0; k <= sz[2]; k++) {
				if (new_pos == 2)
					k = sz[2];

				if (i == 0 && j == 0 && k == 0)
					continue;
				
				dp[i][j][k] = INF;

				int pos_i = INF, pos_j = INF, pos_k = INF;
				if (i > 0 && dp[i - 1][j][k] < INF){
					pos_i = help[dp[i - 1][j][k]][have[0][i - 1] - 'a'] + 1;
				}
				
				if (j > 0 && dp[i][j - 1][k] < INF){
					pos_j = help[dp[i][j - 1][k]][have[1][j - 1] - 'a'] + 1;
				}
				
				if (k > 0 && dp[i][j][k - 1] < INF){
					pos_k = help[dp[i][j][k - 1]][have[2][k - 1] - 'a'] + 1;
				}
	
				dp[i][j][k] = min(dp[i][j][k], pos_i);
				dp[i][j][k] = min(dp[i][j][k], pos_j);
				dp[i][j][k] = min(dp[i][j][k], pos_k);
			}
		}
	}
	return dp[sz[0]][sz[1]][sz[2]] <= n;
}

void run() {
	clear();
	for (int test = 0; test < q; test++) {
		char type;
		cin >> type;
		if (type == '+') {
			int pos;
			char x;
			cin >> pos >> x;
			add(pos, x);
			if (check(pos)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else if (type == '-') {
			int pos;
			cin >> pos;
			del(pos);
			if (dp[sz[0]][sz[1]][sz[2]] <= n) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}	
	}
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}