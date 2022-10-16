#include <algorithm>
#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
int c[114514];
int main()
{
    int n=read();
    while(n--)
    {
        int n=read(),ans=0,p=1;
        while(n>0)
        {
            if(n>p)c[ans++]=p;
            else c[ans++]=n;
            n-=p;
            p<<=1;
        }
        std::sort(c,c+ans);;
        printf("%d\n",ans-1);
        for(int i=1;i<ans;i++)
        {
            printf("%d ",c[i]-c[i - 1]);
        }
        puts("");
    }
    return 0;
}