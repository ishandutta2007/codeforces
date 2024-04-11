#include <bits/stdc++.h>
using namespace std;
int n , a[220000] , x , y , rt , du[220000] , maxx[220000];
int fst[220000] , nex[440000] , v[440000] , tot;
long long ans;
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs( int u , int fa )
{
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs(v[i] , u);
		maxx[u] = max(maxx[u] , maxx[v[i]]);
	}
	if(maxx[u] < a[u]) ans += a[u] - maxx[u] , maxx[u] = a[u];
}
int main() 
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , rt = (a[rt] < a[i] ? i : rt);
	for(int i = 1 ; i < n ; i++ ) 
		scanf("%d%d" , &x , &y) , add(x , y) , add(y , x) , du[x]++ , du[y]++;
	if(du[rt] == 1) ans += a[rt];
	dfs(rt , rt);
	if(du[rt] != 1)
	{
		int f = 0 , mx = 0 , sc = 0;
		for(int i = fst[rt] ; i ; i = nex[i] ) mx = max(mx , maxx[v[i]]);
		for(int i = fst[rt] ; i ; i = nex[i] )
		{
			if(maxx[v[i]] == mx)
			{
				if(f) sc = mx;
				else f = 1;
			} 
			else sc = max(sc , maxx[v[i]]);
		}
		ans += a[rt] - sc;
	}
	printf("%lld" , ans);
	
    return 0; 
}
/*
*/