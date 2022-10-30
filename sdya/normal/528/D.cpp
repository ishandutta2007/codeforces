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
#include <complex>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int L = 410010;
const int B = 1000000;
const int LB = 6;

class Long
{
public:
	int m[L], l;
	int &operator [](int i) { return m[i]; }
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
long long fl(double x) { return x<0?x-0.5:x+0.5; }
Long operator &(Long x, Long y)
{
	int i, n;
	long long h;
	for(n=1; n<x.l+y.l; n*=2);
	for(i=0; i<n; vx[i]=0, vy[i]=0, z[i]=complex <double> (cos(2*PI*i/n), sin(2*PI*i/n)), i++);
	for(i=0; i<x.l; vx[i]=x[i], i++);
	for(i=0; i<y.l; vy[i]=y[i], i++);
	for(fft(vx, u, n, 1), fft(vy, u, n, 1), i=0; i<n; vx[i]*=vy[i], z[i]=complex <double> (z[i].real(), -z[i].imag()), i++);
	for(fft(vx, u, n, 1), x.l+=y.l, h=0, i=0; i<x.l; h+=fl(vx[i].real()/n), x[i]=h%B, h/=B, i++);
	for(; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}

int n, m, k;
char s[L], t[L];
int a[L], b[L];

int res[L];

void solve() {
	Long x, y;
	for (int i = L - 1; i >= 0; --i) {
		x.m[i] = 0;
		y.m[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		x.m[i] = a[i];
	}
	x.l = n;
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		y.m[m - 1 - i] = b[i];
		cnt += b[i];
	}
	y.l = m;

	Long z = (x & y);
	for (int i = m - 1; i < n; ++i) {
		int value = 0;
		if (i < z.l) {
			value = z.m[i];
		}

		if (value != cnt) {
			res[i - m + 1] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", &s, &t);

	for (int i = 0; i <= n - m; ++i) {
		res[i] = 1;
	}

	string p = "ACGT";
	for (int r = 0; r < 4; ++r) {
		vector < int > pos;
		for (int i = 0; i < n; ++i) {
			if (s[i] == p[r]) {
				pos.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			a[i] = 0;
			int index = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
			for (int j = max(0, index - 2); j < pos.size() && j < index + 2; ++j) {
				if (abs(pos[j] - i) <= k) {
					a[i] = 1;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			b[i] = (int)(p[r] == t[i]);
		}
		solve();
	}

	int ans = 0;
	for (int i = 0; i <= n - m; ++i) {
		ans += res[i];
	}

	printf("%d\n", ans);

	return 0;
}