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
const int qwq[] = { 0,  1,  2,  5,  8, 
					10, 11, 12, 15, 18, 
					20, 21, 22, 25, 28, 
					50, 51, 52, 55, 58, 
					80, 81, 82, 85, 88};
const int qaq[] = { 0, 10, 50, 20, 80, 
					1, 11, 51, 21, 81, 
					5, 15, 55, 25, 85, 
					2, 12, 52, 22, 82, 
					8, 18, 58, 28, 88};

int H, M, h, m, ansh, ansm, ok;

int main() {
	mulT0 {
		scanf("%d%d", &H, &M);
		scanf("%d:%d", &h, &m);
		ansh = ansm = ok = 0;
		rep(i, h, H-1) {
			int oki = 0;
			rep(j, 0, 24) if(i == qwq[j]) {oki = j + 1; break;}
			if(!oki) continue;
			rep(j, (i==h)?m:0, M-1) {
				int okj = 0;
				rep(k, 0, 24) if(j == qwq[k]) {okj = k + 1; break;}
				if(!okj) continue;
				if(qaq[oki-1] < M && qaq[okj-1] < H) {ansh = i; ansm = j; ok = 1; break;}
			}
			if(ok) break;
		}
		printf("%02d:%02d\n", ansh, ansm);
	}
	return 0;
}