#include <bits/stdc++.h>
using namespace std;
int T , n , it , a[220000] , b[220000] , tot;
queue< int > q[220000];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , q[a[i]].push(i);
		it = 0; tot = 0;
		while(it < n)
		{
			int g = it;
			for(int i = 0 ; i <= n + 1 ; i++ )
			{
				if(!q[i].empty()) g = max(g , q[i].front());
				else 
				{
					b[++tot] = i;
					break;
				}
			}
			if(g == it)
			{
				it++; q[a[it]].pop();
				while(it < n)
				{
					it++; b[++tot] = 0; q[a[it]].pop();
				}
				break;
			}
			while(it < g)
			{
				it++; q[a[it]].pop();
			}
		}
		printf("%d\n" , tot);
		for(int i = 1 ; i <= tot ; i++ ) printf("%d " , b[i]); printf("\n");
	}
	return 0;
}
/*
*/