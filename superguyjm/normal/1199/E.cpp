#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 100001;

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

bool v[N * 3];
int tp, sta[N];

int main() {
	int T = read();
	while(T--) {
		int n = read(), m = read(); tp = 0;
		for(int i = 1; i <= 3 * n; i++) v[i] = 0;
		for(int i = 1; i <= m; i++) {
			int x = read(), y = read();
			if(!v[x] && !v[y]) sta[++tp] = i, v[x] = 1, v[y] = 1;
		}if(tp < n) {
			puts("IndSet"); int s = 0;
			for(int i = 1; i <= 3 * n; i++) if(!v[i]){
				put(i), putchar(' ');
				s++; if(s == n) break;
			} puts("");
		} else {
			puts("Matching");
			for(int i = 1; i <= n; i++) put(sta[i]), putchar(' ');
			puts("");
		}
	}
	return 0;
}