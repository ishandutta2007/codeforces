#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
typedef vector<complex<double> > Poly;
const int maxn = 1 << 20;
const long long mod = 1009;
const double pi = 3.14159265358979323846;
complex<double> w[maxn];
void pre()
{
	for(int i = 1; (1 << i) <= maxn; i ++)
	{
		complex<double> wn = complex<double>(cos(pi / (1 << i - 1)), sin(pi / (1 << i - 1)));
		w[1 << i - 1] = 1;
		for(int j = (1 << i - 1) + 1; j < (1 << i); j ++)
			w[j] = w[j - 1] * wn;
	}
}
int rev[maxn];
void init(const int &n)
{
	for(int i = 1; i < n; i ++)
		rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
}
void fft(Poly &x, const int &n, const int &mul)
{
	for(int i = 1; i < n; i ++)
		if(i < rev[i])
			swap(x[i], x[rev[i]]);
	for(int i = 1; i < n; i <<= 1)
		for(int j = 0; j < n; j += i << 1)
			for(int k = 0; k < i; k ++)
			{
				complex<double> tmp1 = x[j + k], tmp2 = x[j + i + k] * w[i + k];
				x[j + k] = tmp1 + tmp2;
				x[j + i + k] = tmp1 - tmp2;
			}
	if(mul < 0)
	{
		for(int i = 0; i < n; i ++)
			x[i] /= n;
		for(int i = 1; i < (n >> 1); i ++)
			swap(x[i], x[n - i]);
	}
}
Poly operator*(Poly a, Poly b)
{
	int n = a.size(), m = b.size();
	int len;
	for(len = 1; len < n + m - 1; len <<= 1);
	init(len);
	a.resize(len);
	b.resize(len);
	fft(a, len, 1);
	fft(b, len, 1);
	for(int i = 0; i < len; i ++)
		a[i] *= b[i];
	fft(a, len, -1);
	a.resize(n + m - 1);
	for(int i = 0; i < a.size(); i ++)
		a[i] = (long long)(a[i].real() + 0.5) % mod;
	return a;
}
int cnt[maxn];
Poly a[maxn];
Poly work(const int &l, const int &r)
{
	if(l == r)
		return a[l];
	int mid = l + r >> 1;
	return work(l, mid) * work(mid + 1, r);
}
int main()
{
	std::ios::sync_with_stdio(false);
	pre();
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++)
	{
		 int x;
		 cin >> x;
		 cnt[x] ++;
	}
	for(int i = 1; i <= m; i ++)
	{
		a[i].resize(cnt[i] + 1);
		for(int j = 0; j < a[i].size(); j ++)
			a[i][j] = 1;
	}
	Poly ans = work(1, m);
	cout << ans[k].real() << endl;
	
	return 0;
}