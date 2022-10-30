#include <bits/stdc++.h>
using namespace std;
int n , m , tot , id[110000] , cnt , l , r , k;
int dfn[110000] , dfo[110000] , pnt[110000] , fa[110000];
long long lans[200][110000] , ans[110000] , sum[330] , val[110000];
string s[110000];
char adjhsk[110000];
vector< int > son[110000] , idp[110000];
const int B = 330;
struct item
{
	int ch[30] , fail , num;
	vector< int > id;
} node[110000];
struct query
{
	int r , k , id , val;
	bool operator < ( const query &x ) const
	{
		return r < x.r;
	}
} q[220000];
void insert( string s , int id )
{
	int u = 1;
	for(int i = 0 ; i < s.size() ; i++ ) 
	{
		if(!node[u].ch[s[i] - 'a']) node[u].ch[s[i] - 'a'] = ++tot;
		u = node[u].ch[s[i] - 'a'];
		if(s.size() < 500) idp[id].push_back(u);
	}
	node[u].id.push_back(id); pnt[id] = u;
}
void getfail()
{
	queue< int > q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int j = 0 ; j < 26 ; j++ )
		{
			if(!node[u].ch[j]) node[u].ch[j] = node[node[u].fail].ch[j];
			else node[node[u].ch[j]].fail = node[node[u].fail].ch[j] , q.push(node[u].ch[j]);
		}
	}
	for(int i = 1 ; i <= tot ; i++ ) son[node[i].fail].push_back(i) , fa[i] = node[i].fail;
	return ;
}
void mark( string s )
{
	int u = 1;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		u = node[u].ch[s[i] - 'a']; 
		node[u].num++;
	}
}
void dfs( int u , int id )
{
	dfn[u] = ++cnt; 
	for(int i = 0 ; i < son[u].size() ; i++ ) dfs(son[u][i] , id);
	dfo[u] = cnt;
	node[fa[u]].num += node[u].num;
	for(int i = 0 ; i < node[u].id.size() ; i++ ) lans[id][node[u].id[i]] = node[u].num;
}
void add( int l , int r )
{
	int L = l / B , R = r / B;
	for(int i = L + 1 ; i < R ; i++ ) sum[i]++;
	if(L != R)
	{
		for(int i = l ; i < (L + 1) * B ; i++ ) val[i]++;
		for(int i = R * B ; i <= r ; i++ ) val[i]++;
	}
	else for(int i = l ; i <= r ; i++ ) val[i]++;
}
long long ask( int x )
{
//	cerr << "ask: " << ' ' << x << ' ' << val[x] << endl;
	return sum[x / B] + val[x];
}
int main()
{
	tot = 1; node[1].fail = 0; 
	for(int i = 0 ; i < 26 ; i++ ) node[0].ch[i] = 1;
	scanf("%d%d" , &n , &m);  
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%s" , adjhsk) , s[i] = adjhsk , insert(s[i] , i);
		if(s[i].size() >= 500) id[i] = ++cnt;
	}
	getfail();
	for(int i = 1 ; i <= n ; i++ )
	{
		if(!id[i]) continue;
		mark(s[i]);
		cnt = 0; dfs(1 , id[i]);
		for(int j = 1 ; j <= n ; j++ ) lans[id[i]][j] += lans[id[i]][j - 1];
		for(int j = 1 ; j <= tot ; j++ ) node[j].num = 0;
	}
	cnt = 0; dfs(1 , 0); cnt = 0;
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &l , &r , &k);
		if(!id[k])
		{
			if(l != 1) q[++cnt] = (query){l - 1 , k , i , -1}; 
			q[++cnt] = (query){r , k , i , 1}; 
		}
		else ans[i] = lans[id[k]][r] - lans[id[k]][l - 1];
	}
	sort(q + 1 , q + cnt + 1); int it = 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		add(dfn[pnt[i]] , dfo[pnt[i]]);
//		cerr << "edit: " << dfn[pnt[i]] << ' ' << dfo[pnt[i]] << endl;
		while(q[it].r == i)
		{
//			cerr << q[it].k << ": ";
			for(int j : idp[q[it].k] ) ans[q[it].id] += q[it].val * ask(dfn[j]);
			it++;
		}
	}
	for(int i = 1 ; i <= m ; i++ ) printf("%lld\n" , ans[i]);
	return 0;
}
/*

*/