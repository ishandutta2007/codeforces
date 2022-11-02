#include<bits/stdc++.h>
using namespace std;
int n = 500000 , q , ctl = 800 , opt , x , y;
long long ans[810][810] , sum , a[550000];
inline int read()
{
    int a = 0 , f = 0;
    char c = getchar();
    while(!isdigit(c))
	{
        if(c == '-') f = 1;
        c = getchar();
    }
    while(isdigit(c))
	{
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
    if(f) a = -a;
    return a;
}
int main()
{
	q = read();
	while(q--)
	{
		opt = read(); x = read(); y = read();
		if(opt == 1)
		{
			a[x] += y;
			for(int i = 1 ; i <= ctl ; i++ ) ans[i][x % i] += y;
		}
		else
		{
			if(x <= ctl) printf("%lld\n" , ans[x][y]);
			else
			{
				sum = 0;
				for(int i = y ; i <= n ; i += x ) sum += a[i];
				printf("%lld\n" , sum);
			}
		}
	}
	return 0;
}