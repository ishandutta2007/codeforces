//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n, s[N][2], t[N][2]; char c[N];

int main() {
	mulT0 {
		scanf("%d%s", &n, c+1);
		rep(i, 1, n) {
			int id = c[i] == 'L';
			s[i][id^1] = 0;
			s[i][id] = s[i-1][id^1] + 1;
		}
		per(i, n, 1) {
			int id = c[i] == 'L';
			t[i][id^1] = 0;
			t[i][id] = t[i+1][id^1] + 1;
		}
//		rep(i, 1, n) printf("%d %d %d %d\n", s[i][0], s[i][1], t[i][0], t[i][1]);
		rep(i, 0, n) printf("%d%c", s[i][1]+t[i+1][0]+1, " \n"[i==n]);
		rep(i, 0, n+1) s[i][0] = s[i][1] = t[i][0] = t[i][1] = 0;
	}
	return 0;
}