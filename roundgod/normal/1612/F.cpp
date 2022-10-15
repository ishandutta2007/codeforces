#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
unordered_set<ll> s;
/*
suppose n<m
dp[i][j]: maximum number of x when i op has been done and y is j
*/  
void update(int &x,int y) {x=max(x,y);}
int dp[MAXN],ndp[MAXN],x[MAXN],y[MAXN],ans; 
bool swapped=false;
void solve()
{
    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    int res=INF,id=-1;
    for(int i=0;i<30;i++)
    {
        memset(ndp,-1,sizeof(ndp));
        for(int j=1;j<=m;j++)
        {
            if(dp[j]==-1) continue;
            int nxt=j+dp[j]+(s.count(1LL*(dp[j]-1)*m+j-1)?1:0);
            update(ndp[min(nxt,m)],dp[j]);
            update(ndp[j],min(nxt,n));
        }
        swap(dp,ndp);
        for(int j=m;j>=1;j--) 
            if(dp[j]==n)
            {
                res=i+1;
                id=j;
                break;
            }
        if(id!=-1) break;
    }
    while(id<m)
    {
        id+=n+(s.count(1LL*(n-1)*m+id-1)?1:0);
        res++;
    }
    ans=min(ans,res);
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        s.insert(1LL*(x[i]-1)*m+y[i]-1);
    }
    ans=INF; solve();
    swap(n,m);
    s.clear();
    for(int i=0;i<q;i++) 
    {
        swap(x[i],y[i]);
        s.insert(1LL*(x[i]-1)*m+y[i]-1);
    }
    solve();
    printf("%d\n",ans);
    return 0;
}