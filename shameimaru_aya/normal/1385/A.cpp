#include<bits/stdc++.h>
using namespace std;
int T , x , y , z;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &x , &y , &z);
		if(x == y && y == z)
		{
			printf("YES\n%d %d %d\n" , x , x , x);
			continue;
		}
		if(x == y)
		{
			if(z > x) printf("NO\n");
			else printf("YES\n%d %d %d\n" , x , z , z);
			continue;
		}
		if(y == z)
		{
			if(x > z) printf("NO\n");
			else printf("YES\n%d %d %d\n" , x , x , z);
			continue;
		}
		if(x == z)
		{
			if(y > x) printf("NO\n");
			else printf("YES\n%d %d %d\n" , y , x , y);
			continue;
		}
		printf("NO\n");
	}
	
    return 0;
}