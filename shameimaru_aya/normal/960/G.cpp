#include<bits/stdc++.h>
using namespace std;
int n , a , b;
long long rev[440000] , fac[440000] , inv[440000] , inc[440000];
const int mod = 998244353 , g = 3 , invg = 332748118;
void init()
{
	fac[0] = fac[1] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 2 ; i <= 400000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 400000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 400000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
long long exp( long long a , long long b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod; b >>= 1;
	}
	return ans % mod;
}
long long C( int a , int b )
{
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
void NTT( vector< long long > &a , int len , int w )
{
	for(int i = 0 ; i < len ; i++ ) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
	for(int i = 0 ; i < len ; i++ )
		if(i < rev[i]) swap(a[i] , a[rev[i]]);
	for(int hlf = 1 ; hlf < len ; hlf <<= 1 )
	{
		long long wn = exp(w , (mod - 1) / (hlf << 1));
		for(int i = 0 ; i < len ; i += hlf << 1 )
		{
			long long w = 1;
			for(int j = i ; j < i + hlf ; j++ )
			{
				long long x = a[j] , y = w * a[j + hlf] % mod;
				a[j] = (x + y) % mod; a[j + hlf] = (x - y + mod) % mod;
				w = w * wn % mod;
			}
		}
	}
	return ;
}
void DFT( vector< long long > &a , int len )
{
	NTT(a , len , g);
}
void IDFT( vector< long long > &a , int len )
{
	NTT(a , len , invg);
	long long invl = exp(len , mod - 2);
	for(int i = 0 ; i < len ; i++ ) a[i] = a[i] * invl % mod;
}
struct poly
{
	vector< long long > a;
	poly( int len = 0 ) { a.resize(len); }
	int size() { return a.size(); }
	friend poly operator + ( poly x , poly &y )
	{
		int siz = max(x.size() , y.size());
		poly ans(siz);
		for(int i = 0 ; i < siz ; i++ ) ans.a[i] = (x.a[i] + y.a[i]) % mod;
		return ans;
	}
	friend poly operator - ( poly x , poly &y ) 
	{
		int siz = max(x.size() , y.size());
		poly ans(siz);
		for(int i = 0 ; i < siz ; i++ ) 
			ans.a[i] = x.a[i] - y.a[i] , ans.a[i] = ans.a[i] < 0 ? ans.a[i] + mod : ans.a[i];
		for(int i = siz - 1 ; i >= 0 ; i-- ) 
		{
			if(ans.a[i])
			{
				ans.a.resize(i + 1);
				break;
			}
		}
		return ans;
	}
	friend poly operator * ( poly x , poly y )
	{
		int siz = x.size() + y.size() - 1 , len = 1 << ((int)log2(siz - 1) + 1);
//		cerr << x.size() << ' ' << y.size() << ' ' << siz << ' ' << len << endl;
		poly ans(len);
		x.a.resize(len) , y.a.resize(len);
		DFT(x.a , len); DFT(y.a , len); 
		for(int i = 0 ; i < len ; i++ ) ans.a[i] = x.a[i] * y.a[i] % mod;
		IDFT(ans.a , len);
		ans.a.resize(siz);
		return ans;
	}
	poly & operator += ( poly y )
	{
		return (*this) = (*this) + y;
	}
	poly & operator -= ( poly y )
	{
		return (*this) = (*this) - y;
	}
	poly & operator *= ( poly y )
	{
		return (*this) = (*this) * y;
	}
} F[20] , G , qwq1 , qwq2 , ans;
void move( poly &F , poly &ans , int m )
{
	qwq1.a.resize(F.size()); qwq2.a.resize(F.size()); long long s = 1;
	for(int j = 0 ; j < F.size() ; j++ ) 
	{
		qwq1.a[F.size() - j - 1] = s * inc[j] % mod;
		s = s * m % mod;
	}
	for(int j = 0 ; j < F.size() ; j++ ) qwq2.a[j] = F.a[j] * fac[j] % mod;
	ans = qwq1 * qwq2;
	for(int j = 0 ; j < F.size() ; j++ ) ans.a[j] = ans.a[j + F.size() - 1] * inc[j] % mod;
	ans.a.resize(F.size());
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	init();
//	n = 10;
//	G.a.resize(10); G.a[1] = 1; G.a[2] = 2;
//	move(G , ans , 3);
//	for(int i = 0 ; i < 3 ; i++ ) cerr << ans.a[i] << ' '; cerr << endl;
//	while(1);
	
	scanf("%d%d%d" , &n , &a , &b);
	if(a + b > n + 1 || a + b < 2 || a < 1 || b < 1)
	{
		printf("0\n");
		return 0;
	}
	F[0].a.resize(2); F[0].a[1] = 1;
	for(int i = 1 ; i <= 17 ; i++ )
	{
		move(F[i - 1] , F[i] , 1 << i - 1);
		F[i] = F[i] * F[i - 1]; 
		if(i >= 5) continue;
//		for(int j = 0 ; j < F[i].size() ; j++ ) cerr << F[i].a[j] << ' '; cerr << endl;
//		cerr << F[i].size() << endl;
	}
	int s = 0;
	ans.a.resize(n + 1); ans.a[0] = 1;
	for(int i = 0 ; i <= 17 ; i++ )
	{
		if(((n - 1) >> i) & 1) 
		{
			move(F[i] , G , s);
			ans = ans * G; //ans.a.resize(n + 1);
			s += (1 << i);
		}
	}
//	for(int i = 0 ; i <= 4 ; i++ ) cerr << F[2].a[i] << ' '; cerr << endl;
	printf("%lld" , ans.a[a + b - 2] * C(a + b - 2 , a - 1) % mod);
    return 0;
}
/*
2
1 2
*/