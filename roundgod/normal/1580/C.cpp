#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define right sdkas
#define left sdkoads
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x[MAXN],y[MAXN];
const int threshold=500;
int cnt[MAXN];
int last[MAXN];
int modcnt[505][505];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=m;i++)
    {
        int op,k;
        scanf("%d%d",&op,&k);
        int len=x[k]+y[k];
        if(len>threshold)
        {
            if(op==1)
            {
                last[k]=i;
                for(int t=i;t<=m;t+=len)
                {
                    int l=t+x[k],r=min(m,t+len-1);
                    if(l>m) break;
                    cnt[l]++; cnt[r+1]--;
                }
            }
            else
            {
                for(int t=last[k];t<=m;t+=len)
                {
                    int l=t+x[k],r=min(m,t+len-1);
                    if(l>m) break;
                    cnt[l]--; cnt[r+1]++;
                    if(l<i-1) cnt[i]--; if(r+1<i-1) cnt[i]++;
                }
            }
        }
        else
        {
            if(op==1)
            {
                last[k]=i;
                if(i+x[k]<=m) 
                for(int t=i+x[k];t<=i+len-1;t++) modcnt[len][t%len]++;
            }
            else
            {
                if(last[k]+x[k]<=m) 
                for(int t=last[k]+x[k];t<=last[k]+len-1;t++) modcnt[len][t%len]--;
            }
        }
        cnt[i]+=cnt[i-1];
        int ans=cnt[i];
        for(int mod=1;mod<=500;mod++) ans+=modcnt[mod][i%mod];
        printf("%d\n",ans);
    }
    return 0;
}