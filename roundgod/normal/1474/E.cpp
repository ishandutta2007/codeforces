#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> l,r;
int p[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        l.clear(); r.clear();
        ll ans=0;
        for(int i=2;i<=n;i++)
        {
            if(1LL*(i-1)*(i-1)>1LL*(n-i)*(n-i)) l.push_back(i); else r.push_back(i);
            ans+=max(1LL*(i-1)*(i-1),1LL*(n-i)*(n-i));
        } 
        printf("%lld\n",ans);
        int now=n;
        for(auto x:r)
        {
            p[now]=x;
            now=x;
        }
        p[now]=1;
        now=1;
        for(auto x:l)
        {
            p[now]=x;
            now=x;
        }
        for(int i=1;i<=n;i++) printf("%d ",p[i]);
        puts("");
        printf("%d\n",n-1);
        while(p[n]!=1) {printf("%d %d\n",p[n],n); swap(p[n],p[p[n]]);}
        while(p[1]!=1) {printf("%d %d\n",p[1],1); swap(p[1],p[p[1]]);}
    }
    return 0;
}