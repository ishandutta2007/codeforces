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

int a[2001];

int main() {
	int q = read();
	while(q--) {
		int n = read();
		for(int i = 1; i <= n * 4; i++) a[i] = read();
		sort(a + 1, a + n * 4 + 1);
		bool bk = 0;
		for(int i = 1; i <= 2 * n; i += 2) {
			int x1 = i, x2 = i + 1, y1 = 4 * n - i + 1, y2 = 4 * n - i;
			if(a[x1] == a[x2] && a[y1] == a[y2]) {
				if(a[x1] * a[y1] == a[1] * a[4 * n]) ;
				else bk = 1;
			} else bk = 1;
		}
		if(bk) puts("NO");
		else puts("YES");
	}
	return 0;
}