#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
typedef pair<int,int> P;
int n,k,m,a;
int g[MAXN];
pair<P, int> vote[MAXN];
int ans[MAXN];
bool cmp(pair<P,int> x, pair<P,int> y)
{
    if(x.first.first!=y.first.first) return x.first.first>y.first.first;
    return x.first.second<y.first.second;
}
int main()
{
    scanf("%d %d %d %d",&n,&k,&m,&a);
    memset(vote,0,sizeof(vote));
    for(int i=0;i<MAXN;i++)
        vote[i].second=i;
    for(int i=0;i<a;i++)
    {
        scanf("%d",&g[i]);
        g[i]--;
        vote[g[i]].first.first++;
        vote[g[i]].first.second=i+1;
    }
    sort(vote,vote+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(m-a==0&&vote[i].first.first==0)
        {
            ans[vote[i].second]=3;
            continue;
        }
        if(i<=k-1)
        {
            if(vote[i].first.first==0)
            {
                ans[vote[i].second]=2;
                continue;
            }
            if(k==n)
            {
                ans[vote[i].second]=1;
                continue;
            }
            int cnt=0;
            for(int j=i+1;j<=k;j++)
                cnt+=vote[i].first.first-vote[j].first.first+1;
            if(cnt>m-a) ans[vote[i].second]=1; else ans[vote[i].second]=2;
        }
        else
            if(vote[i].first.first+m-a>vote[k-1].first.first) ans[vote[i].second]=2; else ans[vote[i].second]=3;
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}