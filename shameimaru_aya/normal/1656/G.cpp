#include<bits/stdc++.h>
using namespace std;
int T , n , a[220000] , t[220000] , gg , f , id , p[220000] , st[220000] , fa[220000] , num[220000];
vector< int > pl[220000];
int getf( int x )
{
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}
void merge( int x , int y )
{
	int A = getf(x) , B = getf(y);
	if(A != B) fa[B] = A , num[B] = 0;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); gg = f = id = 0;
		for(int i = 1 ; i <= n ; i++ ) t[i] = st[i] = 0 , pl[i].clear();
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , t[a[i]]++ , pl[a[i]].push_back(i);
		for(int i = 1 ; i <= n ; i++ )
			if(t[i] & 1) f++ , id = i;
		if(f != (n & 1))
		{
			printf("NO\n");
			continue;
		}
		if((n & 1) && t[a[(n + 1) / 2]] == 1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(id)
		{
			if(pl[id].back() != (n + 1) / 2) p[(n + 1) / 2] = pl[id].back() , pl[id].pop_back();
			else p[(n + 1) / 2] = pl[id][0] , st[id] = 1;
		}
		int it = 1;
		for(int i = 1 ; i <= n ; i++ )
			for(int j = st[i] ; j < pl[i].size() ; j += 2 ) 
				p[it] = pl[i][j] , p[n + 1 - it] = pl[i][j + 1] , it++;
//		for(int i = 1 ; i <= n ; i++ ) printf("%d " , p[i]); printf("\n");
		for(int i = 1 ; i <= n ; i++ ) fa[i] = i , num[i] = 0;
		for(int i = 1 ; i <= n ; i++ ) merge(i , p[i]);
		for(int i = 1 ; i <= n / 2 ; i++ )
		{
			if(getf(i) != getf(n - i + 1))
				swap(p[i] , p[n - i + 1]) , merge(i , n - i + 1); 
			num[getf(i)] = i;
		}
		for(int i = 1 ; i <= n / 2 ; i++ ) num[getf(i)] = i;
		int qwq = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(num[i])
			{
				if(!qwq) qwq = num[i];
				else
				{
					int a = qwq , b = n + 1 - qwq , c = num[i] , d = n + 1 - num[i];
					int A = p[qwq] , B = p[n + 1 - qwq] , C = p[num[i]] , D = p[n + 1 - num[i]];
					p[a] = C; p[c] = B; p[b] = D; p[d] = A;
				}
			}
		}
		for(int i = 1 ; i <= n ; i++ ) printf("%d " , p[i]); printf("\n");
	}
	return 0;
}
/*
1
7
1 6 3 6 2 2 1
*/