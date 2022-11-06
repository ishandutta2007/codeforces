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
const int N = 305;

int n, col[N][N], tot[3];
char mp[N][N]; 

int main() {
	rep(i, 1, N-5) rep(j, 1, N-5) col[i][j] = (i + j) % 3;
	mulT0 {
		fil(tot, 0);
		scanf("%d", &n);
		rep(i, 1, n) scanf("%s", mp[i]+1);
		rep(i, 1, n) rep(j, 1, n) tot[col[i][j]] += mp[i][j] == 'X';
		int x = min_element(tot, tot+3) - tot;
		rep(i, 1, n) rep(j, 1, n) if(mp[i][j] == 'X' && col[i][j] == x) mp[i][j] = 'O';
		rep(i, 1, n) printf("%s\n", mp[i]+1);
	}
	return 0;
}