#include<bits/stdc++.h>
using namespace std;
int T , n , m , x , y;
int fst[110000] , nex[220000] , v[220000] , tot;
long long num[110000] , ans , s[110000] , siz[110000] , p[66000];
const int mod = 1e9 + 7;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs( int u , int fa )
{
	siz[u] = 1;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs(v[i] , u);
		siz[u] += siz[v[i]];
		num[(i - 1) / 2 + 1] = siz[v[i]] * (n - siz[v[i]]);
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d" , &x , &y);
			add(x , y); add(y , x);
		}
		scanf("%d" , &m);
		for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &p[i]);
		sort(p + 1 , p + m + 1); reverse(p + 1 , p + m + 1);
		dfs(1 , 1);
		sort(num + 1 , num + n);
		for(int i = 1 ; i < n - 1 ; i++ )
		{
//			cerr << num[i] << ' ';
			if(m >= n - i) ans = (ans + num[i] % mod * p[m]) % mod , m--;
			else ans = (ans + num[i] % mod) % mod;
		}
//		cerr << num[n - 1] << '\n';
		long long qwq = num[n - 1] % mod;
		while(m) 
		{
			qwq = qwq * p[m] % mod;
			m--;
		}
		ans = (ans + qwq) % mod;
		printf("%d\n" , ans);
		tot = ans = 0;
		for(int i = 1 ; i <= n ; i++ ) fst[i] = 0;
	}
    return 0;
}