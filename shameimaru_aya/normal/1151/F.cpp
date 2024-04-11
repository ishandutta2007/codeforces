#include <bits/stdc++.h> 
using namespace std;
int n , k , s[110] , r , t , a , b;
const int mod = 1e9 + 7;
struct matrix
{
	int r , c; long long a[60][60];
	matrix operator * ( const matrix &x ) const
	{
		matrix ans; ans.r = r; ans.c = x.c;
		for(int i = 0 ; i <= r ; i++ )
		{
			for(int j = 0 ; j <= x.r ; j++ )
			{
				ans.a[i][j] = 0;
				for(int k = 0 ; k <= c ; k++ )
				{
					ans.a[i][j] += a[i][k] * x.a[k][j] % mod;
					if(ans.a[i][j] >= mod) ans.a[i][j] -= mod;
				}
			}
		}
		return ans;
	}
} B , E , A;
matrix exp( matrix a , int b )
{
	matrix ans = E , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t;
		t = t * t; b >>= 1;
	}
	return ans;
}
long long exp( int a , int b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod; b >>= 1;
	}
	return ans;
}
int main()
{
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &s[i]) , r += s[i];
	a = n - r , b = r; r = min(r , n - r);
	for(int i = 1 ; i <= a ; i++ ) t += s[i];
	A.r = 0; A.c = r; A.a[0][t] = 1;
	B.r = B.c = E.r = E.c = r;
	for(int i = 0 ; i <= r ; i++ ) B.a[i][i] = E.a[i][i] = 1;
	for(int i = 0 ; i <= r ; i++ )
	{
		if(i != r) 
		{
			B.a[i + 1][i] = 2 * (i + 1) * (i + 1) * exp(a + b , mod - 2) % mod * exp(a + b - 1 , mod - 2) % mod;
			B.a[i + 1][i + 1] = (B.a[i + 1][i + 1] - B.a[i + 1][i] + mod) % mod;
		}
		if(i != 0) 
		{
			B.a[i - 1][i] = 2 * (a - i + 1) * (b - i + 1) * exp(a + b , mod - 2) % mod * exp(a + b - 1 , mod - 2) % mod;
			B.a[i - 1][i - 1] = (B.a[i - 1][i - 1] - B.a[i - 1][i] + mod) % mod;
		}
	}
//	for(int i = 0 ; i <= r ; i++ )
//	{
//		for(int j = 0 ; j <= r ; j++ ) cerr << B.a[i][j] << ' ';
//		cerr << endl;
//	}
	B = exp(B , k);
	A = A * B;
	cout << A.a[0][0];
	return 0;
}
/*
3 1
0 0 10
*/