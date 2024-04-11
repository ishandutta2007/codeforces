#include <bits/stdc++.h>
using namespace std;
int T , n , m , x , y , out[220000] , ans , opt;
int main()
{
	scanf("%d%d" , &n , &m); 
	for(int i = 1 ; i <= m ; i++ ) scanf("%d%d" , &x , &y) , out[min(x , y)]++;
	for(int i = 1 ; i <= n ; i++ ) ans += (out[i] == 0);
	scanf("%d" , &m);
	while(m--)
	{
		scanf("%d" , &opt);
		if(opt == 1) 
		{
			scanf("%d%d" , &x , &y); out[min(x , y)]++;
			if(out[min(x , y)] == 1) ans--;
		}
		if(opt == 2) 
		{
			scanf("%d%d" , &x , &y); out[min(x , y)]--;
			if(out[min(x , y)] == 0) ans++;
		}
		if(opt == 3) printf("%d\n" , ans);
	}
	return 0;
}
/*

*/