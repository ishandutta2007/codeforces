
 #include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Max = 5e5 + 5, Mod = 998244353;
ll n, k, a[22], b[22], dp[22][22][22];
int OP, CL;
ll Try(int i, int op, int cl)
{
	if (op < 0)
		cl++, op = 0;
	if (i == n)
		return (op == OP && cl == CL ? 0 : 1e16);
	ll& ret = dp[i][op][cl];
	if (ret + 1)
		return ret;
	ll c1 = Try(i + 1, op + 1, cl) + a[i];
	ll c2 = Try(i + 1, op - 1, cl) + b[i];
	return ret = min({ (ll)1e16,c1,c2 });
}
typedef vector<vector<ll>> matrix;
int m;
matrix init(ll x)
{
	return matrix(m, vector<ll>(m, x));
}
matrix mult(matrix& a, matrix& b)
{
	matrix Res = init(1e15);
	for (int i = 0; i < m; i++)
		for (int k = 0; k < m; k++)
			for (int j = 0; j < m; j++)
				Res[i][j] = min(Res[i][j], a[i][k] + b[k][j]);
	return Res;
}
matrix fp(matrix& x, ll p)
{
	if ( p== 1 )
		return x;
	matrix y = fp(x, p >> 1);
	y = mult(y, y);
	if (p & 1)
		y = mult(y, x);
	return y;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (n == 1)
	{
		a[n] = a[0];
		b[n] = b[0];
		n++;
		k /= 2;
	}
	vector<pair<int, int>> v;
	m = 2 * n+1;
	matrix T = init(1e16);
	for(int i=0;i<m;i++)
    {
		for (int j=0;j<=n;j++)
		{
		    for (int k=0;k<=n;k++)
            {
                OP = j;
                CL = k;
                int jj = i - CL + OP;
                if (i-CL>=0 && jj<m && jj >= 0 )
                {
                    memset(dp, -1, sizeof(dp));
                    T[i][jj] = min(T[i][jj],Try(0, 0, 0));
                }
			}
		}
    }
	T = fp(T, k);
	cout << T[0][0] << endl;
	return 0;
}