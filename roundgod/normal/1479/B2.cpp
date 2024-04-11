#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int last[MAXN],dp[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int c=-1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(c==-1)
        {
            c=a[i];
            cnt=1;
        }
        else if(c!=a[i])
        {
            v.push_back(P(c,cnt));
            c=a[i]; cnt=1;
        }
        else cnt++;
    }
    v.push_back(P(c,cnt));
    memset(last,-1,sizeof(last));
    dp[0]=0;
    last[v[0].F]=0;
    for(int i=1;i<(int)v.size();i++)
    {
        dp[i]=dp[i-1];
        if(last[v[i].F]!=-1)
        {
            dp[i]=max(dp[i],1+dp[last[v[i].F]+1]);
        }
        last[v[i].F]=i;
    }
    printf("%d\n",(int)v.size()-dp[(int)v.size()-1]);
    return 0;
}