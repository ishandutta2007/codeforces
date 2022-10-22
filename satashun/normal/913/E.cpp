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

int enc(string s)
{
	int r = 0;
	rep(i, 8) {
		r = r * 2 + (s[i] - '0');
	}
	return r;
}

inline void ch(string &s, string t)
{
	if (s == "") {
		s = t;
	} else {
		s = min(s, t);
	}
}

string dp[3][256][110];
char in[10];

int main() {
	dp[0][enc("00001111")][1] = "x";
	dp[0][enc("00110011")][1] = "y";
	dp[0][enc("01010101")][1] = "z";	

	for (int i = 1; i <= 30; ++i) {
		rep(k, 3) {
			rep(j, 256) {
				if (k == 2) {
					if (dp[1][j][i] != "") {
						ch(dp[2][j][i], dp[1][j][i]);
					} 
					rep(t, 256) if ((t | j) == j) rep(u, 256) if ((t | u) == j) {
						rep(l, i-1) {
							if (dp[1][t][l] != "" && dp[2][u][i-1-l] != "") {
								ch(dp[2][j][i], dp[2][u][i-1-l] + "|" + dp[1][t][l]);
							}
						}
					}
				} else if (k == 1) {
					if (dp[0][j][i] != "") {
						ch(dp[1][j][i], dp[0][j][i]);
					} 					
					rep(t, 256) if ((t & j) == j) rep(u, 256) if ((t & u) == j) {
						rep(l, i-1) {
							if (dp[0][t][l] != "" && dp[1][u][i-1-l] != "") {
								ch(dp[1][j][i], dp[1][u][i-1-l] + "&" + dp[0][t][l]);
							}
						}
					}					
				} else {
					if (dp[0][255-j][i-1] != "") {
						ch(dp[0][j][i], "!" + dp[0][255-j][i-1]);
					}
					if (i >= 2 && dp[2][j][i-2] != "") {
						ch(dp[0][j][i], "(" + dp[2][j][i-2] + ")");
					}
				}
			}
		}
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		scanf("%s", in);
		int t = 0;
		rep(i, 8) {
			t = t * 2 + (in[i] - '0');
		}
		rep(i, 60) if (dp[2][t][i] != "") {
			printf("%s\n", dp[2][t][i].c_str());
			break;
		}
	}

	return 0;
}