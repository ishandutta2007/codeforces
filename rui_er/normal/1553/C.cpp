//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 15;

int T;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s", s+1);
		int now1 = 0, now2 = 0, ans = 10;
		rep(i, 1, 10) {
			if(s[i] == '1' || ((i & 1) && s[i] == '?')) {
				if(i & 1) ++now1;
				else ++now2;
			}
//			printf("%d %d\n", now1, now2);
			if(now1 > now2 + 5 - i / 2) {
				chkmin(ans, i);
				break;
			}
		}
		now1 = now2 = 0;
		rep(i, 1, 10) {
			if(s[i] == '1' || (!(i & 1) && s[i] == '?')) {
				if(i & 1) ++now1;
				else ++now2;
			}
//			printf("%d %d\n", now1, now2);
			if(now2 > now1 + 5 - (i + 1) / 2) {
				chkmin(ans, i);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}