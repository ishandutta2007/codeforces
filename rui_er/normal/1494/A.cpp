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
const int N = 55;

char c[N];

int main() {
	mulT0 {
		scanf("%s", c);
		int n = strlen(c);
		if(c[0] == c[n-1]) puts("NO");
		else {
			char le = c[0], ri = c[n-1];
			rep(i, 0, n-1) {
				if(c[i] == le) c[i] = '(';
				else if(c[i] == ri) c[i] = ')';
			}
			int now = 0, _ = 1;
			rep(i, 0, n-1) {
				if(c[i] == '(') ++now;
				else if(c[i] == ')') {
					--now;
					if(now < 0) {_ = 0; break;}
				}
				else ++now;
			}
			if(_ && !now) puts("YES");
			else {
				now = 0, _ = 1;
				rep(i, 0, n-1) {
					if(c[i] == '(') ++now;
					else {
						--now;
						if(now < 0) {_ = 0; break;}
					}
				}
				if(_ && !now) puts("YES");
				else puts("NO");
			}
		}
	} 
	return 0;
}