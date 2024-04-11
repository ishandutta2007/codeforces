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
const int N = 5e5 + 10;

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

int Log[N], bin[20];
int a[N], gg[N], mn[20][N], mx[20][N];

I pii query(cr l, cr r) {
	reg hh = Log[r - l];
	return pii{_min(mn[hh][l], mn[hh][r - bin[hh]]), _max(mx[hh][l], mx[hh][r - bin[hh]])};
}

int main() {
	reg n = read();
	fo(i, 1, n) a[i] = read();
	a[0] = a[1], a[n + 1] = a[n];
	bin[0] = 1; fo(i, 1, 19) bin[i] = bin[i - 1] << 1;
	fo(i, 2, n + 1) Log[i] = Log[i >> 1] + 1;
	fo(i, 0, n) mn[0][i] = _max(a[i], a[i + 1]), mx[0][i] = _min(a[i], a[i + 1]);
	fo(i, 1, 19) fo(j, 0, n - bin[i] + 1) 
	mn[i][j] = _min(mn[i - 1][j], mn[i - 1][j + bin[i - 1]]), mx[i][j] = _max(mx[i - 1][j], mx[i - 1][j + bin[i - 1]]);
	reg ans = 0;
	fo(i, 1, n) {
		reg l = 1, r = _min(i, n - i + 1), z;
		while(l <= r) {
			reg mid = l + r >> 1;
			pii h = query(i - mid, i + mid);
			if(h.fi <= h.se) r = mid - 1, z = mid;
			else l = mid + 1;
		} if(z == 1) gg[i] = a[i];
		else {
			pii h = query(i - z, i + z);
			if(a[i] > a[i - 1]) {
				if(z % 2 == 0) gg[i] = h.se;
				else gg[i] = h.fi;
			} else {
				if(z % 2 == 0) gg[i] = h.fi;
				else gg[i] = h.se;
			}
		} ans = _max(ans, z - 1);
	} pr2(ans);
	fo(i, 1, n) pr1(gg[i]);
	return 0;
}