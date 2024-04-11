#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

const double Pi = 4 * atan(1);
typedef long long intl;

namespace FFT
{
	#define double long double
	struct Complex
	{
		double real, imag;
		Complex() { real = imag = 0; }
		Complex(const double &real) : real(real) { imag = 0; }
		Complex(const double &real, const double &imag) : real(real), imag(imag) { }
		Complex operator +(const Complex &rhs)
		{
			return Complex(real + rhs.real, imag + rhs.imag);
		}
		Complex operator -(const Complex &rhs)
		{
			return Complex(real - rhs.real, imag - rhs.imag);
		}
		Complex operator *(const Complex &rhs)
		{
			return Complex(real * rhs.real - imag * rhs.imag,
						real * rhs.imag + imag * rhs.real);
		}
		Complex operator /(const double &rhs)
		{
			return Complex(real / rhs, imag / rhs);
		}
	};
	void dft(vector <Complex> &a, bool inv = false)
	{
		int n = a.size();
		for (int i = 1, j = 0; i < n - 1; i++)
		{
			for (int s = n; j ^= s >>= 1, ~j & s;);  
			if (i < j)
				swap(a[i], a[j]);
		}
		for(int len = 2; len <= n; len <<= 1)
		{
			int half = len >> 1;
			double ang = 2 * Pi / len * (inv ? -1 : 1);
			Complex unit(cos(ang), sin(ang));
			for(int i = 0; i < n; i += len)
			{
				Complex w(1);
				for(int j = 0; j < half; j ++)
				{
					Complex u = a[i + j];
					Complex v = w * a[i + j + half];
					a[i + j] = u + v;
					a[i + j + half] = u - v;
					w = w * unit;
				}
			}
		}

		if(inv)
			for(int i = 0; i < n; i ++)
				a[i] = a[i] / n;
	}

	vector <intl> multiply(const vector <intl> &v1, const vector <intl> &v2)
	{
		int n1 = v1.size();
		int n2 = v2.size();
		int n = 1;
		while(n < n1 || n < n2)
			n <<= 1;
		n <<= 1;

		vector <Complex> c1(n, 0), c2(n, 0);
		for(int i = 0; i < n1; i ++)
			c1[i] = v1[i];
		for(int i = 0; i < n2; i ++)
			c2[i] = v2[i];
		dft(c1);
		dft(c2);
		for(int i = 0; i < n; i ++)
			c1[i] = c1[i] * c2[i];
		dft(c1, true);

		vector <intl> res(n);
		for(int i = 0; i < n; i ++)
			res[i] = (intl)(c1[i].real + 0.5);
		return res;
	}

	vector <intl> multiply_mod(const vector <intl> &v1, const vector <intl> &v2, const intl &mod)
	{
		int n = v1.size();
		intl sq = (intl)sqrt(mod);
		vector <intl> s0(n), s1(n), s2(n), s3(n);
		for(int i = 0; i < n; i ++)
		{
			s0[i] = v1[i] % sq;
			s1[i] = v1[i] / sq;
			s2[i] = v2[i] % sq;
			s3[i] = v2[i] / sq;
		}
		vector <intl> r0 = multiply(s0, s2);
		vector <intl> r1 = multiply(s0, s3);
		vector <intl> r2 = multiply(s1, s2);
		vector <intl> r3 = multiply(s1, s3);

		r0.resize(n);
		for(int i = 0; i < n; i ++)
		{
			r0[i] += (r1[i] + r2[i]) % mod * sq % mod;
			r0[i] += r3[i] % mod * sq % mod * sq % mod;
			r0[i] %= mod;
		}
		return r0;
	}
	//#undef double
}

const int N = (1 << 15);
const intl Mod = (intl)1e9 + 7;
intl fac[N];
intl inv_fac[N];

intl qpow(intl a, intl b)
{
	intl ret = 1;
	intl tmp = a;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
		b >>= 1;
	}
	return ret;
}

vector <intl> multiply(vector <intl> v1, vector <intl> &v2, intl m)
{
	for(int i = 0; i < N; i ++)
	{
		v1[i] *= qpow(2, m * i);
		v1[i] %= Mod;
	}
	vector <intl> ret = FFT :: multiply_mod(v1, v2, Mod);
	/*
	for(int i = 0; i < 5; i ++)
		cout << i << ' ' << v1[i] << ' ' << v2[i] << ' ' << ret[i] << '\n';
	*/
	ret.resize(N);
	return ret;
}

vector <intl> qpow(vector <intl> &vec, intl b)
{
	vector <intl> ret(N, 0);
	vector <intl> tmp = vec;

	ret[0] = 1;
	intl m = 1;
	while(b > 0)
	{
		if(b & 1)
			ret = multiply(ret, tmp, m);
		tmp = multiply(tmp, tmp, m);
		m <<= 1;
		b >>= 1;
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	fac[0] = inv_fac[0] = 1;
	fac[1] = inv_fac[1] = 1;
	for(int i = 2; i < N; i ++)
	{
		fac[i] = fac[i - 1] * i % Mod;
		inv_fac[i] = (Mod - Mod / i) * inv_fac[Mod % i] % Mod;
		//assert(inv_fac[i] > 0);
	}
	for(int i = 1; i < N; i ++)
		inv_fac[i] = inv_fac[i - 1] * inv_fac[i] % Mod;

	intl n;
	int k;
	cin >> n >> k;
	if(n > k)
	{
		cout << 0 << '\n';
		return 0;
	}
	vector <intl> vec(N);
	vec[0] = 0;
	for(int i = 1; i <= k; i ++)
		vec[i] = inv_fac[i];

	vec = qpow(vec, n);
	intl ans = 0;
	for(int i = 0; i <= k; i ++)
	{
		//cout << i << ' ' << vec[i] << '\n';
		ans += vec[i] * fac[k] % Mod * inv_fac[k - i] % Mod;
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}