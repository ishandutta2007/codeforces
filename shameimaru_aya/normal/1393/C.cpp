#include<bits/stdc++.h>
using namespace std;
int T , n , a , t[110000] , maxx , tot;
string s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); maxx = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a) , t[a]++;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(maxx == t[i]) tot++;
			if(maxx < t[i]) maxx = t[i] , tot = 1;
		};
		printf("%d\n" , (n - maxx * tot) / (maxx - 1) + tot - 1);
		for(int i = 1 ; i <= n ; i++ ) t[i] = 0;
	}
	return 0;
}