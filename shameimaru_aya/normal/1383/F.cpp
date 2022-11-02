#include<bits/stdc++.h>
using namespace std;
int n , m , q , k , x , y , z , ans , s , t , K , flag;
int w[20] , dis[11000] , f[1 << 10] , lg[1 << 10] , r[1 << 10];
/* ---- read() & rlong() - begin ---- */
#define gc() (p0==p1&&(p1=(p0=buf)+fread(buf,1,1048576,stdin),p0==p1)?EOF:*p0++)
char buf[1048576],*p0,*p1;
inline int read() {
int r=0; char c=gc(); while (c<48||c>57) c=gc();
while (c>47&&c<58) {r=(r<<3)+(r<<1)+(c^48); c=gc();} return r;
}
#undef gc
/* ---- read() & rlong() -- end ----- */
struct data
{
	int u , v;
} E[20];
inline int MIN( int a , int b )
{
	return (a < b ? a : b);
}
struct G
{
	short fst[10001] , nex[20200] , v[20200] , noww[10001] , vis[10001] , tot = 1;
	int mf , val[20200];
	queue< int > q;
	inline void add( int a , int b , int c )
	{
		nex[++tot] = fst[a] , fst[a] = tot;
		v[tot] = b , val[tot] = c;
		nex[++tot] = fst[b] , fst[b] = tot;
		v[tot] = a , val[tot] = 0;
		return ;
	}
	bool bfs()
	{
		bool flag = false;
		q = queue< int >();
		q.push(s); dis[s] = 1;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			if(u == t) flag = true;
			for(int i = fst[u] ; i ; i = nex[i] )
			{
				if(val[i] && !dis[v[i]])
				{
	//				cerr << u << ' ' << v[i] << endl;
					dis[v[i]] = dis[u] + 1;
					q.push(v[i]);
				}
			}
		}
		return flag;
	}
	int dfs( int u , int flow )
	{
		if(u == t)
		{
			mf += flow;
			return flow;
		}
		int sum = 0;
		for( ; noww[u] ; noww[u] = nex[noww[u]] )
		{
			int i = noww[u];
			if(val[i] && dis[v[i]] == dis[u] + 1)
			{
				int qwq = dfs(v[i] , MIN(val[i] , flow));
				val[i] -= qwq; val[i ^ 1] += qwq;
				flow -= qwq; sum += qwq;
				if(flow < 1e-6) return sum;
			}
		}
		return sum;
	}
	void dinic()
	{
		memset(dis , 0 , sizeof(dis));
		while(bfs())
		{
			memcpy(noww , fst , sizeof(noww));
			dfs(s , 1e9);
			memset(dis , 0 , sizeof(dis));
		}
	}
	int dfs2( int u , int flow )
	{
		if(u == t)
		{
			mf += flow; flag = 1;
			return flow;
		}
		vis[u] = 1;
		for(int i = fst[u] ; i && !flag ; i = nex[i] )
		{
			if(val[i] && !vis[v[i]])
			{
				int qwq = dfs2(v[i] , MIN(val[i] , flow));
				if(flag)
				{
					val[i] -= qwq; val[i ^ 1] += qwq;
					return qwq;
				}
			}
		}
		return 0;
	}
	void FF()
	{
		memset(vis , 0 , sizeof(vis));
		flag = 0; dfs2(s , 1e9);
		while(flag)
		{
			memset(vis , 0 , sizeof(vis));
			flag = 0; dfs2(s , 1e9);
		}
		return ;
	}
} g[1 << 10];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	lg[1] = 1; lg[2] = 2; lg[4] = 3; lg[8] = 4; lg[16] = 5;
	lg[32] = 6; lg[64] = 7; lg[128] = 8; lg[256] = 9; lg[512] = 10;
	n = read() , m = read() , k = read() , q = read(); s = 1; t = n; K = (1 << k) - 1;
	for(int i = 0 ; i <= K ; i++ ) r[i] = i ^ K;
	for(int i = 1 ; i <= m ; i++ )
	{
		x = read() , y = read() , z = read();
		if(i <= k) E[i].u = x , E[i].v = y;
		if(i > k) g[0].add(x , y , z);
	}
	g[0].dinic(); f[0] = 1;
	for(int i = 0 ; i <= K ; i++ )
	{
		for(int j = 1 ; j <= k ; j++ )
		{
			int msk = i | (1 << j - 1);
			if(!f[msk])
			{
				f[msk] = 1; g[msk] = g[i];
				g[msk].add(E[j].u , E[j].v , 25);
				g[msk].FF();
			}
		}
	}
	while(q--)
	{
		ans = 1e9;
		for(int i = 1 ; i <= k ; i++ ) w[i] = read();
		for(int i = 1 ; i <= K ; i++ )
		{
			int lm = (i - 1) & i;
			f[i] = f[lm] + w[lg[lm ^ i]];
		}
		for(int i = 0 ; i <= K ; i++ ) ans = MIN(ans , f[i] + g[r[i]].mf);
		printf("%d\n" , ans - 1);
	}
    return 0;
}
/*

*/