#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n , m , x;
long long rev[4400000] , a[110000] , sp[110000] , pre[110000] , suf[110000] , p2[110000] , ans;
const int mod = 998244353 , g = 3 , invg = 332748118;
LL exp( LL a , LL b )
{
	LL ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod;
		b >>= 1;
	}
	return ans % mod;
}
void NTT( vector< long long > &a , int len , int k )
{
	a.resize(len); 
	for(int i = 0 ; i < len ; i++ ) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
	for(int i = 0 ; i < len ; i++ )
		if(i < rev[i]) swap(a[i] , a[rev[i]]);
	for(int hlf = 1 ; hlf < len ; hlf <<= 1 )
	{
		long long wn = exp(k , (mod - 1) / (hlf << 1));
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
}
void DFT( vector< long long > &a , int len )
{
	NTT(a , len , g);
}
void IDFT( vector< long long > &a , int len )
{
	long long invl = exp(len , mod - 2);
	NTT(a , len , invg);
	for(int i = 0 ; i < len ; i++ ) a[i] = a[i] * invl % mod;
}
struct poly
{
	vector< long long > a; int len;
	void init( int x )
	{
		a.resize(x); len = x;
	}
	poly get( int l , int r )
	{
		poly ans; ans.len = r - l + 1; 
		ans.a = vector< long long >(a.begin() + l , a.begin() + r + 1);
		return ans;
	}
	poly operator * ( const poly &x ) const
	{
		poly ans; int qwq = len + x.len - 1;
		vector< long long > c = a , d = x.a;
		int siz = 1 << ((int)log2(qwq) + 1); ans.init(siz);
//		cerr << qwq << ' ' << siz << endl;
		DFT(c , siz); DFT(d , siz);
		for(int i = 0 ; i < siz ; i++ ) ans.a[i] = c[i] * d[i] % mod;
		IDFT(ans.a , siz); ans.init(qwq);
		return ans;
	}
} F , G , H;
void divide( int l , int r ) //F > G
{
	if(l == r || l > n) return ;
	int mid = l + r >> 1;
	poly gl = G.get(l , mid) , gr = F.get(mid + 1 , r);
//	cerr << gl.len << ' ' << gr.len << endl;
	gl = gl * gr;
	for(int i = 0 ; i < gl.len ; i++ )
	{
		int j = i + l + mid + 1;
		(H.a[j] += gl.a[i]) %= mod;
	}
	divide(l , mid); divide(mid + 1 , r);
}
void solve( int f )
{
	pre[0] = suf[n + 1] = 1;
	for(int i = 1 ; i <= n ; i++ ) pre[i] = pre[i - 1] * (sp[i] + 1) % mod;
	for(int i = n ; i >= 1 ; i-- ) suf[i] = suf[i + 1] * (sp[i] + 1) % mod;
//	for(int i = 1 ; i <= n ; i++ ) cerr << pre[i] << ' '; cerr << endl;
//	for(int i = 1 ; i <= n ; i++ ) cerr << suf[i] << ' '; cerr << endl;
	
	for(int i = 1 ; i <= n ; i++ ) F.a[i] = suf[i + f];
	for(int i = n + 1 ; i <= 2 * n ; i++ ) F.a[i] = 1;
	for(int i = 1 ; i <= n ; i++ ) G.a[i] = sp[i] * pre[i - 1] % mod;
	divide(1 , 2 * n);
	for(int i = 2 ; i <= 2 * n ; i += 2 )
	{
//		cerr << H.a[i] << ' ';
		(ans += H.a[i] * (i / 2) % mod * a[i / 2] % mod) %= mod;
		H.a[i] = 0;
	}
//	cerr << endl;
	
	for(int i = 1 ; i <= n ; i++ ) G.a[i] = sp[i] * pre[i - 1] % mod * i % mod;
	divide(1 , 2 * n);
	for(int i = 2 ; i <= 2 * n ; i += 2 )
	{
//		cerr << H.a[i] << ' ';
		(ans += mod - H.a[i] * a[i / 2] % mod) %= mod;
		H.a[i] = 0;
	}
//	cerr << endl;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	p2[0] = 1; F.init(210000); G.init(210000); H.init(410000); 
	for(int i = 1 ; i <= 100000 ; i++ ) p2[i] = p2[i - 1] * 2 % mod;
	
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &a[i]);
	for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &x) , sp[x] = 1;
	solve(0);
	reverse(a + 1 , a + n + 1); reverse(sp + 1 , sp + n + 1);
	solve(1);
//	cerr << ans << endl;
	printf("%lld" , ans * exp((p2[m] - 1 + mod) , mod - 2) % mod);
    return 0;
}
/*
*/