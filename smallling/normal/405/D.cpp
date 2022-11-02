#include<cstdio>

using namespace std;

int n,tot,o,f[1000100],a[1000100];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&o),f[o]=1;
    for(int i=1;i<=1000000;i++)
        if(f[i]&&!f[1000000-i+1])a[++tot]=1000000-i+1,f[a[tot]]=1;
    for(int i=1;i<=1000000&&tot<n;i++)
        if(!f[i]&&!f[1000000-i+1])a[++tot]=i,f[a[tot]]=1,a[++tot]=1000000-i+1,f[a[tot]]=1;
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d ",a[i]);
}