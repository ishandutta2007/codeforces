#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN],c[MAXN],d[MAXN],type[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&b[i]);
            c[a[i]]=b[i];
        }
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&d[i]);
            type[a[i]]=0;
            if(d[i]==b[i]) type[a[i]]=2; else if(d[i]) type[a[i]]=1;
        }
        int ans=1;
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(c[i]==i) {continue;}
                bool has1=false,has2=false;
                int now=i;
                while(!vis[now])
                {
                    vis[now]=true;
                    if(type[now]==1) has1=true;
                    if(type[now]==2) has2=true;
                    now=c[now];
                }
                if(!has1&&!has2) ans=2LL*ans%MOD;
                if(has1&&has2) ans=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}