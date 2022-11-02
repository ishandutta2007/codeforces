#include<bits/stdc++.h>
using namespace std;
int T , n , a[110000] , maxx , secc;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); maxx = secc = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%d" , &a[i]);
			secc = max(secc , a[i]);
			if(secc > maxx) swap(secc , maxx);
		}
		printf("%d\n" , secc + maxx);
	}
	return 0;
}
/*
*/