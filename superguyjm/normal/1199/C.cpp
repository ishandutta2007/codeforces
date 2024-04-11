#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 400001;

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

int a[N], b[N], s[N];

int main() {
	int n = read(), I = read();
	for(int i = 1; i <= n; i++) a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	int ll = unique(b + 1, b + n + 1) - (b + 1);
	I = I * 8; int k = I / n;
	if(k > 20) {
		puts("0");
		return 0;
	} k = 1 << k;
	for(int i = 1; i <= n; i++) s[lower_bound(b + 1, b + ll + 1, a[i]) - b]++;
	for(int i = 1; i <= ll; i++) s[i] += s[i - 1];
	if(ll <= k) {
		puts("0"); return 0;
	}
	int tp = n, ans = 999999999;
	for(int i = 1; i <= ll - k + 1; i++) {
		int r = i + k - 1;
		ans = _min(ans, s[i - 1] + s[ll] - s[r]);
	} put(ans), puts("");
	return 0;
}