/*
                     _ooOoo_
                    o8888888o
                    88" . "88
                    (| -_- |)
                    O\  =  /O
                 ____/`---'\____
               .'  \\|     |//  `.
              /  \\|||  :  |||//  \
             /  _||||| -:- |||||-  \
             |   | \\\  -  /// |   |
             | \_|  ''\---/''  |   |
             \  .-\__  `-`  ___/-. /
           ___`. .'  /--.--\  `. . __
        ."" '<  `.___\_<|>_/___.'  >'"".
       | | :  `- \`.;`\ _ /`;.`/ - ` : | |
       \  \ `-.   \_ __\ /__ _/   .-` /  /
  ======`-.____`-.___\_____/___.-`____.-'======
                     `=---='
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    BUG
*/
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

int n, u, r, d, l;

int main() {
	mulT0 {
		scanf("%d%d%d%d%d", &n, &u, &r, &d, &l);
		int ans = 1;
		if(u == n && (!l || !r)) ans = 0;
		if(r == n && (!u || !d)) ans = 0;
		if(d == n && (!l || !r)) ans = 0;
		if(l == n && (!u || !d)) ans = 0;
		if(u == n && d == n && (l <= 1 || r <= 1)) ans = 0;
		if(l == n && r == n && (u <= 1 || d <= 1)) ans = 0;
		if((u == n && d == n - 1 || u == n - 1 && d == n) && !(l >= 1 && r >= 2 || l >= 2 && r >= 1)) ans = 0;
		if((l == n && r == n - 1 || l == n - 1 && r == n) && !(u >= 1 && d >= 2 || u >= 2 && d >= 1)) ans = 0;
		if(u == n - 1 && !l && !r) ans = 0;
		if(r == n - 1 && !u && !d) ans = 0;
		if(d == n - 1 && !l && !r) ans = 0;
		if(l == n - 1 && !u && !d) ans = 0;
		if(u == n - 1 && d == n - 1 && (l + r <= 1)) ans = 0;
		if(l == n - 1 && r == n - 1 && (u + d <= 1)) ans = 0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}