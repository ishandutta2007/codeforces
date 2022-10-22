#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 1000001;

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

int a[N];

int main() {
	int n = read(), x = read(), y = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int j = 1; j <= n; j++) {
		bool bk = 0;
		for(int i = j - 1; i >= _max(j - x, 1); i--) {
			if(a[i] < a[j]) {bk = 1; break;
			}
		} for(int i = j + 1; i <= _min(j + y, n); i++) {
			if(a[i] < a[j]) {bk = 1; break;
			}
		} if(!bk) {
			put(j), puts("");
			return 0;
		}
	}
	return 0;
}