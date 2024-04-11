#include<bits/stdc++.h>
using namespace std;
int T , n , m , h[110000] , a , b , flag , num[110000] , sum[110000];
int nex[220000] , fst[220000] , v[220000] , val[110000] , sval[110000] , tot;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
	return ;
}
void dfs1( int u , int fa )
{
	sval[u] = val[u];
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs1(v[i] , u);
		sval[u] += sval[v[i]];
	}
	return ;
}
void dfs2( int u , int fa )
{
	int t = 0;
	sum[u] = val[u];
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		t++;
		dfs2(v[i] , u);
		sum[u] += num[v[i]];
	}
//	cerr << u << ' ' << sum[u] << ' ' << num[u] << endl;
	if(sum[u] < num[u]) flag = 1;
	return ;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &val[i]);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &h[i]);
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d" , &a , &b);
			add(a , b); add(b , a);
		}
		dfs1(1 , 1);
//		for(int i = 1 ; i <= n ; i++ ) cerr << val[i] << ' ';
		for(int i = 1 ; i <= n ; i++ )
		{
			if(h[i] < 0) num[i] = -h[i];
			else num[i] = 0;
			int qwq = sval[i] - abs(h[i]);
			if(qwq % 2 != 0 || abs(h[i]) > sval[i]) 
			{
				flag = 1;
				break;
			}
			num[i] += qwq / 2;
		}
		if(flag == 1)
		{
			for(int i = 1 ; i <= n ; i++ ) fst[i] = 0;
			tot = flag = 0;
			printf("NO\n");
			continue;
		}
//		cerr << 111111;
		dfs2(1 , 1);
		if(flag == 1)
		{
			for(int i = 1 ; i <= n ; i++ ) fst[i] = 0;
			tot = flag = 0;
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 1 ; i <= n ; i++ ) fst[i] = 0;
		tot = flag = 0;
	}
	return 0;
}