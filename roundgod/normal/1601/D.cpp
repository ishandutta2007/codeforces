#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,d;
int dp[MAXN];
vector<pair<P,int> > v;
int main()
{
    scanf("%d%d",&n,&d);
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<d) continue;
        if(y<=x) {ans++; v.push_back(make_pair(P(x,y),1)); continue;}
        v.push_back(make_pair(P(y,x),0));
    }
    sort(v.begin(),v.end());
    int mx=0;
    for(int i=0;i<(int)v.size();i++)
    {
        mx=max(mx,v[i].F.S);
        if(i==0) dp[i]=0; else dp[i]=dp[i-1];
        if(v[i].S==0)
            if(mx==v[i].F.S) dp[i]=max(dp[i],dp[upper_bound(v.begin(),v.end(),make_pair(P(v[i].F.S,INF),INF))-v.begin()-1]+1);
    }
    printf("%d\n",ans+dp[(int)v.size()-1]);
    return 0;
}