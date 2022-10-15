#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 2000000000LL
#define MOD 1000000007
#define F first
#define S second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,d[2][MAXN];
int pos[MAXN];
vector<int> ans;
bool check(int dif)//p1=INF p2=INF+dif
{
    ans.clear();
    multiset<ll> s1,s2;
    for(int i=1;i<=n;i++)
    {
        s1.insert(d[0][i]);
        s2.insert(d[1][i]);
    }
    while(s1.size())
    {
        auto p=*(--s1.end());
        s1.erase(--s1.end());
        if(s2.count(p+dif))
        {
            s2.erase(s2.find(p+dif));
            ans.push_back(INF-p);
            continue;
        }
        else 
        {
            ll x=max(dif-p,p-dif);
            if(!s2.count(x)) return false;
            s2.erase(s2.find(x));
            ans.push_back(INF+p);
        }
    }
    return true;
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
                scanf("%lld",&d[i][j]);
        bool f=false;
        ll dif=-INF;
        for(int i=1;i<=n;i++)
        {
            if(check(max(d[0][1]-d[1][i],d[1][i]-d[0][1])))
            {
                f=true;
                dif=max(d[0][1]-d[1][i],d[1][i]-d[0][1]);
                break;
            }
            if(check(d[0][1]+d[1][i]))
            {
                f=true;
                dif=d[0][1]+d[1][i];
                break;
            }
        }
        if(!f) puts("NO");
        else
        {
            puts("YES");
            ll mini=INF;
            for(int i=0;i<n;i++) mini=min(mini,ans[i]);
            for(int i=0;i<n;i++) printf("%lld ",ans[i]-mini);
            printf("\n");
            printf("%lld %lld\n",INF-mini,INF+dif-mini);
        }
    }
    return 0;
}