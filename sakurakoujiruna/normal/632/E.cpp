#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double Pi = 4 * atan(1);
//typedef long long intl;
typedef int intl;

namespace FFT
{
	//#define double long double
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

	vector <intl> multiply_mod(const vector <intl> &v1, const vector <intl> &v2, const int &mod)
	{
		int n = v1.size();
		int sq = sqrt(mod);
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

void norm(vector <int> &v)
{
	while(*--v.end() == 0)
		v.pop_back();
	for(auto &x : v)
		x = (x > 0);
}

vector <int> qpow(vector <int> v, int b)
{
	vector <int> ans(1, 1);
	vector <int> tmp = v;
	while(b > 0)
	{
		if(b & 1)
		{
			ans = FFT :: multiply(ans, tmp);
			norm(ans);
		}
		tmp = FFT :: multiply(tmp, tmp);
		norm(tmp);
		b >>= 1;
	}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> v(1001, 0);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		v[x] = 1;
	}
	vector <int> ans = qpow(v, k);
	for(int i = 0; i < ans.size(); i ++)
		if(ans[i])
			cout << i << ' ';
	cout << '\n';
}