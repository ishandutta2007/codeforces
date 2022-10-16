#include <algorithm>
#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
char c[114514];
int main()
{
    int n=read();
    while(n--)
    {
        int n=read(),k=read();
        scanf("%s",c);std::sort(c,c+n);
        if(c[0]==c[k-1])
        {
            putchar(c[0]);
            if(c[k]==c[n-1])
            {
                for(int i=k;i<n;i+=k)putchar(c[k]);
            }
            else
            {
                printf("%s",c+k);
            }
        }
        else putchar(c[k-1]);
        puts("");
    }
    return 0;
}