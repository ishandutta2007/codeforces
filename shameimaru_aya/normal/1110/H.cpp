#include <bits/stdc++.h> 
using namespace std;
int n , g[50050][810] , dp[50050][2010] , mx[50050][2010] , tot = 1 , b[55000] , vis[55000] , ans;
string l , r;
struct item
{
	int ch[10] , fail , fl , fr;
} node[110000];
void build()
{
	for(int i = 1 ; i <= 9 ; i++ ) 
	{
		node[1].ch[i] = ++tot; 
		for(int j = l.size() + 1 ; j < r.size() ; j++ ) g[tot][j - 1] = 1;
		if(i == l[0] && l.size() != 1) node[tot].fl = 1;
		if(i == r[0] && r.size() != 1) node[tot].fr = 1;
	}
	node[1].fl = node[1].fr = 1; b[1] = -1;
	queue< int > q; q.push(1);
	while(!q.empty())
	{
		int u = q.front() , pl = b[u] + 1; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		if(node[u].fl && !node[u].fr)
		{
			for(int i = l[pl] + 1 ; i <= 9 ; i++ ) 
			{
				if(!node[u].ch[i]) node[u].ch[i] = ++tot;
				g[node[u].ch[i]][l.size() - 1 - pl] = 1;
			}
			if(!node[u].ch[l[pl]]) node[u].ch[l[pl]] = ++tot; 
			int ls = node[u].ch[l[pl]];
			b[ls] = pl; node[ls].fl = 1;
			if(pl == l.size() - 1) g[ls][0] = 1;
			else q.push(ls);
		}
		if(!node[u].fl && node[u].fr)
		{
			for(int i = 0 ; i <= r[pl] - 1 ; i++ ) 
			{
				if(!node[u].ch[i]) node[u].ch[i] = ++tot;
				g[node[u].ch[i]][r.size() - 1 - pl] = 1;
			}
			if(!node[u].ch[r[pl]]) node[u].ch[r[pl]] = ++tot; 
			int rs = node[u].ch[r[pl]];
			b[rs] = pl; node[rs].fr = 1;
			if(pl == r.size() - 1) g[rs][0] = 1;
			else q.push(rs);
		}
		if(node[u].fl && node[u].fr)
		{
			if(l.size() != r.size())
			{
				for(int i = 0 ; i <= 9 ; i++ )
					if(!node[u].ch[i]) node[u].ch[i] = ++tot;
				if(pl < l.size())
				{
					for(int i = 0 ; i <= 9 ; i++ )
						if(i > l[pl]) g[node[u].ch[i]][l.size() - 1 - pl] = 1;
					int ls = node[u].ch[l[pl]];
					b[ls] = pl; node[ls].fl = 1;
					if(pl == l.size() - 1) g[ls][0] = 1;
					else q.push(ls);
				}
				
				if(pl < r.size())
				{				
					for(int i = 0 ; i <= 9 ; i++ )
						if(i < r[pl] && (i || pl)) g[node[u].ch[i]][r.size() - 1 - pl] = 1;
					int rs = node[u].ch[r[pl]];
					b[rs] = pl; node[rs].fr = 1;
					if(pl == r.size() - 1) g[rs][0] = 1;
					else q.push(rs);
				}
			}
			else
			{
				for(int i = l[pl] + 1 ; i < r[pl] ; i++ )
				{
					if(!node[u].ch[i]) node[u].ch[i] = ++tot;
					g[node[u].ch[i]][l.size() - 1 - pl] = 1;
				}
				
				if(!node[u].ch[l[pl]]) node[u].ch[l[pl]] = ++tot; 
				int ls = node[u].ch[l[pl]];
				b[ls] = pl; node[ls].fl = 1;
				if(pl == l.size() - 1) g[ls][0] = 1;
				else q.push(ls);
				
				if(!node[u].ch[r[pl]]) node[u].ch[r[pl]] = ++tot; 
				int rs = node[u].ch[r[pl]];
				b[rs] = pl; node[rs].fr = 1;
				if(pl == r.size() - 1) g[rs][0] = 1;
				else q.push(rs);
			}
		}
	}
}
void getfail()
{
	queue< int > q; q.push(1);
	memset(vis , 0 , sizeof(vis));
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0 ; i < 10 ; i++ )
		{
			if(node[u].ch[i] && !vis[node[u].ch[i]])
			{
				q.push(node[u].ch[i]); node[node[u].ch[i]].fail = node[node[u].fail].ch[i];
				for(int j = 0 ; j <= r.size() ; j++ ) 
					g[node[u].ch[i]][j] += g[node[node[u].ch[i]].fail][j];
			}
			else node[u].ch[i] = node[node[u].fail].ch[i];
		}
	}
	return ;
}
void print()
{
	int u = 1;
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j <= 9 ; j++ ) 
		{
			if(mx[u][i] == mx[node[u].ch[j]][i + 1]
			&& dp[node[u].ch[j]][i + 1] == dp[u][i] + g[node[u].ch[j]][min((int)r.size() , n - i - 1)]) 
			{
				printf("%d" , j);
				u = node[u].ch[j]; 
				break;
			}
		}
	}
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	cin >> l >> r >> n; node[1].fail = 0; node[1].ch[0] = 1;
	for(int i = 0 ; i <= 9 ; i++ ) node[0].ch[i] = 1;
	for(int i = 0 ; i < l.size() ; i++ ) l[i] -= '0';
	for(int i = 0 ; i < r.size() ; i++ ) r[i] -= '0';
	build(); 
	getfail();
	memset(dp , -0x7f / 3 , sizeof(dp));
	dp[1][0] = 0;
	for(int i = 1 ; i <= tot ; i++ )
		for(int j = 1 ; j <= r.size() ; j++ ) g[i][j] += g[i][j - 1];
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= tot ; j++ )
		{
			for(int k = 0 ; k <= 9 ; k++ )
			{
				dp[node[j].ch[k]][i] = max(dp[node[j].ch[k]][i] , dp[j][i - 1] + g[node[j].ch[k]][min((int)r.size() , n - i)]);
				ans = max(ans , dp[node[j].ch[k]][i]);
			}
		}
	}
	for(int j = 1 ; j <= tot ; j++ ) mx[j][n] = dp[j][n];
	for(int i = n - 1 ; i >= 0 ; i-- )
	{
		for(int j = 1 ; j <= tot ; j++ )
		{
			if(dp[j][i] < 0) continue;
			for(int k = 0 ; k <= 9 ; k++ )
				if(dp[node[j].ch[k]][i + 1] == dp[j][i] + g[node[j].ch[k]][min((int)r.size() , n - i - 1)])
					mx[j][i] = max(mx[j][i] , mx[node[j].ch[k]][i + 1]);
		}
	}
	printf("%d\n" , ans); print();
	return 0;
}
/*
3
427
5
*/