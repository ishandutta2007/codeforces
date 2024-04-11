#include <bits/stdc++.h>
using namespace std;
int T , n , a , s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); s = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a) , s += a;
		if(s % n == 0) printf("0\n");
		else printf("1\n");
	}
	return 0; 
}
/*
*/