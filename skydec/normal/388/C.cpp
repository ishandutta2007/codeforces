#include<stdio.h>
#include<algorithm>
#define MAXN 1005
using namespace std;
int b[MAXN];int ans;int sum;int tot;
int n;
bool cmp(int x,int y){return x>y;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int s;scanf("%d",&s);
            for(int j=1;j<=s;j++)
            {
                    int v;scanf("%d",&v);sum+=v;
                    if((s&1)&&(j*2-1==s))b[++tot]=v;
                    if(j*2<=s)ans+=v;
                    }
                    }
    sort(b+1,b+1+tot,cmp);
    for(int i=1;i<=tot;i++)ans+=((i)%2)*b[i];
    printf("%d %d\n",ans,sum-ans);
    return 0;
}