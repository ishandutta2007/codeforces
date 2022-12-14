#include<bits/stdc++.h>
using namespace std;
int mx[500000];
int mn[500000];
set<int> rows;
bool isCol[500000];
int nxt[500000];
int L[500000];
int R[1000000];
long long dp[300005][6];
vector<int> row[500000];
long long dist(int x,int y)
{
    return abs(x-y);
}
long long solve(int i,int j)
{
    int loc = row[i][j];
    if (nxt[i]==0)
        return min(dist(loc,mn[i])+dist(mn[i],mx[i]),dist(loc,mx[i])+dist(mx[i],mn[i]));
    if (dp[i][j]!=-1)return dp[i][j];
    int v = nxt[i];
    long long ret = 1e15;
    for (int x=0;x<row[v].size();x++)
    {
        int loc2 = row[v][x],cur;
        cur = min(dist(loc,mn[i])+dist(mn[i],mx[i])+dist(mx[i],loc2),
                  dist(loc,mx[i])+dist(mx[i],mn[i])+dist(mn[i],loc2));
        ret=min(ret,cur+solve(v,x)+nxt[i]-i);
    }
    return dp[i][j]=ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for (int i=1;i<=n;i++)
        mn[i]=1e9;
    for (int i=0;i<k;i++)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        rows.insert(r);
        mx[r]=max(mx[r],c);
        mn[r]=min(mn[r],c);
    }
    int last=1;
    for (auto x:rows)
    {
        if (x!=last)nxt[last]=x;
        last=x;
    }
    for (int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        isCol[x]=1;
    }
    L[0]=-1,R[m+1]=-1;
    for (int i=1;i<=m;i++)
    {
        L[i]=L[i-1];
        if (isCol[i])L[i]=i;
    }
    for (int i=m;i>=1;i--)
    {
        R[i]=R[i+1];
        if (isCol[i])R[i]=i;
    }
    for (int i=1;i<=n;)
    {
        if (nxt[i]==0)break;
        int S = mn[nxt[i]];
        int E = mx[nxt[i]];
        if (L[S]!=-1)row[nxt[i]].push_back(L[S]);
        if (L[E]!=-1)row[nxt[i]].push_back(L[E]);
        if (R[S]!=-1)row[nxt[i]].push_back(R[S]);
        if (R[E]!=-1)row[nxt[i]].push_back(R[E]);
        i=nxt[i];
    }
    row[1].push_back(1);
    if (mn[1]==1e9)
        mn[1]=1,mx[1]=1;
    printf("%lld\n",solve(1,0));
}