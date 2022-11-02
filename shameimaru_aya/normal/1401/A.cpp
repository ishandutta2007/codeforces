#include<bits/stdc++.h>
using namespace std;
int T , n , k , ans;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &k);
		if(n < k) ans = k - n;
		else ans = min((n - k) % 2 , n - k);
		printf("%d\n" , ans);
	}
    return 0;
}