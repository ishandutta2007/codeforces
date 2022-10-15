#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 1000000000
using namespace std;
int bit[2*MAXN+1],n,k;
int m[MAXN],cnt[MAXN],c[MAXN];
vector<vector<int> > way;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&m[i]);
        cnt[m[i]]++;
    }
    for(int i=k-1;i>=1;i--) cnt[i]+=cnt[i+1];
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    int ans=0;
    for(int i=1;i<=k;i++) ans=max(ans,(cnt[i]+c[i]-1)/c[i]);
    printf("%d\n",ans);
    way.resize(ans);
    sort(m+1,m+n+1);
    for(int i=n;i>=1;i--) way[i%ans].push_back(m[i]);
    for(auto v:way)
    {
        printf("%d ",(int)v.size());
        for(auto x:v) printf("%d ",x);
        puts("");
    }
    return 0;
}