#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin >> a;
	int ans = 0;
	int cnt = 0;
	//printf("%d\n",ans);
	long long b = a;
	while(b>0)
	{
		ans += (int)(b%10);
		cnt++;
		//printf("%d\n",ans);
		b/=10;
	}
	a -= pow(10,cnt-1);
	a ++;
	ans = 0;
	//printf("%lld\n",a);
	while(a>0)
	{
		ans += (int)(a%10);
		a/=10;
	}
	printf("%d\n",ans+9*(cnt-1));
	return 0;
}