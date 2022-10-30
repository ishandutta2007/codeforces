#include <bits/stdc++.h>
#define lowbit(x) (x & (-x)) 
#define pr pair< int , int >
#define F first
#define S second
using namespace std;
int n , x , y , xx , yy , ans , tot , top , p[880000] , a[880000] , dep[880000];
long long p3[50] , ful[50];
vector< int > son[880000];
map< pair< pr , int > , int > dddfn;
struct item
{
	long long x , y , val , dfn;
	bool operator < ( const item &a ) const
	{
		return dfn < a.dfn;
	}
	bool operator == ( const item &a ) const
	{
		return (x == a.x && y == a.y);
	}
	bool operator != ( const item &a ) const
	{
		return !((*this) == a);
	}
	pr mp()
	{
		return make_pair(x , y);
	}
} node[880000] , st[880000];
map< item , int > id;
long long getdfn( int x , int y , int d = 30 ) 
{
//	cerr << x << ' ' << y << ' ' << d << endl;
//	system("pause");
	if(x == 0 && y == 0) return 1; //root
	if(x < (1 << d) && y < (1 << d)) //2
		return getdfn(x , y , d - 1) + (y == 0 ? 0ll : p3[d]);
	if(x >= (1 << d) && y < (1 << d)) //1
		return getdfn(x - (1 << d) , y , d - 1) + (1ll << d);
	if(x >= (1 << d) && y >= (1 << d)) //3
		return getdfn(x - (1 << d) , y - (1 << d) , d - 1) + p3[d] * 2;
}
item make_item( int x , int y , int f )
{
	item ans;
	ans.x = x; ans.y = y; 
	if(f) ans.dfn = getdfn(x , y);
	return ans;
}
item getfa( item a , int d , int ff )
{
	long long k = (1ll << d);
	if(a.x <= k) return make_item(0 , 0 , ff);
	if(a.y < k) return make_item(a.x - k , 0 , ff);
	long long i = lowbit((a.x & ful[d]));
	long long sy = a.y & ((i << 1) - 1);
//	cerr << a.x << ' ' << a.y << ' ' << d << endl;
//	cerr << d << ' ' << (a.x & ful[d]) << ' ' << i << endl;
//	cerr << sy << endl;
	if(a.y & i)
	{
		long long qwq = (a.x - k) & ((i << 1) - 1);
//		cerr << a.y << ' ' << sy << ' ' << qwq << ' ' << i << endl;
//		cerr << a.x - k << ' ' << ((a.y ^ sy) | qwq) << endl;
		return make_item(a.x - k , (a.y ^ sy) | qwq , ff);
	}
	else return make_item(a.x - k , (a.y ^ sy) , ff);
}
item lca( item a , item b )
{
	if(a.x < b.x) swap(a , b);
	for(int i = 30 ; i >= 0 ; i-- )
		if(getfa(a , i , 0).x >= b.x) a = getfa(a , i , 0);
	if(a.y == b.y) return a;
	for(int i = 30 ; i >= 0 ; i-- )
		if(getfa(a , i , 0).y != getfa(b , i , 0).y) a = getfa(a , i , 0) , b = getfa(b , i , 0);
	return getfa(a , 0 , 1);
}
void dfs( int u , int fa )
{
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		dfs(son[u][i] , u);
		node[u].val += node[son[u][i]].val;
	}
	if(node[u].val) a[dep[fa]] ^= 1 , a[dep[u]] ^= 1;
//	cerr << dep[fa] << ' ' << dep[u] << ' ' << node[u].val << endl;
//	cerr << node[u].x << ' ' << node[u].y << ' ' << node[u].val << ' ' << dep[fa] << ' ' << dep[u] << endl;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	p3[0] = 1;
	for(int i = 1 ; i <= 31 ; i++ ) p3[i] = p3[i - 1] * 3 , ful[i] = (1ll << i) - 1;
	for(int i = 0 ; i <= 31 ; i++ ) ful[i] = ful[31] ^ ful[i];
//	cerr << lca(make_item(7 , 4) , make_item(3 , 2)).x << ' ' << lca(make_item(7 , 4) , make_item(3 , 2)).y << endl;
//	while(1);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d%d%d" , &x , &y , &xx , &yy); x += y; xx += yy;
		item aa , bb;
		node[++tot] = make_item(x , y , 1); node[tot].val = 1; aa = node[tot]; 
		node[++tot] = make_item(xx , yy , 1); node[tot].val = 1; bb = node[tot]; 
		item L = lca(aa , bb) , f = getfa(L , 0 , 1); 
		L.dfn = getdfn(L.x , L.y);
//		cerr << L.x << ' ' << L.y << ' ' << L.dfn << endl;
//		cerr << f.x << ' ' << f.y << ' ' << f.dfn << endl;
		if(L.x) node[++tot] = f , node[tot].val = -1;
		node[++tot] = L , node[tot].val = -1;
	}
//	cerr << 1111111;
	sort(node + 1 , node + tot + 1);
//	for(int i = 1 ; i <= tot ; i++ ) cerr << node[i].x << ' ' << node[i].y << ' ' << node[i].dfn << endl;
	if(node[1].x || node[1].y)
	{
		node[++tot] = make_item(0 , 0 , 1);
		sort(node + 1 , node + tot + 1);
	}
	int las = 0 , qwq = 1; node[0].x = -1;
	for(int i = 1 ; i <= tot ; i++ )
	{
		if(node[i] == node[las]) node[las].val += node[i].val , node[i].val = 0;
		else las = i;
	} 
	for(int i = 2 ; i <= tot ; i++ )
		if(node[i].val) node[++qwq] = node[i];
	tot = qwq;
	for(int i = 1 ; i <= tot ; i++ ) id[node[i]] = i;
	st[++top] = node[1];
//	cerr << 11111111 << endl;
	for(int i = 2 ; i <= qwq ; i++ )
	{
		item L = lca(st[top] , node[i]); 
		if(!id[L]) node[++tot] = L , id[L] = tot;
		if(L == st[top]) st[++top] = node[i];
		else
		{
			while(top > 1 && st[top - 1].x > L.x)
			{
				son[id[st[top - 1]]].push_back(id[st[top]]);
				top--;
			}
			if(st[top].x > L.x)
			{
				son[id[L]].push_back(id[st[top]]);
				top--;
			}
			if(!top || st[top] != L) st[++top] = L;
			st[++top] = node[i];
		}
	}
//	cerr << 11111111 << endl;
	while(top > 1) 
	{
		son[id[st[top - 1]]].push_back(id[st[top]]);
		top--;
	}
//	cerr << "node: \n"; 
//	for(int i = 1 ; i <= tot ; i++ ) cerr << node[i].x << ' ' << node[i].y << ' ' << node[i].val << endl; cerr << endl;
	for(int i = 1 ; i <= tot ; i++ ) p[i] = node[i].x;
	sort(p + 1 , p + tot + 1); qwq = unique(p + 1 , p + tot + 1) - p - 1;
	for(int i = 1 ; i <= tot ; i++ )
		dep[i] = lower_bound(p + 1 , p + qwq + 1 , node[i].x) - p;
	dfs(1 , 0);
//	cerr << "dep: \n"; for(int i = 1 ; i <= tot ; i++ ) cerr << dep[i] << ' '; cerr << endl;
//	cerr << "a: \n"; for(int i = 1 ; i <= qwq ; i++ ) cerr << a[i] << ' '; cerr << endl;
	for(int i = 1 ; i <= qwq ; i++ ) ans += a[i];
	printf("%d" , ans);
	return 0;
}
/*
*/