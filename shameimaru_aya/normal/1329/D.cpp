#include<bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int T , n , m , num[30] , st[220000] , pl[220000] , maxx;
int c[880000] , lazy[880000] , a[220000] , top;
string s;

void build( int l , int r , int id )
{
	c[id] = lazy[id] = 0;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson); 
	return ;
}
inline void push_down( int l , int r , int id )
{
	if(!lazy[id]) return ;
	int mid = l + r >> 1;
	c[lson] = mid - l + 1; c[rson] = r - mid;
	lazy[lson] = lazy[rson] = 1; lazy[id] = 0;
	return ;
}
void upd( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		c[id] = r - l + 1;
		lazy[id] = 1;
		return ;
	}
	push_down(l , r , id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , lson); upd(mid + 1 , r , a , b , rson); 
	c[id] = c[lson] + c[rson];
	return ;
}
int ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return 0;
	if(a <= l && r <= b) return c[id];
	push_down(l , r , id);
	int mid = l + r >> 1;
	return ask(l , mid , a , b , lson) + ask(mid + 1 , r , a , b , rson); 
}
inline bool check()
{
	int maxx = 0 , sum = 0;
	for(int i = 1 ; i <= 26 ; i++ ) 
		sum += num[i] , maxx = max(maxx , num[i]);
	return 2 * maxx < sum;
}
inline int tpl( int x )
{
	return x - ask(1 , n , 1 , x - 1 , 1);
}

int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		maxx = m = top = 0; memset(num , 0 , sizeof(num));
		cin >> s; n = s.size();
		build(1 , n , 1);
		for(int i = 1 ; i < n ; i++ )
			if(s[i] == s[i - 1]) a[++m] = s[i] - 'a' + 1 , num[s[i] - 'a' + 1]++ , pl[m] = i;
		for(int i = 1 ; i <= 26 ; i++ )
			if(num[maxx] < num[i]) maxx = i;
		printf("%d\n" , max(num[maxx] , (m + 1) / 2) + 1);
		for(int i = 1 ; i <= m ; i++ )
		{
			if(!top || !check() || a[st[top]] == a[i]) 
			{
				st[++top] = i;
				continue;
			}
			printf("%d %d\n" , tpl(pl[st[top]] + 1) , tpl(pl[i]));
			upd(1 , n , pl[st[top]] + 1 , pl[i] , 1);
			num[a[st[top]]]--; num[a[i]]--; top--;
		}
//		cerr << 111111111 << endl;
//		for(int i = 1 ; i <= top ; i++ ) cerr << st[i] << ' ' << a[st[i]] << endl;
		for(int i = 1 ; i <= top ; i++ ) a[i] = a[st[i]] , pl[i] = pl[st[i]];
		m = top; top = maxx = 0;
		for(int i = 1 ; i <= 26 ; i++ )
			if(num[maxx] < num[i]) maxx = i;
		for(int i = 1 ; i <= m ; i++ )
		{
//			cerr << st[top] << ' ' << i << ' ' << a[st[top]] << ' ' << a[i] << endl;
			if(!top || (a[st[top]] != maxx && a[i] != maxx) || a[st[top]] == a[i]) st[++top] = i;
			else
			{
				printf("%d %d\n" , tpl(pl[st[top]] + 1) , tpl(pl[i]));
				upd(1 , n , pl[st[top]] + 1 , pl[i] , 1);
				top--;
			}
		}
		for(int i = 1 ; i <= top ; i++ ) 
		{
			printf("%d %d\n" , tpl(pl[st[i]]) , tpl(pl[st[i]]));
			upd(1 , n , pl[st[i]] , pl[st[i]] , 1);
		}
		printf("%d %d\n" , 1 , tpl(n));
	}
	return 0;
}
/*
1
aabaaacab
*/