#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN];
vector<int> v;
bool dp[MAXN],ndp[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&p[i]);
        int now=1;
        while(now<=2*n)
        {
            int cur=p[now],cnt=1;
            now++;
            while(now<=2*n&&p[now]<cur) now++,cnt++;
            v.push_back(cnt);
        }
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<(int)v.size();i++)
        {
            memset(ndp,false,sizeof(ndp));
            for(int j=0;j<=n;j++)
            {
                if(dp[j]) ndp[j]=true;
                if(dp[j]&&j+v[i]<=n) ndp[j+v[i]]=true;
            }
            swap(dp,ndp);
        }
        if(dp[n]) puts("YES"); else puts("NO"); 
    }
    return 0;
}