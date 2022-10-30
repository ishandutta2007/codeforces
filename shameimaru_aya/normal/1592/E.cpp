#include <bits/stdc++.h> 
using namespace std;
int n , a[1100000] , msk , f[1 << 20][2] , ver[1 << 20][2] , tot , ans , s , s0;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int b = 20 ; b >= 1 ; b-- )
	{
		memset(ver , 0 , sizeof(ver)); tot = s = 0; s0 = (1 << 20) - 1; 
		for(int i = n + 1 ; i >= 1 ; i-- )
		{
			if(((a[i - 1] >> (b - 1)) & 1) && !((a[i] >> (b - 1)) & 1)) tot++ , s0 = (1 << 20) - 1;
			if((a[i - 1] >> (b - 1)) & 1)
				if(ver[s][i & 1] != tot) ver[s][i & 1] = tot , f[s][i & 1] = i;
			if(((a[i] >> (b - 1)) & 1))
				if(ver[s][i & 1] == tot) ans = max(ans , f[s][i & 1] - i);
			s ^= a[i - 1] >> b; s0 &= a[i - 1] >> b;
		}
	}
	printf("%d" , ans);
	return 0;
}
/*
9
5 6 10 7 6 7 9 7 7
*/