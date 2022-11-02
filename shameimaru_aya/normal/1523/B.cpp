#include <bits/stdc++.h>
using namespace std;
int T , n , a[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		cout << 3 * n << endl;
		for(int i = 1 ; i <= n ; i += 2 ) 
		{
			printf("2 %d %d\n" , i , i + 1);
			printf("1 %d %d\n" , i , i + 1);
			printf("2 %d %d\n" , i , i + 1);
			printf("1 %d %d\n" , i , i + 1);
			printf("2 %d %d\n" , i , i + 1);
			printf("1 %d %d\n" , i , i + 1);
		}
	}
	return 0;
}
/*

*/