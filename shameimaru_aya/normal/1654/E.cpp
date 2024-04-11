#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n , a[110000] , lim , ans = 1 , las;
long long b[110000];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n); lim = sqrt(100000) + 1; 
//	cerr << bs << ' ' << mod << endl;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(long long k = -lim ; k <= lim ; k++ )
	{
		for(int i = 1 ; i <= n ; i++ ) b[i] = a[i] - k * i;
		sort(b + 1 , b + n + 1);
		las = 1;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(b[i] != b[las]) 
			{
				ans = max(ans , i - las);
				las = i; 
			}
		}
		ans = max(ans , n - las + 1);
//		cerr << clock() << endl;
	}
//	cerr << 111111 << endl;
	for(int i = 1 ; i <= n ; i++ )
	{
		int qwq = min(i - 1 , lim);
		for(int j = 1 ; j <= qwq ; j++ )
		{
			long long d = a[i] - a[i - j];
			if(d % j == 0) b[j] = d / j;
			else b[j] = -11451419;
		}
		sort(b + 1 , b + qwq + 1); 
		las = 1;
		for(int j = 1 ; j <= qwq ; j++ ) 
		{
			if(b[j] != b[las]) 
			{
				if(b[las] != -11451419) ans = max(ans , j - las + 1);
//				if(i - las + 1 == 3) cerr << i << ' ' << las << ' ' << b[i] << endl;
				las = j;  
			}
		}
		if(b[las] != -11451419) ans = max(ans , qwq - las + 2);
	}
	cout << n - ans;
	return 0;
}
/*
*/