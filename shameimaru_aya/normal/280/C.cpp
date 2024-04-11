#include<bits/stdc++.h>
using namespace std;
int n , x , y , dep[110000];
int fst[110000] , v[220000] , nex[220000] , tot;
double ans;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs( int u , int fa )
{
	dep[u] = dep[fa] + 1;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs(v[i] , u);
	}
	return ;
}
int main()
{
	scanf("%d" ,&n);
	for(int i = 1 ; i < n ; i++ )
	{
		scanf("%d%d" , &x , &y);
		add(x , y); add(y , x);
	}
	dfs(1 , 1);
	for(int i = 1 ; i <= n ; i++ ) ans += (long double)1 / dep[i];
	printf("%.7f" , ans);
    return 0;
}