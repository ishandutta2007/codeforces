#include <stdio.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
int main()
{
    int T=read();
    while(T--) {
        int n=read(),s=(n-1)/4+1;
        for(int i=0;i<n-s;i++)putchar('9');
        for(int i=0;i<s;i++)putchar('8');
        puts("");
    }
    return 0;
}