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
int t,n,k,b[MAXN],c[MAXN];
int cnt[MAXN],ans[MAXN];
vector<int> G[MAXN];
int nxt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n+1;i++) G[i].clear(),nxt[i]=-1;
        int st=0,type=1;
        k=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&b[i]);
            if(b[i]>i) k++;
            if(b[i]==n+1) {st=n+1;}
            G[b[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) if(b[i]!=0&&b[i]!=n+1) nxt[b[b[i]]]=b[i];
        int tot=0;
        while(st!=-1)
        {
            int sz=(int)G[st].size(); 
            if(nxt[st]!=-1)
            {
                int last=nxt[st];
                for(auto x:G[st])
                {
                    if(x==last) continue;
                    ans[++tot]=x;
                }
                ans[++tot]=last;
            }
            else
            {
                for(auto x:G[st]) ans[++tot]=x;
            }
            st=nxt[st];
            type^=1;
        }
        printf("%d\n",k);
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}