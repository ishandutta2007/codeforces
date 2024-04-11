#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%lld" , &n);
		if(n & 1)
		{
			if(n == 1) printf("-1\n");
			else printf("2\n");
		}
		else
		{
			if(n <= 10)
			{
				int gg = 1;
				for(long long i = 2 ; i <= n ; i++ )
				{
					if(n >= (i + 1) * i / 2 && n % i == ((i + 1) * i / 2) % i)
					{
						printf("%d\n" , i); gg = 0;
						break;
					}
				}
				if(gg) printf("-1\n");
			}
			else
			{
				long long qwq = n , s = 1;
				while(qwq % 2 == 0) qwq /= 2 , s *= 2;
				if(qwq >= (s * 2 + 1)) printf("%lld\n" , s * 2);
				else 
				{
					if(qwq != 1) printf("%lld\n" , qwq);
					else printf("-1\n");
				}
			}
		}
	}
	return 0;
}
/*
*/