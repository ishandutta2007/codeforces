#include <bits/stdc++.h>
using namespace std;

#define M 200001


int f[21][M], g[21][M], a[M];

int calc(int type, int st, int en){
	int cur = 1, r = 0;
	while(cur <= en - st + 1) cur *= 2, r ++;
	r --; cur /= 2;
	if(type == 1) return min(f[r][st], f[r][en - cur + 1]);
    return max(g[r][st], g[r][en - cur + 1]);
}

int main() {
	///freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) f[0][i] = g[0][i] = a[i];
    for(int i = 1; i <= 20; i ++){
    	for(int j = 1; j <= n; j ++) {
			int x = j + (1<<(i-1));
    		if(x > n) continue;
    		f[i][j] = min(f[i-1][j], f[i-1][x]);
    		g[i][j] = max(g[i-1][j], g[i-1][x]);
    	}
    }
    int st = 1, en = n;
    while(en >= st){
        int x = calc(1, st, en);
		int y = calc(2, st, en);
		if(a[st] != x && a[en] != y) {
			swap(a[st], a[en]);
			break;
		}
        else if(a[st] == x && a[en] == y) {
        	st ++;
			en --;
        }
        else if(a[st] == x) {
            st ++;
        }
        else en --;
    }
    int x = -1e9;
	for(int i = 1; i <= n; i ++) {
		if(a[i] < x) return puts("NO");
		x = a[i];
	}
    return puts("YES");
}