#include<bits/stdc++.h>
#define lson (i << 1) - 1
#define rson (i << 1)
using namespace std;
int n , m , k , a[20000] , b[20000] , c[20000] , noww , ans;
int qwq , x , y , z;
struct item
{
	int sum , id , val;
	bool operator < ( const item &x ) const
	{
		return c[id] > c[x.id];
	}
} node[20000];
struct edge
{
	int u , v;
	bool operator < ( const edge &x ) const
	{
		return u < x.u;
	}
} e[400000];
int main()
{
	scanf("%d%d%d" , &n , &m , &k);
	node[0].sum = k;
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d%d" , &x , &y , &z);
		a[lson] = x;
		b[rson] = y;
		c[rson] = z;
		node[lson].sum = node[lson - 1].sum + b[lson];
		node[lson].id = node[lson].val = lson;
		node[rson].sum = node[rson - 1].sum + b[rson];
		node[rson].id = node[rson].val = rson;
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &e[i].u , &e[i].v);
		e[i].u <<= 1;
		e[i].v <<= 1;
	}
	sort(e + 1 , e + m + 1);
	for(int i = 1 ; i <= n + n ; i++ )
	{
		node[i].sum -= a[i];
		if(node[i].sum < 0)
		{
			printf("-1");
			return 0;
		}
	}
	qwq = node[n + n].sum;
	for(int i = n + n - 1 ; i >= 1 ; i-- )
	{
		qwq = min(qwq , node[i].sum);
		node[i].sum = min(qwq , node[i].sum);
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		node[e[i].v].sum = node[e[i].u].sum;
		node[e[i].v].val = max(node[e[i].v].val , e[i].u);
//		cerr << e[i].u << " " << e[i].v << " " << node[e[i].u].sum << " " << node[e[i].v].sum << endl;
	}
//	cerr << node[n + n - 4].sum << endl;
	sort(node + 1 , node + n + n + 1);
	for(int i = 1 ; i <= n + n ; i++ )
	{
		if(c[node[i].id] == 0) break;
//		cerr << node[i].id << " ";
//		cerr << node[i].sum << endl;
		if(node[i].sum > 0)
		{
			bool flag = false;
			ans += c[node[i].id];
//			cerr << node[i].sum << " " << node[i].id << "   ";
			for(int j = 1 ; j <= n + n ; j++ )
			{
				if(node[j].val >= node[i].val)
				{
					node[j].sum--;
//					cerr << node[j].sum << ' ';
					if(node[j].sum < 0) flag = 1;
				}
			}
			if(flag)
			{
				ans -= c[node[i].id];
			for(int j = 1 ; j <= n + n ; j++ )
			{
				if(node[j].val >= node[i].val)
				{
//					cerr << node[j].id << ' ';
					node[j].sum++;
				}
			}
			}
//			cerr << endl;
		}
	}
	printf("%d" , ans);
	return 0;
}
/*
5 3 7
7 5 2
3 0 8
11 2 10
13 3 5
16 0 0
3 1
2 1
4 3
*/