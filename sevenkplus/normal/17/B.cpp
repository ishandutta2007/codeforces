#include<cstdio>
#include<algorithm>
#define Max 1000001
int a[1000],n,m;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;scanf("%*d"),a[i++]=Max);
    scanf("%d",&m);
    for(int i=0,x,y,z;i<m;scanf("%d%d%d",&x,&y,&z),a[--y]=std::min(a[y],z),i++);
    std::sort(a,a+n);
    if(a[n-2]==Max)
        puts("-1");
    else
    {
        int s=0;
        for(int i=0;i<n-1;s+=a[i++]);
        printf("%d\n",s);
    }
    return 0;
}