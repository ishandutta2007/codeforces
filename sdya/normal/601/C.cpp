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
#include <complex>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int L = 110000;
const int B = 100000;
const int LB = 5;
class Long
{
public:
	double m[L];
	int l;
	double &operator [](int i) { return m[i]; }
};

double PI=2*acos(0.0);
complex <double> vx[2*L], vy[2*L], u[2*L], z[2*L], z0;

void fft(complex <double> *v, complex <double> *u, int n, int d)
{
	if(n==1) return;
	int i;
	n/=2;
	for(i=0; i<n; u[i]=v[2*i], u[i+n]=v[2*i+1], i++);
	fft(u, v, n, 2*d);
	fft(u+n, v, n, 2*d);
	for(i=0; i<n; z0=z[i*d]*u[i+n], v[i]=u[i]+z0, v[i+n]=u[i]-z0, i++);
}

const double eps = 1e-14;

Long operator &(Long x, Long y)
{
	int i, n;
	long long h;
	for(n=1; n<x.l+y.l; n*=2);
	for(i=0; i<n; vx[i]=0, vy[i]=0, z[i]=complex <double> (cos(2*PI*i/n), sin(2*PI*i/n)), i++);
	for(i=0; i<x.l; vx[i]=x[i], i++);
	for(i=0; i<y.l; vy[i]=y[i], i++);
	for(fft(vx, u, n, 1), fft(vy, u, n, 1), i=0; i<n; vx[i]*=vy[i], z[i]=complex <double> (z[i].real(), -z[i].imag()), i++);
	for(fft(vx, u, n, 1), x.l+=y.l, h=0, i=0; i<x.l; x[i]=vx[i].real() / n, i++);
	for(; x.l>1 && x[x.l-1] < eps; x.l--);
	for (int i = x.l - 1; i >= 0; --i) {
		if (x[i] < eps) {
			x[i] = 0.0;
		}
	}
	return x;
}

const int maxN = 110;

int n, m, a[maxN];

Long solve(int l, int r) {
	if (l == r) {
		Long res;
		res.l = m + 1;
		double q = 1.0 / (double)(m - 1);
		res.m[0] = 0.0;
		for (int j = 1; j <= m; ++j) {
			res.m[j] = (a[l] == j ? 0.0 : q);
		}
		return res;
	}

	Long x = solve(l, (l + r) / 2);
	Long y = solve((l + r) / 2 + 1, r);
	return (x & y);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	Long res = solve(0, n - 1);

	double p = 0.0;
	for (int i = 0; i < s && i < res.l; ++i) {
		p += res.m[i];
	}

	p *= (double)(m - 1);
	printf("%.10lf\n", p + 1);


	return 0;
}