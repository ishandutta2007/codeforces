#include <stdio.h>
#include <string.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),f=0;
		int a=read(),b=read();
		if(a<b)f=1;
		for(int i=1;i<n;i++)
		{
			int c=read(),d=read();
			if(c-a<d-b||c-a<0||d-b<0||c<d)f=1;
			a=c,b=d;
		}
		if(f)puts("NO");
		else puts("YES");
	}
}