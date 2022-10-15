#include<bits/stdc++.h>
#define MAXN 100005
#define INF 4000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x,y;
int dx[6]={1,0,-1,-1,0,1},dy[6]={1,1,0,-1,-1,0};
int c[6];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        for(int i=0;i<6;i++) scanf("%d",&c[i]);
        for(int tt=0;tt<100;tt++)
        {
            for(int i=0;i<6;i++)
            {
                int pre=(i+5)%6,suf=(i+1)%6;
                c[i]=min(c[i],c[pre]+c[suf]);
            }
        }
        ll ans=INF;
        int a,b;
        a=x; b=y-a; if(a>=0&&b>=0) ans=min(ans,1LL*a*c[0]+1LL*b*c[1]);
        a=y; b=-x; if(a>=0&&b>=0) ans=min(ans,1LL*a*c[1]+1LL*b*c[2]);
        b=-y; a=-x-b;  if(a>=0&&b>=0) ans=min(ans,1LL*a*c[2]+1LL*b*c[3]);
        a=-x; b=-y-a; if(a>=0&&b>=0) ans=min(ans,1LL*a*c[3]+1LL*b*c[4]);
        a=-y; b=x; if(a>=0&&b>=0) ans=min(ans,1LL*a*c[4]+1LL*b*c[5]);
        b=y; a=x-b; if(a>=0&&b>=0) ans=min(ans,1LL*a*c[5]+1LL*b*c[0]);
        printf("%lld\n",ans);
    }
}