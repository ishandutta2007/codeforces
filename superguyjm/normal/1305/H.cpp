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
const int N = 1e5 + 2;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I LL read() {
	LL x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

int n, m, x[N], a[N];
LL T, l[N], r[N], s[N];

I bool check() {
	fo(i, 1, m) s[i] = s[i - 1] + a[i];
	reg j = m; fo(i, 0, n) {
		while(j && a[j] >= n - i) j--;
		if(l[i] + s[j] + (LL)(n - i) * (m - j) < l[n]) return 0;
		if(r[i] + s[j] + (LL)(n - i) * (m - j) < T) return 0;
	} return 1;
}

I bool check(cr p, cr v) {
	LL sum = 0; bool bk = 0;
	fo(i, 1, m) {
		a[i] = _max(a[i - 1], x[i]);
		if(m - i + 1 <= p) {
			if(x[i] != -1) bk |= 1;
			if(x[i] != -1 && x[i] < v) return 0;
		}
	} fo(i, m - p + 1, m) {
		if(x[i] != -1 && a[i] != a[m]) return 0;
		a[i] = _max(v, a[m]);
	} fo(i, 1, m) sum += a[i];
	if(sum > T) return 0;
	sum = T - sum;
	LL bak = sum;
	reg lst = 0;
	fo(i, 1, m) {
		if(x[i] != -1 || m - i + 1 <= p) {
			reg len = i - lst - 1, inc = a[i] - a[lst];
			if((LL)inc * len <= sum) {
				sum -= (LL)inc * len;
				fo(j, lst + 1, i - 1) a[j] += inc;
			} else {
				inc = sum / len, sum -= (LL)inc * len;
				fo(j, lst + 1, i - 1) {
					a[j] += inc;
					if(i - j <= sum) a[j]++;
				} sum = 0;
				break;
			} lst = i;
		}
	} if(bk) {
		if(sum) return 0;
	} else {
		if(sum) {
			reg zz = p;
			while(zz < m && x[m - zz] == -1) zz++;
			LL hh = (sum - 1) / zz + 1;
			fo(i, 1, m) {
				a[i] = _max(a[i - 1], x[i]);
				if(m - i + 1 <= p) a[i] = _max(a[i], v);
			} if(a[m] + hh > n) return 0;
			fo(i, m - p + 1, m) a[i] += hh;
			sum = bak - (LL)hh * p;
			if(sum < 0) return 0;
			lst = 0;
			fo(i, 1, m) {
				if(x[i] != -1 || m - i + 1 <= p) {
					reg len = i - lst - 1, inc = a[i] - a[lst];
					if((LL)inc * len <= sum) {
						sum -= (LL)inc * len;
						fo(j, lst + 1, i - 1) a[j] += inc;
					} else {
						inc = sum / len, sum -= (LL)inc * len;
						fo(j, lst + 1, i - 1) {
							a[j] += inc;
							if(i - j <= sum) a[j]++;
						} sum = 0;
						break;
					} lst = i;
				}
			} if(sum) return 0;
		}
	} return check();
}

int main() {
	n = read(), m = read();
	fo(i, 1, n) l[i] = read(), r[i] = read();
	sort(l + 1, l + n + 1), sort(r + 1, r + n + 1);
	fo(i, 1, n) l[i] += l[i - 1], r[i] += r[i - 1];
	reg q = read();
	memset(x, -1, sizeof(x));
	while(q--) {
		reg p = read(), s = read();
		x[m - p + 1] = s;
	} fo(i, 1, m) {
		a[i] = _max(a[i - 1], x[i]);
		if(x[i] != -1 && x[i] < a[i]) {puts("-1 -1"); return 0;}
	} T = read();
	if(!check(1, 0)) {puts("-1 -1"); return 0;}
	reg l = 1, r = m, ans;
	while(l <= r) {
		reg mid = l + r >> 1;
		if(check(mid, 0)) l = mid + 1, ans = mid;
		else r = mid - 1;
	} pr1(ans);
	l = 0, r = n; reg hh;
	while(l <= r) {
		reg mid = l + r >> 1;
		if(check(ans, mid)) l = mid + 1, hh = mid;
		else r = mid - 1;
	} pr2(hh);
	return 0;
}