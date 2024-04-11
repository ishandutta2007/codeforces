#include <bits/stdc++.h>
using namespace std;
int T , n , f0 , t0;
char s[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%s" , s + 1); n = strlen(s + 1); f0 = t0 = 0; s[0] = '$';
		for(int i = 1 ; i <= n ; i++ )
		{
			if(s[i] == '0') f0 = 1 , t0 += (s[i - 1] != '0');
		}
		if(!f0) printf("0\n");
		else
		{
			if(t0 == 1) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;  
}
/*
*/