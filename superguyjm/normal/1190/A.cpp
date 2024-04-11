#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 100001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

LL a[N];

int main() {
	LL n = read(); int m = read(); LL k = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int j = i, s = i - 1;
		while(j < m && (a[j + 1] - s - 1) / k == (a[i] - s - 1) / k) j++;
		ans++, i = j;
	} put(ans), puts("");
	return 0;
}