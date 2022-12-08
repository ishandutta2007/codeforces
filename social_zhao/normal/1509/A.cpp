#include <cstdio>
using namespace std;
const int MAXN = 200011;

int n, tot, cnt;
int a[MAXN], b[MAXN];

int read() {
	int X = 0, F = 1; char C = getchar();
	while(C < '0' || C > '9') {if(C == '-')F=-1; C = getchar();}
	while(C >= '0' && C <= '9') {X = X*10+C-'0'; C = getchar();}
	return X * F;
}

int main() {
	int T = read();
	while(T--) {
		tot = cnt = 0;
		n = read();
		for(int i = 1, x; i <= n; ++i) {
			x = read();
			if(x & 1) a[++tot] = x;
			else b[++cnt] = x;
		}
		for(int i = 1; i <= tot; ++i)
			printf("%d ", a[i]);
		for(int j = 1; j <= cnt; ++j)
			printf("%d ", b[j]);
		puts("");
	}
	return 0;
}