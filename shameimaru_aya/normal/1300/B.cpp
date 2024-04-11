#include<bits/stdc++.h>
using namespace std;
int T , n , a[300000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n + n ; i++ )
		{
			scanf("%d" , &a[i]);
		}
		sort(a + 1 , a + n + n + 1);
		printf("%d\n" , a[n + 1] - a[n]);
	}
	return 0;
}
//2 3 4 5 8 13 13 16 17 20