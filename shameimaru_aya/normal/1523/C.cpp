#include <bits/stdc++.h>
using namespace std;
int T , n , a[110000] , ans[110000] , dep;
void print()
{
	for(int i = 1 ; i <= dep ; i++ )
	{
		printf("%d" , ans[i]);
		if(i != dep) printf(".");
	}
	printf("\n");
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , ans[i] = 0; dep = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(a[i] == 1) ans[++dep] = 1;
			else
			{
				while(ans[dep] != a[i] - 1) dep--;
				ans[dep] = a[i];
			}
			print(); 
		}
	}
	return 0;
}
/*

*/