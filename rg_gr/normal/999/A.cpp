#include <stdio.h>
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
#undef T

int main() {
	int n=read(),k=read(),ans=0,f=0;
	while(n--)
	{
	    int a=read();
	    if(f==0&&a<=k)ans++;
	    else if(a>k)f=n;
	}
	printf("%d\n",ans+f);
	return 0;
}