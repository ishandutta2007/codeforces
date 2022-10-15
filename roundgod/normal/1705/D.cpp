#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,n,k,a[MAXN];
char s[MAXN],t[MAXN];
int dp[MAXN][3];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&tot);
    while(tot--)
    {
        scanf("%d",&n);
        scanf("%s",s+1); scanf("%s",t+1);
        if((s[1]!=t[1])||(s[n]!=t[n])) {puts("-1"); continue;}
        vector<int> v1,v2;
        for(int i=2;i<=n;i++) if(s[i]!=s[i-1]) v1.push_back(i);
        for(int i=2;i<=n;i++) if(t[i]!=t[i-1]) v2.push_back(i);
        if(v1.size()!=v2.size()) {puts("-1"); continue;}
        ll ans=0;
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        for(int i=0;i<(int)v1.size();i++) ans+=max(v1[i]-v2[i],v2[i]-v1[i]);
        printf("%lld\n",ans);
    }
    return 0;
}