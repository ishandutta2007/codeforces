#include <bits/stdc++.h> 
using namespace std;
int T , n , a[110] , ans;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); ans = 1;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = i + 1 ; j <= n ; j++ )
			{
				int pr = j - i , d = a[j] - a[i] , tot = 0 , g = __gcd(pr , abs(d));
				pr /= g; d /= g;
				for(int k = (i - 1) % pr + 1 ; k <= n ; k += pr )
					if(a[k] == a[i] + (k - i) / pr * d) tot++;
				ans = max(ans , tot);
			}
		}
		printf("%d\n" , n - ans);
	}
    return 0;
} 
/*
*/