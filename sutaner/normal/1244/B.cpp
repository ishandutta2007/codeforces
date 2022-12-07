#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 2019
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
char s[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		int left = -1, right = -1;
		rep(i, 1, n){
			if (s[i] == '1') {left = i; break;}
		}
		per(i, n, 1) {
			if (s[i] == '1') {right = i; break;}
		}
		if (left == -1) printf("%d\n", n);
		else printf("%d\n", max(right, n - left + 1) << 1); 
	}
	return 0;
}