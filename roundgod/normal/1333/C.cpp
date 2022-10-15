#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll s[MAXN];
map<ll,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=0;
    mp[0]=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(mp.find(s[i])!=mp.end()) l=max(l,mp[s[i]]+1);
        ans+=i-l;
        mp[s[i]]=i;
    }
    printf("%lld\n",ans);
    return 0;
}