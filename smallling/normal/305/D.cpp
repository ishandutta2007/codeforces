#include<cstdio>
#include<algorithm>

#define N 1000010
#define mo 1000000007

using namespace std;

int n,m,l,firsty,lastx,cnt,cnt1,cnt2,x,y,ans,Pow[N];

int main()
{
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(y==x+1)continue;
        if(y-x!=l+1)return puts("0"),0;
        if(!firsty)
        {
            firsty=y;
            lastx=x;
            continue;
        }
        if(x>=firsty)return puts("0"),0;
        lastx=x;cnt++;
    }
    ans=0;Pow[0]=1;
    for(int i=1;i<=n;i++)
    {
        Pow[i]=Pow[i-1]*2;
        if(Pow[i]>=mo)Pow[i]-=mo;
    }
    if(!firsty)goto la;
    for(int i=max(l+1,lastx)+1;i<firsty;i++)
    {
        ans=ans+Pow[min(n-i,l)-cnt-1];
        if(ans>=mo)ans-=mo;
    }
    ans+=Pow[min(n-firsty,l)-cnt];
    if(ans>=mo)ans-=mo;
    printf("%d\n",ans);
    return 0;
    la:;
    for(int i=l+2;i<=n;i++)
    {
        ans=ans+Pow[min(n-i,l)];
        if(ans>=mo)ans-=mo;
    }
    printf("%d\n",ans+1);
}