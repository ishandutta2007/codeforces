#include <stdio.h>
#include <algorithm>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
signed main()
{
    printf("? ");
    for(int i=0;i<100;i++)printf("%d ",i);
    puts("");fflush(stdout);
    int x=read();
    printf("? ");
    for(int i=1;i<=100;i++)printf("%d ",i<<7);
    puts("");fflush(stdout);
    int y=read();
    printf("! %d\n",(x&0x3f80)|(y&0x7f));
    fflush(stdout);
}