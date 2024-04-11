#include <bits/stdc++.h>
using namespace std;
#define M  1000001
int a[M];

int mi[21][M], mx[21][M];

int calc1(int x, int y) {
    int cur = 1, p = 0;
    while(cur <= y - x + 1) {
        cur *= 2; p ++;
    }
    p --; cur /= 2;
    return min(mi[p][x], mi[p][y - cur + 1]);
}
int calc2(int x, int y) {
    int cur = 1, p = 0;
    while(cur <= y - x + 1) {
        cur *= 2; p ++;
    }
    p --; cur /= 2;
    return max(mx[p][x], mx[p][y - cur + 1]);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) mi[0][i] = mx[0][i] = a[i];
    for(int i = 1; i < 20; i ++) {
    	for(int j = 1; j <= n; j ++) {
    		int k = j + (1 << (i - 1));
    		if(k > n) continue;
			mi[i][j] = min(mi[i-1][j], mi[i-1][k]);
			mx[i][j] = max(mx[i-1][j], mx[i-1][k]);
    	}
    }
    while(m --) {
        int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
        if(calc1(x, y) == z && calc2(x, y) == z) {
        	puts("-1");
			continue;
        }
        if(a[x] != z) {
        	printf("%d\n", x);
			continue;
        }
        int st = x, en = y;
        while(en > st + 1) {
            int mid = (en + st) / 2;
			if(calc1(st, mid) == z && calc2(st, mid) == z) st = mid;
			else en = mid;
        }
        printf("%d\n", en);
    }
}