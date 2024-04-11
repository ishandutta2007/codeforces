#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 219
using namespace std;

int r, c, k;
char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char gri[maxn][maxn];
char ans[maxn][maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &r, &c, &k);
		rep(i, 1, r) scanf("%s", gri[i] + 1);
		int cnt = 0;
		rep(i, 1, r) rep(j, 1, c) if (gri[i][j] == 'R') cnt++;
		int x = 1, y = 1, d = 1, num = cnt / k, num2 = cnt - k * num;
		rep(i, 1, k){
			int init;
			if (!num2) init = num;
			else num2--, init = num + 1;
			if (i < k){
				while (init){
					if (gri[x][y] == 'R') init--;
					ans[x][y] = s[i - 1];
					y += d;
					if (y > c) x++, d = -d, y = c; 
					else if (y < 1) x++, d = -d, y = 1;
				}
			}
			else {
				while (x <= r){
					if (gri[x][y] == 'R') init--;
					ans[x][y] = s[i - 1];
					y += d;
					if (y > c) x++, d = -d, y = c; 
					else if (y < 1) x++, d = -d, y = 1;
				}
			}
		}
		rep(i, 1, r) {rep(j, 1, c) printf("%c", ans[i][j]); printf("\n");} 
	}
	return 0;
}