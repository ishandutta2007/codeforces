#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

bool dp[210][210][210];
int n;
string s;
string ans;

int main() {
	cin >> n >> s;
	int na = 0, nb = 0, nc = 0;

	rep(i, n) {
		if (s[i] == 'B') ++na;
		else if (s[i] == 'G') ++nb;
		else ++nc;
	}

	dp[na][nb][nc] = 1;

	for (int s = n; s >= 0; --s) {
		for (int i = s; i >= 0; --i) {
			for (int j = s-i; j >= 0; --j) {
				int k = s - i - j;
				if (dp[i][j][k]) {
					if (i >= 2) {
						dp[i-1][j][k] = 1;
					}
					if (j >= 2) {
						dp[i][j-1][k] = 1;
					}
					if (k >= 2) {
						dp[i][j][k-1] = 1;
					}
					if (i && j) {
						dp[i-1][j-1][k+1] = 1;
					}
					if (j && k) {
						dp[i+1][j-1][k-1] = 1;
					}
					if (i && k) {
						dp[i-1][j+1][k-1] = 1;
					}
				}				
			}
		}		
	}

	if (dp[1][0][0]) {
		ans.pb('B');
	} 
	if (dp[0][1][0]) {
		ans.pb('G');
	} 	
	if (dp[0][0][1]) {
		ans.pb('R');
	} 
	cout << ans << endl;

	return 0;
}