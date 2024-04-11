#include <bits/stdc++.h>
using namespace std;
int T , n , v , p[220000] , num[220000] , tot;
void dfs( int k , int s , int noww )
{
	if(k > tot)
	{
		if(s == p[noww] * p[noww % tot + 1] ||
		   s == p[noww] * p[(noww + tot - 2) % tot + 1] || 
		   s == p[noww])
		return ;
		printf("%d " , s);
		return ;
	}
	for(int i = 0 ; i <= num[k] ; i++ )
	{
		if(k != noww || i) dfs(k + 1 , s , noww);
		s *= p[k];
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); v = n; tot = 0;
		for(int i = 2 ; i * i <= v ; i++ )
		{
			if(v % i == 0) p[++tot] = i , num[tot] = 0;
			while(v % i == 0)
			{
				v /= i;
				num[tot]++;
			}
		}
		if(v != 1) p[++tot] = v , num[tot] = 1;
		if(tot == 2 && num[1] == 1 && num[2] == 1)
		{
			printf("%d %d %d\n1\n" , p[1] , p[2] , n);
			continue;
		}
		if(tot == 2)
		{
			int s = 1;
			for(int i = 1 ; i <= num[1] ; i++ ) 
			{
				s *= p[1];
				printf("%d " , s);
			}
			printf("%d " , p[1] * p[2]);
			s = 1;
			for(int i = 1 ; i <= num[2] ; i++ ) 
			{
				s *= p[2];
				printf("%d " , s);
			}
			s = 1; int t = 1;
			for(int i = 1 ; i <= num[1] ; i++ )
			{
				s *= p[1]; t = 1;
				for(int j = 1 ; j <= num[2] ; j++ )
				{
					t *= p[2];
					if(i == 1 && j == 1) continue;
					printf("%d " , s * t);
				}
			}
			printf("\n0\n");
			continue;
		}
		for(int i = 1 ; i <= tot ; i++ )
		{
			printf("%d " , p[i]);
			dfs(i , 1 , i);
			printf("%d " , p[i] * p[i % tot + 1]);
		}
		printf("\n0\n");
	}
	return 0;
}
/*

*/