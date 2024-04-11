#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 5000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int t,l,r;
vector<int> a,b;
ll dp[30][2][2][2][2];
ll solve(int now,int af1,int af2,int bf1,int bf2)
{
    if(now==30) return 1;
    if(dp[now][af1][af2][bf1][bf2]!=-1) return dp[now][af1][af2][bf1][bf2];
    dp[now][af1][af2][bf1][bf2]=0;
    int alow=(af1?0:a[now]),ahigh=(af2?1:b[now]),blow=(bf1?0:a[now]),bhigh=(bf2?1:b[now]);
    for(int i=alow;i<=ahigh;i++)
        for(int j=blow;j<=bhigh;j++)
        {
            if(i&&j) continue;
            dp[now][af1][af2][bf1][bf2]+=solve(now+1,(af1||i>a[now]),(af2||i<b[now]),(bf1||j>a[now]),(bf2||j<b[now]));
        }
    return dp[now][af1][af2][bf1][bf2];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        a.clear(); b.clear();
        while(l) {a.push_back(l&1); l>>=1;}
        while(r) {b.push_back(r&1); r>>=1;}
        while(a.size()<30) a.push_back(0);
        while(b.size()<30) b.push_back(0);
        reverse(a.begin(),a.end()); reverse(b.begin(),b.end());
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(0,0,0,0,0));
    }
    return 0;
}