#include <stdio.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
signed main()
{
	int T(read());
	while(T--)
	{
		int n=read();
		// 2 3 5 7 11 13 17 19 23 29
		// 6 10 14 15 21 22 26 33 34
		if(n>44)printf("YES\n6 10 14 %d\n",n-30);
		else if(n<=30)puts("NO");
		else if(n!=36&&n!=40&&n!=44)printf("YES\n%d 6 10 14\n",n-30);
		else if(n==36)puts("YES\n5 6 10 15");
		else if(n==40)puts("YES\n6 9 10 15");
		else puts("YES\n6 10 13 15");
	}
	getchar();
	return 0;
}