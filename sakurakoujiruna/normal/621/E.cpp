#include <iostream>
#include <cstring>
using namespace std;

const int N = 211;
typedef long long intl;
const intl Mod = (intl)1e9 + 7;

int cnt[N];

int old[N];
int cyc[N];

int doc[N];
int dpc[N];

/*
struct Matrix
{
	int n, m;
	intl num[101][101];
	Matrix() { }
	Matrix(int n, int m) : n(n), m(m)
	{
		memset(num, 0, sizeof(num));
		for(int i = 0; i < min(n, m); i ++)
			num[i][i] = 1;
	}
	Matrix operator *(const Matrix &rhs) const
	{
		Matrix ret(n, rhs.m);
		for(int i = 0; i < ret.n; i ++)
			for(int j = 0; j < ret.m; j ++)
			{
				ret.num[i][j] = 0;
				for(int k = 0; k < m; k ++)
				{
					ret.num[i][j] += num[i][k] * rhs.num[k][j];
					ret.num[i][j] %= Mod;
				}
			}
		return ret;
	}
};
*/

struct Vector
{
	int n;
	intl v[101];
	Vector() { }
	Vector(int n) : n(n)
	{
		for(int i = 1; i < n; i ++)
			v[i] = 0;
		v[0] = 1;
	}
	Vector operator *(const Vector &rhs) const
	{
		Vector ret(n);
		for(int i = 0; i < n; i ++)
			ret.v[i] = 0;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
			{
				ret.v[(i + j) % n] += v[i] * rhs.v[j];
				ret.v[(i + j) % n] %= Mod;
			}
		return ret;
	}
};

/*
Matrix qpow(Matrix A, int b)
{
	Matrix ret(A.n, A.m);
	Matrix tmp = A;
	while(b > 0)
	{
		if(b & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
		b >>= 1;
	}
	return ret;
}
*/

Vector qpow(Vector A, int b)
{
	Vector ret(A.n);
	Vector tmp = A;
	while(b > 0)
	{
		if(b & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
		b >>= 1;
	}
	return ret;
}

intl dp[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, b, k, x;
	cin >> n >> b >> k >> x;
	for(int i = 0; i < n; i ++)
	{
		int t;
		cin >> t;
		t %= x;
		cnt[t] ++;
	}
	memset(old, -1, sizeof(old));
	old[1] = 0;
	cyc[0] = 1;
	int tmp = 1;
	int start, cycle;
	for(int i = 1; ; i ++)
	{
		tmp *= 10;
		tmp %= x;
		cyc[i] = tmp;
		//cout << i << ' ' << tmp << '\n';
		if(old[tmp] != -1)
		{
			cycle = i - old[tmp];
			start = old[tmp];
			break;
		}
		old[tmp] = i;
	}

	for(int i = start; i < start + cycle; i ++)
		doc[cyc[i]] ++;

	//cout << cycle << ' ' << start << '\n';

	if(b > 400)
	{
		for(int i = 0; i < x; i ++)
			dpc[i] += (b - 300) / cycle * doc[i];
		b -= (b - 300) / cycle * cycle;
	}
	tmp = 1;
	for(int i = 0; i < b; i ++)
	{
		dpc[tmp] ++;
		tmp *= 10;
		tmp %= x;
	}
	/*
	for(int i = 0; i < x; i ++)
		cout << i << ' ' << dpc[i] << '\n';
	*/
	/*
	Matrix step(x, x);
	for(int i = 0; i < x; i ++)
		for(int j = 0; j < x; j ++)
			step.num[i][j] = cnt[(j - i + x) % x];
	Matrix S(x, 1);
	S.num[0][0] = 1;
	*/

	Vector S(x);

	//dp[0][0] = 1;
	for(int i = 0; i < x; i ++)
	{
		/*
		Matrix T = qpow(step, dpc[i]) * S;
		for(int j = 0; j < x; j ++)
			if(T.num[j][0] != 0)
			{
				cout << i << ' ' << j << ' ' << T.num[j][0] << '\n';
			} 
		*/
		Vector step(x);
		step.v[0] = 0;
		for(int j = 0; j < x; j ++)
			step.v[(i * j) % x] += cnt[j];
		
		/*
		for(int j = 0; j < x; j ++)
			for(int k = 0; k < x; k ++)
			{
				dp[i + 1][(j + k * i) % x] += T.num[k][0] * dp[i][j];
				dp[i + 1][(j + k * i) % x] %= Mod;
			}
		*/
		/*
		for(int j = 0; j < x; j ++)
			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		*/
		S = S * qpow(step, dpc[i]);
	}
	cout << S.v[k] << '\n';
	return 0;
}