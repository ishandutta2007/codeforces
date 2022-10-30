#include <bits/stdc++.h> 
using namespace std;
int n , m , a[220000] , tot = 1;
long long p2[220000];
const int mod = 998244353;
struct item
{
	long long num , ch[2];
} t[220000 * 30];
void insert( int k )
{
	int u = 1; t[u].num++;
	for(int i = 29 ; i >= 0 ; i-- )
	{
		int c = (k >> i) & 1; 
		if(!t[u].ch[c]) t[u].ch[c] = ++tot;
		u = t[u].ch[c]; t[u].num++;
	}
}
long long solve2( int u , int v , int x )
{
	if(!u || !v) return 0;
//	cerr << u << ' ' << v << ' ' << x << endl;
	if(x == -1) return (p2[t[u].num] - 1) * (p2[t[v].num] - 1) % mod;
	int c = (m >> x) & 1;
	if(c == 0) 
		return (solve2(t[u].ch[0] , t[v].ch[0] , x - 1) + solve2(t[u].ch[1] , t[v].ch[1] , x - 1)) % mod;
	else
	{
		long long ans = 0 , xx = solve2(t[u].ch[0] , t[v].ch[1] , x - 1) , yy = solve2(t[u].ch[1] , t[v].ch[0] , x - 1);
		ans += xx * yy % mod;
		ans += xx * (p2[t[t[u].ch[1]].num] + p2[t[t[v].ch[0]].num] - 1) % mod;
		ans += yy * (p2[t[t[u].ch[0]].num] + p2[t[t[v].ch[1]].num] - 1) % mod;
		ans += (p2[t[t[u].ch[0]].num] - 1) * (p2[t[t[v].ch[0]].num] - 1) % mod;
		ans += (p2[t[t[u].ch[1]].num] - 1) * (p2[t[t[v].ch[1]].num] - 1) % mod;
		return ans % mod;
	}
}
long long solve( int u , int x )
{
	if(!u) return 0;
//	cerr << u << ' ' << x << endl;
	if(x == -1) return (p2[t[u].num] - 1);
	int c = (m >> x) & 1;
	if(c == 0) 
		return (solve(t[u].ch[0] , x - 1) + solve(t[u].ch[1] , x - 1)) % mod;
	else
		return ((p2[t[t[u].ch[0]].num] - 1) + (p2[t[t[u].ch[1]].num] - 1) + solve2(t[u].ch[0] , t[u].ch[1] , x - 1)) % mod; 
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	p2[0] = 1;
	for(int i = 1 ; i <= 200000 ; i++ ) p2[i] = p2[i - 1] * 2 % mod;
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , insert(a[i]);
	printf("%lld" , solve(1 , 29));
    return 0;
} 
/*
*/