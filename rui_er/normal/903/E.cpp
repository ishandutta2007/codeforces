// Problem: F. Swapping Characters
// Contest: Codeforces - Training Round #1 (1400-1700-1900-2000-2100-2200, 120min)
// URL: https://codeforces.com/group/iw2l909Oqc/contest/396416/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int N = 5e3+5, K = 2.5e3+5;

int k, n, buc1[26], buc2[26], diff[K];
char s[K][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &k, &n);
	rep(i, 1, k) scanf("%s", s[i]+1);
	int same = 0;
	rep(i, 1, n) {
		++buc1[s[1][i]-'a'];
		same |= buc1[s[1][i]-'a'] > 1;
	}
	rep(i, 2, k) {
		rep(j, 0, 25) buc2[j] = 0;
		rep(j, 1, n) ++buc2[s[i][j]-'a'];
		int ok = 1;
		rep(j, 0, 25) ok &= buc1[j] == buc2[j];
		if(!ok) return puts("-1")&0;
	}
	rep(i, 2, k) rep(j, 1, n) diff[i] += s[1][j] != s[i][j];
	rep(i, 1, n) {
		rep(j, i+1, n) {
			int ok = 1;
			rep(t, 2, k) {
				int d = diff[t] - (s[1][i] != s[t][i]) - (s[1][j] != s[t][j]) + (s[1][i] != s[t][j]) + (s[1][j] != s[t][i]);
				if(d && d != 2 || !d && !same) {ok = 0; break;}
			}
			if(ok) {
				rep(t, 1, n) {
					if(t == i) putchar(s[1][j]);
					else if(t == j) putchar(s[1][i]);
					else putchar(s[1][t]);
				}
				puts("");
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}