#include<bits/stdc++.h>
using namespace std;
int n , cnt , a[220000];
long long sum;
int main() 
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int l = 1 ; l <= n ; l++ )
	{
		sum = a[l + 1];
		for(int r = l + 2 ; r <= n ; r++ )	
		{
			if(a[l] < a[r])
			{
				sum += a[r];
				if(sum > (1 << ((int)log2(a[l]) + 1))) break;
				continue;
			}
			if((a[l] ^ a[r]) == sum) cnt++;
			sum += a[r];
			if(sum > (1 << ((int)log2(a[l]) + 1))) break;
		}
	}
	reverse(a + 1 , a + n + 1);
	for(int l = 1 ; l <= n ; l++ )
	{
		sum = a[l + 1];
		for(int r = l + 2 ; r <= n ; r++ )	
		{
			if(a[l] <= a[r])
			{
				sum += a[r];
				if(sum > (1 << ((int)log2(a[l]) + 1))) break;
				continue;
			} 
			if((a[l] ^ a[r]) == sum) cnt++;
			sum += a[r];
			if(sum > (1 << ((int)log2(a[l]) + 1))) break;
		}
	}
	printf("%d" , cnt);
    return 0;
}
/*
5
2 0 2 0 2
*/