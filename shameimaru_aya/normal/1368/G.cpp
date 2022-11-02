#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , dfn[220000] , dfo[220000] , mp[220000] , c[880000] , ccnt[880000];
int fst[220000] , nex[440000] , v[440000] , tot , in[220000] , cnt;
long long ans;
string s;
struct item
{
	long long x , y1 , y2 , val;
	bool operator < ( const item &a ) const
	{
		return x > a.x;
	}
} line[220000];
inline int id( int x , int y )
{
	if(x <= 0 || x > n || y <= 0 || y > m) return -1;
	return (x - 1) * m + y;
}
inline void add( int a , int b )
{
	if(a == -1 || b == -1) return ;
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; in[b]++;
}
void dfs( int u )
{
	dfn[u] = ++tot;
	for(int i = fst[u] ; i ; i = nex[i] ) dfs(v[i]);
	dfo[u] = tot;
	return ;
}
void upd( int l , int r , int L , int R , int a , int id )
{
	if(R < l || r < L) return ;
	if(L <= l && r <= R)
	{
		ccnt[id] += a;
		if(ccnt[id]) c[id] = r - l + 1;
		else
		{
			if(l != r) c[id] = c[lson] + c[rson];
			else c[id] = 0;
		}
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , L , R , a , lson); upd(mid + 1 , r , L , R , a , rson);
	if(ccnt[id]) c[id] = r - l + 1;
	else c[id] = c[lson] + c[rson];
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		cin >> s;
		for(int j = 1 ; j <= m ; j++ )
		{
			if(s[j - 1] == 'U') mp[id(i , j)] = 1 , add(id(i + 2 , j) , id(i , j));
			if(s[j - 1] == 'D') mp[id(i , j)] = 2 , add(id(i - 2 , j) , id(i , j));
			if(s[j - 1] == 'L') mp[id(i , j)] = 3 , add(id(i , j + 2) , id(i , j));
			if(s[j - 1] == 'R') mp[id(i , j)] = 4 , add(id(i , j - 2) , id(i , j));
		}
	}
	tot = 0;
	for(int i = 1 ; i <= n * m ; i++ )
		if(!in[i]) dfs(i);
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ )
		{
			int u = id(i , j);
			if(mp[u] == 1)
			{
				int v = id(i + 1 , j);
				if((i + j) % 2 == 0)
				{
					line[++cnt] = (item){dfn[u] , dfn[v] , dfo[v] , 1};
					line[++cnt] = (item){dfo[u] + 1 , dfn[v] , dfo[v] , -1};
				}
				else
				{
					line[++cnt] = (item){dfn[v] , dfn[u] , dfo[u] , 1};
					line[++cnt] = (item){dfo[v] + 1 , dfn[u] , dfo[u] , -1};
				}
			}
			if(mp[u] == 3)
			{
				int v = id(i , j + 1);
				if((i + j) % 2 == 0)
				{
					line[++cnt] = (item){dfn[u] , dfn[v] , dfo[v] , 1};
					line[++cnt] = (item){dfo[u] + 1 , dfn[v] , dfo[v] , -1};
				}
				else
				{
					line[++cnt] = (item){dfn[v] , dfn[u] , dfo[u] , 1};
					line[++cnt] = (item){dfo[v] + 1 , dfn[u] , dfo[u] , -1};
				}
			}
		}
	}
	sort(line + 1 , line + cnt + 1);
	for(int i = 1 ; i <= cnt ; i++ )
	{
//		cerr << line[i].x << ' ' << line[i].y1 << ' ' << line[i].y2 << ' ' << line[i].val << endl;
		upd(1 , n * m , line[i].y1 , line[i].y2 , line[i].val , 1);
		if(line[i].x != line[i + 1].x) ans += c[1];
	}
	printf("%lld" , ans);
	return 0;
}