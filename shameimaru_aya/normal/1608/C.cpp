#include <bits/stdc++.h> 
using namespace std;
int T , n , a[110000] , b[110000] , ans[110000] , ma , mb , tst , dela[110000] , delb[110000];
int nexa[110000] , prea[110000] , nexb[110000] , preb[110000];
queue< int > q;
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		return num < x.num;
	}
} node[110000];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) ans[i] = dela[i] = delb[i] = 0; ma = mb = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , ma = (a[ma] > a[i] ? ma : i);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &b[i]) , mb = (b[mb] > b[i] ? mb : i);
		for(int i = 1 ; i <= n ; i++ ) node[i] = (item){a[i] , i};
		sort(node + 1 , node + n + 1); node[n + 1].id = 0;
		for(int i = 1 ; i <= n ; i++ ) 
			nexa[node[i].id] = node[i + 1].id , prea[node[i].id] = node[i - 1].id;
		
		for(int i = 1 ; i <= n ; i++ ) node[i] = (item){b[i] , i};
		sort(node + 1 , node + n + 1);
		for(int i = 1 ; i <= n ; i++ ) 
			nexb[node[i].id] = node[i + 1].id , preb[node[i].id] = node[i - 1].id;
		
		q.push(ma); q.push(mb);
		while(!q.empty())
		{
			int u = q.front(); q.pop(); 
			if(ans[u]) continue;
			ans[u] = 1;
			int p;
			if(!dela[u])
			{
				p = nexa[u];
				while(p)
				{
					q.push(p); 
					if(prea[p]) nexa[prea[p]] = nexa[p]; 
					if(nexa[p]) prea[nexa[p]] = prea[p]; 
					dela[p] = 1;
					p = nexa[p];
				}	
			}
			if(!delb[u])
			{
				p = nexb[u];
				while(p)
				{
					q.push(p); 
					if(preb[p]) nexb[preb[p]] = nexb[p]; 
					if(nexb[p]) preb[nexb[p]] = preb[p]; 
					delb[p] = 1;
					p = nexb[p];
				}
			}
		}
		for(int i = 1 ; i <= n ; i++ ) printf("%d" , ans[i]); printf("\n");
	}
    return 0;
}
/*
3
5
1 2 3 4 5
4 2 5 1 3
4
11 12 20 21
44 22 11 30
1
1000000000
1000000000

*/