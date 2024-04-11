#include <bits/stdc++.h> 
using namespace std;
int T , n , p[110000] , x;
vector< int > id;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); 
		for(int i = 1 ; i <= n ; i++ ) p[i] = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(!p[i]) 
			{
				id.clear();
				while(1)
				{
					printf("? %d\n" , i); fflush(stdout);
					scanf("%d" , &x); id.push_back(x);
					if(p[x]) break;
					p[x] = 1;
				}
				for(int i = 0 ; i < (int)id.size() - 1 ; i++ )
				{
					p[id[i]] = id[i + 1];
				}
			}
		}
		printf("! ");
		for(int i = 1 ; i <= n ; i++ ) printf("%d " , p[i]); printf("\n"); fflush(stdout);
		
	}
    return 0;
} 
/*
*/