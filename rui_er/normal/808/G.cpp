// LUOGU_RID: 96376906
// Problem: CF808G Anthem of Berland
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF808G
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m;
char s[N], t[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct KMPAM {
	int pi[N], nxt[N][26];
	void build(char* s, int n) {
		rep(i, 2, n) {
			int j = pi[i-1];
			while(j && s[j+1] != s[i]) j = pi[j];
			if(s[j+1] == s[i]) ++j;
			pi[i] = j;
		}
		rep(i, 1, n) {
			rep(j, 0, 25) {
				char c = j + 'a';
				if(i > 1 && s[i] != c) nxt[i][j] = nxt[pi[i-1]+1][j];
				else nxt[i][j] = (s[i] == c) + i;
			}
		}
	}
}kmp;

int main() {
	scanf("%s%s", s+1, t+1);
	n = strlen(s+1); m = strlen(t+1);
	t[++m] = '$';
	kmp.build(t, m);
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0xc0c0c0c0));
	dp[0][1] = 0;
	rep(i, 1, n) {
		rep(j, 1, m) {
			if(s[i] == '?') {
				rep(k, 0, 25) {
					chkmax(dp[i][kmp.nxt[j][k]], dp[i-1][j] + (kmp.nxt[j][k] == m));
				}
			}
			else {
				int k = s[i] - 'a';
				chkmax(dp[i][kmp.nxt[j][k]], dp[i-1][j] + (kmp.nxt[j][k] == m));
			}
			// printf("%d%c", dp[i][j], " \n"[j==m]);
		}
	}
	printf("%d\n", *max_element(dp[n].begin(), dp[n].end()));
	return 0;
}