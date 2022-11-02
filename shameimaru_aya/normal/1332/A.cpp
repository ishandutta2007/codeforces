#include<bits/stdc++.h>
using namespace std;
int T , x1 , x2 , x3 , x4 , x , y , a , b , c , d , a1 , a2;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d%d%d%d" , &a , &b , &c , &d , &x , &y , &x1 , &x3 , &x2 , &x4);
		if(a && x - 1 < x1 && b && x + 1 > x2)
		{
			printf("No\n");
			continue;
		}
		if(c && y - 1 < x3 && d && y + 1 > x4)
		{
			printf("No\n");
			continue;
		}
		a = b - a; b = d - c;
		if(x + a >= x1 && x + a <= x2 && y + b >= x3 && y + b <= x4)
		printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}