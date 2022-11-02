#include<bits/stdc++.h>
using namespace std;
int T , n , x , l[1100] , p[1100] , fr[1100] , id[1100] , fl , fp;
int l0[1100] , p0[1100] , cl , cp , al , ap , a , b , sl , sp , u;
bitset< 1000001 > dp[1100];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		sl = sp = cl = cp = fl = fp = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &l[i]) , sl += l[i];
		scanf("%d" , &x);
		for(int i = 1 ; i <= x ; i++ ) scanf("%d" , &p[i]) , sp += p[i];
		if(n != x || sl % 2 == 1 || sp % 2 == 1)
		{
			printf("No\n");
			continue;
		}
		sort(l + 1 , l + n + 1); sort(p + 1 , p + n + 1); 
		reverse(l + 1 , l + n + 1); reverse(p + 1 , p + n + 1); 
		dp[0].set(0 , 1);
		for(int i = 1 ; i <= n ; i++ ) dp[i] = dp[i - 1] | (dp[i - 1] << l[i]);
		if(!dp[n][sl / 2])
		{
			printf("No\n");
			continue;
		}
		u = sl / 2;
		for(int i = n - 1 ; i >= 0 ; i-- )
		{
			if(!dp[i][u]) l0[++cl] = l[i + 1] , u = u - l[i + 1];
			if(u == 0) break;
		}
		al = cl; u = sl / 2;
		for(int i = n - 1 ; i >= 0 ; i-- )
		{
			if(u && !dp[i][u]) u = u - l[i + 1];
			else l0[++cl] = -l[i + 1];
		}
		reverse(l0 + 1 , l0 + al + 1);
		
		dp[0].set(0 , 1);
		for(int i = 1 ; i <= n ; i++ ) dp[i] = dp[i - 1] | (dp[i - 1] << p[i]);
		if(!dp[n][sp / 2])
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		u = sp / 2;
		for(int i = n - 1 ; i >= 0 ; i-- )
		{
			if(!dp[i][u]) p0[++cp] = p[i + 1] , u = u - p[i + 1];
			if(u == 0) break;
		}
		ap = cp; u = sp / 2;
		for(int i = n - 1 ; i >= 0 ; i-- )
		{
			if(u && !dp[i][u]) u = u - p[i + 1];
			else p0[++cp] = -p[i + 1];
		}
		
		if(al > ap) 
		{
			reverse(p0 + 1 , p0 + ap + 1);  reverse(p0 + ap + 1 , p0 + n + 1);
			reverse(l0 + 1 , l0 + n + 1); reverse(p0 + 1 , p0 + n + 1); 
			for(int i = 1 ; i <= n ; i++ ) l0[i] = -l0[i] , p0[i] = -p0[i];
			al = n - al , ap = n - ap;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(l0[i] < 0 && !fl) fl = 1 , reverse(p0 + i , p0 + ap + 1);
			if(p0[i] < 0 && !fp) fp = 1 , reverse(l0 + i , l0 + n + 1);
//			cerr << endl << l0[i] << ' ' << p0[i] << endl;
			a += l0[i];
			printf("%d %d\n" , a , b);
			b += p0[i];
			printf("%d %d\n" , a , b);
		}
	}
    return 0;
}
/*
2
9
1 4 1 2 2 2 2 2 4
9
3 4 5 12 2 2 4 8 16

4
1 2 3 6
2
1 3
*/