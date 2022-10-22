#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

char ss[52][52];
int f[52][52][52][52], s[52][52];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) scanf("%s", ss[i] + 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) s[i][j] = (ss[i][j] == '#') + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		for(int x1 = 1; x1 <= n - i + 1; x1++) for(int y1 = 1; y1 <= n - j + 1; y1++) {
			int x2 = x1 + i - 1, y2 = y1 + j - 1;
			f[x1][y1][x2][y2] = _max(x2 - x1 + 1, y2 - y1 + 1);
			for(int h = x1; h <= x2; h++) 
			if(s[h][y2] - s[h - 1][y2] - s[h][y1 - 1] + s[h - 1][y1 - 1] == 0) f[x1][y1][x2][y2] = _min(f[x1][y1][x2][y2], f[x1][y1][h - 1][y2] + f[h + 1][y1][x2][y2]);
			for(int h = y1; h <= y2; h++) if(s[x2][h] - s[x2][h - 1] - s[x1 - 1][h] + s[x1 - 1][h - 1] == 0) f[x1][y1][x2][y2] = _min(f[x1][y1][x2][y2], f[x1][y1][x2][h - 1] + f[x1][h + 1][x2][y2]);
		}
	} put(f[1][1][n][n]), puts("");
	return 0;
}