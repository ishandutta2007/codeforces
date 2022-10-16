#include <string.h>
#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
int a[105],f[105],p[105],ans;
int main()
{
    int n=read();
    while(n--)
    {
        int n=read(),k=read();ans=0;memset(f,0,sizeof(f));memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        {
            a[i]=read();
            if(f[a[i]]==0)p[ans++]=a[i],f[a[i]]=1;
        }
        int qwq=0;
        if(ans>k){puts("-1");continue;}
        printf("%d\n",10000/n*k);
        for(int i=0;i<10000/n;i++)
            for(int j=0;j<k;j++)printf("%d ",j<ans?p[j]:p[0]);
        puts("");
    }
    return 0;
}