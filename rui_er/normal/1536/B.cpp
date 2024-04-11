//LG@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const int N = 1e3+5, K = 35;

int T, n, a[K][K][K];
char s[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		memset(a, 0, sizeof(a));
		scanf("%d%s", &n, s+1);
		rep(delta, 0, min(2, n-1)) {
			rep(L, 1, n) {
				int R = L + delta;
				if(R > n) break;
				if(!delta) ++a[s[L]-'a'+1][0][0];
				else if(delta == 1) ++a[s[L]-'a'+1][s[R]-'a'+1][0];
				else ++a[s[L]-'a'+1][s[L+1]-'a'+1][s[R]-'a'+1];
			}
			int ans = 0;
			if(!delta) {
				rep(i, 1, 26) {
					if(!a[i][0][0]) {
						printf("%c\n", i+'a'-1);
						ans = 1;
						break;
					}
				}
			}
			else if(delta == 1) {
				rep(i, 1, 26) {
					rep(j, 1, 26) {
						if(!a[i][j][0]) {
							printf("%c%c\n", i+'a'-1, j+'a'-1);
							ans = 1;
							break;
						}
					}
					if(ans) break;
				}
			}
			else {
				rep(i, 1, 26) {
					rep(j, 1, 26) {
						rep(k, 1, 26) {
							if(!a[i][j][k]) {
								printf("%c%c%c\n", i+'a'-1, j+'a'-1, k+'a'-1);
								ans = 1;
								break;
							}
						}
						if(ans) break;
					}
					if(ans) break;
				}
			}
			if(ans) break;
		}
	}
	return 0;
}