#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define P 1000000009
#define N 300010

struct mat {
	int a00,a01,a02,a10,a11,a12,a20,a21,a22;
	mat () {a00=a01=a02=a10=a11=a12=a20=a21=a22=0;}
	mat operator * (const mat&b) {
		mat c;
		c.a00=((ll)a00*b.a00+(ll)a01*b.a10%P+(ll)a02*b.a20%P)%P;
		c.a01=((ll)a00*b.a01+(ll)a01*b.a11%P+(ll)a02*b.a21%P)%P;
		c.a02=((ll)a00*b.a02+(ll)a01*b.a12%P+(ll)a02*b.a22%P)%P;
		c.a10=((ll)a10*b.a00+(ll)a11*b.a10%P+(ll)a12*b.a20%P)%P;
		c.a11=((ll)a10*b.a01+(ll)a11*b.a11%P+(ll)a12*b.a21%P)%P;
		c.a12=((ll)a10*b.a02+(ll)a11*b.a12%P+(ll)a12*b.a22%P)%P;
		c.a20=((ll)a20*b.a00+(ll)a21*b.a10%P+(ll)a22*b.a20%P)%P;
		c.a21=((ll)a20*b.a01+(ll)a21*b.a11%P+(ll)a22*b.a21%P)%P;
		c.a22=((ll)a20*b.a02+(ll)a21*b.a12%P+(ll)a22*b.a22%P)%P;
		return c;
	}
};

struct vec {
	int a0,a1,a2;
	vec() {a0=a1=a2=0;}
	vec operator + (const vec&b) {
		vec c;
		c.a0=(a0+b.a0)%P;
		c.a1=(a1+b.a1)%P;
		c.a2=(a2+b.a2)%P;
		return c;
	}
	vec operator * (const mat&b) {
		vec c;
		c.a0=((ll)a0*b.a00%P+(ll)a1*b.a10%P+(ll)a2*b.a20%P)%P;
		c.a1=((ll)a0*b.a01%P+(ll)a1*b.a11%P+(ll)a2*b.a21%P)%P;
		c.a2=((ll)a0*b.a02%P+(ll)a1*b.a12%P+(ll)a2*b.a22%P)%P;
		return c;
	}
	vec rec() {
		vec c;
		c.a0 = a0;
		c.a1 = a1;
		return c;
	}
};

int n,m, a[N];
int f[N*4]; // sum
vec g[N*4];

void blt(int p, int l, int r) {
	if (l == r-1) {
		f[p] = a[l];
		return;
	}
	int mid = (l+r)/2;
	blt(p*2+1,l,mid);
	blt(p*2+2,mid,r);
	f[p] = (f[p*2+1]+f[p*2+2])%P;
}

vec fv[N];
mat fm[N];

void add(int p, vec a, mat b) {
	(f[p] += (a*b).a2) %= P;
	g[p] = g[p] + a;
}

void add(int p, int l, int r, int L, int R, int st) {
	if (L <= l && r <= R) {
		add(p,fv[st],fm[r-l]);
		return;
	}
	int mid = (l+r)/2;
	add(p*2+1,g[p],fm[mid-l]);
	add(p*2+2,(g[p]*fm[mid-l]).rec(),fm[r-mid]);
	g[p] = vec();
	if (L < mid) add(p*2+1,l,mid,L,R,st);
	if (mid < R) add(p*2+2,mid,r,L,R,st+max(L,mid)-max(l,L));
	f[p] = (f[p*2+1]+f[p*2+2])%P;
}

int ask(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return f[p];
	int mid = (l+r)/2;
	add(p*2+1,g[p],fm[mid-l]);
	add(p*2+2,(g[p]*fm[mid-l]).rec(),fm[r-mid]);
	g[p] = vec();
	int S = 0;
	if (L < mid) (S += ask(p*2+1,l,mid,L,R)) %= P;
	if (mid < R) (S += ask(p*2+2,mid,r,L,R)) %= P;
	return S;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	blt(0,0,n);
	fv[0].a1 = 1;
	fm[0].a00 = 1;
	fm[0].a11 = 1;
	fm[0].a22 = 1;
	fm[1].a10 = 1;
	fm[1].a01 = 1;
	fm[1].a11 = 1;
	fm[1].a02 = 1;
	fm[1].a22 = 1;
	for (int i = 2; i <= n; i ++)
		fm[i] = fm[i-1]*fm[1];
	for (int i = 1; i <= n; i ++)
		fv[i] = (fv[i-1]*fm[1]).rec();
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		l --;
		if (t == 1) {
			add(0,0,n,l,r,1);
		} else
		if (t == 2) {
			cout << ask(0,0,n,l,r) << endl;
		}
	}
	return 0;
}