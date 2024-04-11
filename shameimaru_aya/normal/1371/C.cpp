#include<bits/stdc++.h>
using namespace std;
int T;
long long a , b , c , d; 
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld" , &a , &b , &c , &d);
		int qwq = min(c , d);
		a -= qwq; b -= qwq; c -= qwq; d -= qwq;
//		cerr << a << ' ' << b << ' ' << c << ' ' << d << endl;
		if(a + b < c + d || a < 0 || b < 0)
		{
			printf("No\n");
			continue;
		}
		if(d == 0) printf("Yes\n");
		if(d != 0) 
		{
			if(min(a , b) >= d) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}