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
const int N = 405;

int n, pos[2][2], tot;
char s[N][N];

int main() {
	mulT0 {
		tot = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%s", s[i]+1);
			rep(j, 1, n) {
				if(s[i][j] == '*') {
					pos[tot][0] = i;
					pos[tot][1] = j;
					++tot;
				}
			}
		}
		if(pos[0][0] == pos[1][0]) {
			if(pos[0][0] == n) s[1][pos[0][1]] = s[1][pos[1][1]] = '*';
			else s[n][pos[0][1]] = s[n][pos[1][1]] = '*';
		}
		else if(pos[0][1] == pos[1][1]) {
			if(pos[0][1] == n) s[pos[0][0]][1] = s[pos[1][0]][1] = '*';
			else s[pos[0][0]][n] = s[pos[1][0]][n] = '*';
		}
		else s[pos[0][0]][pos[1][1]] = s[pos[1][0]][pos[0][1]] = '*';
		rep(i, 1, n) printf("%s\n", s[i]+1);
	}
	return 0;
}