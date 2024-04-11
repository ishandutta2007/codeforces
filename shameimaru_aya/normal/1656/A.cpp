#include <bits/stdc++.h>
using namespace std;
int T , n , a[220000] , b[220000];
bool cmp( int x , int y )
{
	return a[x] < a[y];
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , b[i] = i;
		sort(b + 1 , b + n + 1 , cmp);
		printf("%d %d\n" , b[1] , b[n]);
	}
	return 0;
}
/*
*/