#include <bits/stdc++.h>
using namespace std;
int n , k , a[110000];
int main()
{
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i < 2 * n ; i += 2 )
	{
		a[i] = i; a[i + 1] = i + 1;
		if(k) k-- , swap(a[i] , a[i + 1]);
	}
	for(int i = 1 ; i <= 2 * n ; i++ ) printf("%d " , a[i]);
	return 0;
}
/*

*/