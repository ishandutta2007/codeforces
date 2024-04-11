#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxr 100000
#define maxn 500051
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

bool vis[maxn];
int mat[maxn];
int n, m, cm = 0;
int lis[maxn];
int cs = 0;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		cm = cs = 0;
		int x, y;
		read(n), read(m);
		rep(i, 1, m) {
			read(x), read(y);
			if (vis[x] || vis[y]) continue;
			vis[x] = vis[y] = 1, mat[++cm] = i;
			lis[++cs] = x, lis[++cs] = y;
		}
		if (cm >= n){
			printf("Matching\n");
			rep(i, 1, n) printf("%d ", mat[i]); 
			printf("\n");
		}
		else {
			printf("IndSet\n");
			int ct = 0;
			rep(i, 1, 3 * n){
				if (!vis[i]) {
					ct++;
					printf("%d ", i);
					if (ct == n) break;
				}
			}
			printf("\n");
		}
		rep(i, 1, cs) vis[lis[i]] = 0;
	}
	return 0;
}