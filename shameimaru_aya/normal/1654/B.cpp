#include<bits/stdc++.h>
using namespace std;
int T , n , f[220] , pl;
char s[220000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		memset(f , 0 , sizeof(f));
		scanf("%s" , s); int n = strlen(s);
		for(int i = n - 1 ; i >= 0 ; i-- )
		{
			if(!f[s[i]]) 
			{
				f[s[i]] = 1; pl = i;
			}
		}
		for(int i = pl ; i < n ; i++ ) printf("%c" , s[i]); printf("\n");
	}
	return 0;
}
/*
*/