#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxr 100000
#define maxn 500015
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, I;
int num[maxn], pre[maxn], a[maxn], b[maxn];

int main(){
	int inf = 1000000000;
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	read(n), read(I);
	int maxk = (I << 3) / n;
	int maxK = (maxk >= 30) ? inf : (1 << maxk);
	rep(i, 1, n) read(a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int _n = unique(b + 1, b + 1 + n) - b - 1;//???
	rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + _n, a[i]) - b;
	rep(i, 1, n) num[a[i]]++;
	rep(i, 1, _n) pre[i] = pre[i - 1] + num[i];
	int ans = n;
	if (maxK >= _n) ans = 0;
	else {
		rep(l, 1, _n - maxK + 1){
			int r = l + maxK - 1;
			ans = min(ans, pre[l - 1] + pre[_n] - pre[r]);
		}
	}
	printf("%d", ans);
	return 0;
}