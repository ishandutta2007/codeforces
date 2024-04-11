#include<bits/stdc++.h>
using namespace std;
long long T , a , b , x , y , cntx , cnty , ans , sum , qwq;
int main()
{
	cin >> T;
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld%lld%lld%lld%lld" , &a , &b , &cntx , &cnty , &x , &y);
		if(x > y) swap(x , y) , swap(cntx , cnty);
		for(int i = 0 ; i <= cntx ; i++ )
		{
			if(a < 0) break;
			sum = i;
			sum += min(cnty , a / y);
			qwq = min(cnty , a / y);
			if((cntx - i) * x <= b)
			{
				sum += cntx - i + min(cnty - qwq , (b - (cntx - i) * x) / y);
			}
			else
			{
				sum += b / x;
			}
			ans = max(ans , sum);
			a -= x;
		}
		printf("%lld\n" , ans);
	}
    return 0;
}