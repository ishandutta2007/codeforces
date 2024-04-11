#include <bits/stdc++.h>
using namespace std;
int n , a , cnt , ans[20];
int main()
{
	scanf("%d" , &n);
	while(n)
	{
		int s = n , t = 1; a = 0;
		while(s)
		{
			if(s % 10) a += t;
			t *= 10; s /= 10;
		}
		ans[++cnt] = a;
		n -= a;
	}
	printf("%d\n" , cnt);
	for(int i = 1 ; i <= cnt ; i++ ) printf("%d " , ans[i]);
	return 0;
}
/*

*/