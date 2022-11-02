#include<bits/stdc++.h>
using namespace std;
int T , n , a[330000] , k , l , safe[330000] , tot , flag , noww , opt;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		flag = tot = 0;
		scanf("%d%d%d" , &n , &k , &l);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		safe[++tot] = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(a[i] > l)
			{
				flag = 1;
				break;
			}
			if(a[i] + k <= l) safe[++tot] = i;
		}
		safe[++tot] = n + 1;
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		for(int i = 1 ; i < tot ; i++ )
		{
			noww = k; opt = -1;
			for(int j = safe[i] + 1 ; j < safe[i + 1] ; j++ )
			{
				if(l - a[j] < noww)
				{
					if(opt == 1)
					{
						flag = 1;
						break;
					}
					noww = l - a[j];
					if(noww == 0) opt = 1;
				}
				noww += opt;
				if(noww == 0) opt = 1;
			}
			if(flag) break;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
/*
4
5 100 100
100 100 100 5 3
1 1 1
0
4 1 1
0 0 1 0
6 4 7
1 2 3 4 3 2
*/