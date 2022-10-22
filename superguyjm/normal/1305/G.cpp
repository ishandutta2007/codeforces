#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define R register
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define fo(i, a, b) for(reg i = a; i <= b; i++)
#define fd(i, a, b) for(reg i = a; i >= b; i--)
#define cr const reg&
using namespace std;
const int N = 1 << 18;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I int read() {
	reg x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

int a[N], fa[N], cnt[N];
LL ans = 0;

I int findfa(cr x) {return fa[x] == x ? x : fa[x] = findfa(fa[x]);}

I void Merge(cr x, cr y, cr c) {
	reg u = findfa(x), v = findfa(y);
	if(u ^ v) ans += (LL)c * (cnt[u] + cnt[v] - 1), fa[u] = v, cnt[v] = 1;
}

int main() {
	reg n = read();
	reg mx = 0;
	fo(i, 1, n) a[i] = read(), cnt[a[i]]++, ans -= a[i], mx = _max(mx, a[i]);
	cnt[0]++;
	reg m = 1;
	for(; m <= mx; m <<= 1);
	fo(i, 0, m - 1) fa[i] = i;
	fd(i, m - 1, 0) {
		for(reg j = i; j; j = (j - 1) & i) if(cnt[j] && cnt[i ^ j]) Merge(j, i ^ j, i);
		if(cnt[i] && cnt[0]) Merge(i, 0, i);
	} pr2(ans);
	return 0;
}