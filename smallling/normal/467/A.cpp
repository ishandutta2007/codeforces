#include<cstdio>

int n,p,q,ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p,&q);
        if(q-p>=2)ans++;
    }
    printf("%d",ans);
}