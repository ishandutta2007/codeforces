#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, r;
int x[maxn];


int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		read(n), read(r);
		rep(i, 1, n) read(x[i]);
		sort(x + 1, x + 1 + n);
		n = unique(x + 1, x + 1 + n) - x - 1;
		int num = 0;
		per(i, n, 1){
			if ((ll)x[i] <= (ll)num * r) break;
			num++;
		}
		printf("%d\n", num);
	}
	return 0;
}