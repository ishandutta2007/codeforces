#include<cstdio>
#include<map>

using namespace std;

int n,l,x,y,b1,b2,o,ans,tot,a[200010];
map<int,int>b,bb;

int main()
{
    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o);
        b[x+o]=1;
        bb[y+o]=1;
        bb[o-y]=1;
        b[o-x]=1;
        if(b[o])b1=1;
        a[++tot]=x+o;
        a[++tot]=o-x;
        if(bb[o])b2=1;
    }
    if(b1&&b2)return puts("0"),0;
    for(int i=1;i<=tot;i++)
        if(bb[a[i]]&&a[i]<=l&&a[i]>=0)
        {
            ans=a[i];
            break;
        }
    if(ans)
    {
        puts("1");
        printf("%d",ans);
        return 0;
    }
    printf("%d\n",(b1^1)+(b2^1));
    if(!b1)printf("%d ",x);
    if(!b2)printf("%d",y);
}