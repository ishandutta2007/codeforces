#include <stdio.h>
#include <math.h>
#define int long long
inline int read()
{
	int num = 0,f=1; char c = getchar();
	while (c<48 || c>57){if(c=='-')f=-1;c = getchar();}
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num*f;
}
int upd[25] = {1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401,22369621};
signed main()
{
	int t=read();
	while(t--)
	{
		int n=read();
		if(n&(n+1))
		{
			int p=1;
			while(n)p<<=1,n>>=1;
			printf("%lld\n",p-1);
		}
		else
		{
			int p=log2(n);
			printf("%lld\n",upd[p-1]);
		}
	}
	return 0;
}