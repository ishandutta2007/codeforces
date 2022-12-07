#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 300019
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n, h;
int p[maxn];

int main(){
	int T;
	read(T);
	while (T--){
		read(h), read(n);
		rep(i, 1, n) read(p[i]); p[n + 1] = 0;
		int ans = 0;
		rep(i, 1, n - 1){
			if (p[i + 1] - p[i + 2] == 1) {i++;continue;}
			else ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}