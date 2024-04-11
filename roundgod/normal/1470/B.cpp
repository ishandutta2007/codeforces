#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,tot,q,a[MAXN];
vector<int> v[MAXN];
bool isprime[MAXN];
int id[MAXN];
map<int,int> cnt;
map<vector<int>,int> mp;
int get_id(int x)
{
    if(v[x].size()==0) return 0;
    if(mp.find(v[x])==mp.end()) mp[v[x]]=++tot;
    return mp[v[x]];
}
int main()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=1000000;i++)
    {
        if(isprime[i])
        {
            v[i].push_back(i);
            for(int j=2*i;j<=1000000;j+=i)
            {
                isprime[j]=false;
                int tmp=j,cnt=0;
                while(tmp%i==0) tmp/=i,cnt++;
                if(cnt&1) v[j].push_back(i);
            }
        }
    }
    tot=0;
    for(int i=1;i<=1000000;i++) id[i]=get_id(i);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt.clear();     
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[id[a[i]]]++;
        }
        int ans0=0,ans1=0,res0=0;
        for(auto p:cnt)
        {
            ans0=max(ans0,p.S);
            if(p.F==id[1]||p.S%2==0) res0+=p.S; else ans1=max(ans1,p.S);
        }
        ans1=max(ans1,res0);
        scanf("%d",&q);
        while(q--)
        {
            ll w;
            scanf("%lld",&w);
            if(w>=1) printf("%d\n",ans1); else printf("%d\n",ans0);
        }
    }
    return 0;
}