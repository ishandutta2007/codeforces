#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <complex>
#include <math.h>
using namespace std;
const int L = 350;
const int B = 1000000;
const int LB = 6;
class Long
{
public:
	int m[L], l;
	int &operator [](int i) { return m[i]; }
	Long operator =(long long x)
	{
		for(l=1, m[l-1]=x%B, x/=B; x; m[l++]=x%B, x/=B);
		return *this;
	}
	Long operator =(int x)
	{
		for(l=1, m[l-1]=x%B, x/=B; x; m[l++]=x%B, x/=B);
		return *this;
	}
	Long operator =(char *s)
	{
		int i, j, n;
		for(n=0; s[n]>='0' && s[n]<='9'; n++);
		for(l=(n+LB-1)/LB, i=0; i<l; i++)
			for(m[i]=0, j=0; j<LB; j++)
				if(n-i*LB-LB+j>=0) m[i]=m[i]*10+s[n-i*LB-LB+j]-'0';
		return *this;
	}
	bool inp()
	{
		char s[L*LB+10];
		if(scanf("%s", s)==EOF) return 0;
		else { *this=s; return 1; }
	}
	void out()
	{
		int i;
		char s[8];
		for(sprintf(s, "%%0%dd", LB), printf("%d", m[l-1]), i=l-2; i>=0; printf(s, m[i]), i--);
	}
};
bool operator <(Long x, Long y)
{
	int i;
	if(x.l!=y.l) return x.l<y.l;
	for(i=x.l-1; i>=0 && x[i]==y[i]; i--);
	return i>=0 && x[i]<y[i];
}
Long operator +(Long x, Long y)
{
	int i;
	long long h;
	for(h=0, i=0; i<x.l || i<y.l || h; h+=(i<x.l)*x[i]+(i<y.l)*y[i], x[i]=h%B, h/=B, i++);
	x.l=i;
	return x;
}
Long operator -(Long x, Long y)
{
	int i;
	long long h;
	for(h=0, i=0; i<x.l; h+=x[i]-(i<y.l)*y[i]+B, x[i]=h%B, h/=B, h--, i++);
	for(; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}
Long operator *(Long x, int y)
{
	int i;
	long long h;
	for(h=0, i=0; i<x.l || h; h+=(i<x.l)*(long long)x[i]*y, x[i]=h%B, h/=B, i++);
	for(x.l=i; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}
Long operator /(Long x, int y)
{
	int i;
	long long h;
	for(h=0, i=x.l-1; i>=0; h=h*B+x[i], x[i]=h/y, h%=y, i--);
	for(; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}
int operator %(Long x, int y)
{
	int i;
	long long h;
	for(h=0, i=x.l-1; i>=0; h=h*B+x[i], h%=y, i--);
	return h;
}
Long operator *(Long x, Long y)
{
	int i, j;
	long long h;
	Long z;
	for(h=0, z.l=x.l+y.l, i=0; i<z.l; z[i]=h%B, h/=B, i++)
		for(j=i<x.l-1?i:x.l-1; j>=0 && i-j<y.l; h+=(long long)x[j]*y[i-j], j--);
	for(; z.l>1 && !z[z.l-1]; z.l--);
	return z;
}
Long operator /(Long x, Long y)
{
	int i;
	Long h, t;
	if(y.l==1) return x/y[0];
	for(h=0, i=x.l-1; i>=0; h=h-y*x[i], i--)
		for(t=x[i], h=h*B+t, x[i]=((h.l>y.l)*((long long)h[h.l-1]*B*B+(long long)h[h.l-2]*B+h[h.l-3])+(h.l==y.l)*((long long)h[h.l-1]*B+h[h.l-2]))/((long long)y[y.l-1]*B+y[y.l-2]); x[i] && h<y*x[i]; x[i]--);
	for(; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}
Long operator %(Long x, Long y)
{
	int i;
	Long h, t;
	if(y.l==1) return h=x%y[0];
	for(h=0, i=x.l-1; i>=0; h=h-y*x[i], i--)
		for(t=x[i], h=h*B+t, x[i]=((h.l>y.l)*((long long)h[h.l-1]*B*B+(long long)h[h.l-2]*B+h[h.l-3])+(h.l==y.l)*((long long)h[h.l-1]*B+h[h.l-2]))/((long long)y[y.l-1]*B+y[y.l-2]); x[i] && h<y*x[i]; x[i]--);
	return h;
}

const int maxN = 4000;
const long long P = 1000000007LL;
int digits[maxN], n;
long long d[2][maxN][2][2];
int p, a;

void set0(long long d[maxN][2][2], int l) {
	for (int i = 0; i <= l; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				d[i][j][k] = 0;
			}
		}
	}
}

int w[10][2][2];
int sw[10][2][2];
int tw[2][2];

void add(long long &x, long long value) {
	x = (x + value) % P;
}

void precalc(int p) {
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int carry = 0; carry < 2; ++carry) {
				++w[(i + j + carry) % p][carry][(i + j + carry) / p];
				for (int k = (i + j + carry) % p; k < p; ++k) {
					++sw[k][carry][(i + j + carry) / p];
				}
				++tw[carry][(i + j + carry) / p];
			}
		}
	}
}

