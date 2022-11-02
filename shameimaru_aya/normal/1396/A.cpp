#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[110000];
int main()
{
	scanf("%lld" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &a[i]);
	if(n == 1)
	{
		printf("1 1\n0\n1 1\n0\n1 1\n%lld" , -a[1]);
		return 0;
	}
	printf("1 %lld\n" , n - 1);
	for(int i = 1 ; i < n ; i++ )
	{
		printf("%lld " , 1ll * (n - 1) * (a[i] % n));
		a[i] += 1ll * (n - 1) * (a[i] % n);
	}
	printf("\n%lld %lld\n%lld\n" , n , n , -a[n]); a[n] = 0;
	printf("1 %lld\n" , n);
	for(int i = 1 ; i <= n ; i++ ) printf("%lld " , -a[i]);;
    return 0;
}