#include<bits/stdc++.h>
using namespace std;
struct item
{
	int son[2] , val , fa , cnt , siz;
} node[330000];
struct query
{
	int l , r , ans , id;
} q[330000];
bool cmp1( query a , query b )
{
	return a.l < b.l;
}
bool cmp2( query a , query b )
{
	return a.id < b.id;
}
int n , m , opt , rt , tot , x , a , pl[330000] , lft[330000];
int l[330000] , r[330000] , cnt , c[330000] , s[330000]; 
vector< int > id[330000];
inline void upd( int id )
{
	node[id].siz = node[node[id].son[0]].siz + node[node[id].son[1]].siz + node[id].cnt;
	return ;
}
inline bool get( int x )
{
	return (node[node[x].fa].son[1] == x);
}
inline void connect( int x , int y , int z )
{
	if(x) node[x].fa = y;
	if(y) node[y].son[z] = x;
	return ;
}
inline void rotate( int x )
{
	int fa = node[x].fa , ffa = node[fa].fa , a = get(x) , b = get(fa);
	connect(node[x].son[a ^ 1] , fa , a);
	connect(fa , x , a ^ 1);
	connect(x , ffa , b);
	upd(fa); upd(x); 
	return ;
}
inline void splay( int x )
{
	for(int fa ; fa = node[x].fa ; rotate(x))
	{
		if(!node[fa].fa) continue;
		if(get(fa) == get(x)) rotate(fa);
		else rotate(x);
	}
	rt = x;
	return ;
}
inline void adde( int x )
{
	node[++tot].val = x; node[tot].siz = node[tot].cnt = 1;
	node[tot].son[0] = node[tot].son[1] = node[tot].fa = 0;
	return ;
}
void insert( int id , int x , bool tp , int las )
{
	if(!id)
	{
		adde(x); connect(tot , las , tp); upd(tot); splay(tot);
		return ;
	}
	if(node[id].val == x)
	{
		node[id].cnt++; upd(id); splay(id);
		return ;
	}
	if(node[id].val > x) return insert(node[id].son[0] , x , 0 , id) , upd(id);
	return insert(node[id].son[1] , x , 1 , id) , upd(id);
}
int kth( int id , int k )
{
	int qwq = node[node[id].son[0]].siz;
	if(qwq <= k - 1 && qwq >= k - node[id].cnt)
	{
		splay(id);
		return node[id].val;
	}
	if(qwq < k - node[id].cnt)
		return kth(node[id].son[1] , k - node[id].cnt - qwq);
	else kth(node[id].son[0] , k);
}
inline void build( int l , int r , int id )
{
    if(l == r)
    {
        c[id] = s[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l , mid , id << 1);
    build(mid + 1 , r , id << 1 | 1);
    c[id] = (c[id << 1] + c[id << 1 | 1]);
    return ;
}
inline void updc( int l , int r , int a , int k , int id )
{
    if(l > a || r < a) return ;
    if(a == l && r == a)
    {
        c[id] = k;
        return ;
    }
    int mid = (l + r) >> 1;
    updc(l , mid , a , k , id << 1);
    updc(mid + 1 , r , a , k , id << 1 | 1);
    c[id] = (c[id << 1] + c[id << 1 | 1]);
    return ;
}
inline int ask( int l , int r , int a , int b , int id )
{
    if(l > b || r < a) return 0;
    if(a <= l && r <= b) return c[id];
    int mid = (l + r) >> 1;
    return (ask(l , mid , a , b , id << 1) + ask(mid + 1 , r , a , b , id << 1 | 1));
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d" , &a);
		int qwq = i - a;
		if(qwq < 0 || qwq > cnt) continue ;
		s[i] = 1;
		if(qwq == 0)
		{
			id[i].push_back(i);
			insert(rt , i , 0 , 0);
			cnt++;
		}
		else
		{
			id[kth(rt , cnt + 1 - qwq)].push_back(i);
			insert(rt , min(kth(rt , cnt + 1 - qwq) , i) , 0 , 0);
			cnt++;
		}
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &q[i].l , &q[i].r);
		q[i].l++; q[i].r = n - q[i].r; q[i].id = i;
	}
	sort(q + 1 , q + m + 1 , cmp1);
	build(1 , n , 1);
	for(int i = 1 ; i <= m ; i++ )
	{
		for(int j = q[i - 1].l ; j < q[i].l ; j++ )
			for(int k = 0 ; k < id[j].size() ; k++ ) updc(1 , n , id[j][k] , 0 , 1);
		q[i].ans = ask(1 , n , q[i].l , q[i].r , 1);
	}
	sort(q + 1 , q + m + 1 , cmp2);
	for(int i = 1 ; i <= m ; i++ ) printf("%d\n" , q[i].ans);
    return 0;
}