long long getWays(long long s) {
	if (s < p) {
		return s + 1;
	}
	if (s > p + p - 2) {
		return 0;
	}
	return p - (s - (p - 1));
}

long long getWaysUpTo(long long s) {
	if (s < 0) {
		return 0;
	}
	if (s < p) {
		return (s + 1LL) * (s + 2LL) / 2LL;
	}
	if (s > p + p - 2) {
		s = p + p - 2;
	}
	return (s + 2) * ((long long)(p + p) - s - 1) / 2LL + (s - p + 1) * p;
}

long long getWays(long long l, long long r) {
	return getWaysUpTo(r) - getWaysUpTo(l - 1);
}

int getTotalWays(int carried, int carry) {
	return getWays(p * carry - carried, p * (carry + 1) - 1 - carried) % P;
}

int getWays(int digit, int carried, int carry) {
	return getWays(p * carry + digit - carried) % P;
}

int getWaysUpTo(int digit, int carried, int carry) {
	return getWays(p * carry - carried, p * carry + digit - carried) % P;
}

void solve() {
	int u = 0, v = 1;
	set0(d[u], 1);
	d[u][0][0][0] = 1;

	int tw00 = getTotalWays(0, 0);
	int tw01 = getTotalWays(0, 1);
	int tw10 = getTotalWays(1, 0);
	int tw11 = getTotalWays(1, 1);
	for (int len = 0; len < n; ++len, swap(u, v)) {
		set0(d[v], len + 1);
		int dg = digits[len];
		int dg00 = getWays(dg, 0, 0);
		int dg01 = getWays(dg, 0, 1);
		int dg10 = getWays(dg, 1, 0);
		int dg11 = getWays(dg, 1, 1);

		int pg00 = getWaysUpTo(dg - 1, 0, 0);
		int pg01 = getWaysUpTo(dg - 1, 0, 1);
		int pg10 = getWaysUpTo(dg - 1, 1, 0);
		int pg11 = getWaysUpTo(dg - 1, 1, 1);
		for (int tot = 0; tot <= len; ++tot) {
			add(d[v][tot][1][0], d[u][tot][1][0] * tw00);
			add(d[v][tot][1][1], d[u][tot][1][0] * tw10);

			add(d[v][tot + 1][1][0], d[u][tot][1][1] * tw01);
			add(d[v][tot + 1][1][1], d[u][tot][1][1] * tw11);

			add(d[v][tot][0][0], d[u][tot][0][0] * dg00);
			add(d[v][tot][0][1], d[u][tot][0][0] * dg10);

			add(d[v][tot + 1][0][0], d[u][tot][0][1] * dg01);
			add(d[v][tot + 1][0][1], d[u][tot][0][1] * dg11);

			if (dg > 0) {
				add(d[v][tot][1][0], d[u][tot][0][0] * pg00);
				add(d[v][tot][1][1], d[u][tot][0][0] * pg10);

				add(d[v][tot + 1][1][0], d[u][tot][0][1] * pg01);
				add(d[v][tot + 1][1][1], d[u][tot][0][1] * pg11);
			}
		}
	}

	long long res = 0;
	for (int i = a; i <= n; ++i) {
		add(res, d[u][i][0][0] + d[u][i][1][0]);
	}

	printf("%d\n", (int)(res % P));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &p, &a);

	Long A;
	A.inp();

	Long zero;
	zero = 0;

	n = 0;
	while (zero < A) {
		digits[n++] = (A % p);
		A = (A / p);
	}
	reverse(digits, digits + n);
	solve();

	return 0;
}