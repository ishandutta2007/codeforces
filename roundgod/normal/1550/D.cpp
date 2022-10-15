#include<bits/stdc++.h>
#define MAXN 200005
#define MAXK 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l,r;
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int type[MAXN];
int cnt[4];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k||k<0) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
vector<P> v;
int calc()
{
    if(cnt[0]) return 0;
    int ans=0;
    add(ans,comb(cnt[3],n/2-cnt[1]));
    if(n%2) add(ans,comb(cnt[3],n/2-cnt[2]));
    return ans;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&l,&r);
        int ans=0;
        for(int i=1;i<=n;i++) type[i]=0;
        memset(cnt,0,sizeof(cnt));
        v.clear(); cnt[3]=n;
        for(int i=1;i<=n;i++)
        {
            type[i]=3;
            v.push_back(P(r-i+1,2*i)); v.push_back(P(i-l+1,2*i+1));
        }
        sort(v.begin(),v.end(),greater<P>());
        int curt=1;
        while(v.size())
        {
            P p=v.back(); 
            int t=p.F;
            int val=calc();
            while(v.size()&&v.back().F==t)
            {
                int res=v.back().S; v.pop_back();
                int id=res/2,sgn=res&1;
                cnt[type[id]]--; type[id]^=(1<<sgn); cnt[type[id]]++;
            }
            add(ans,1LL*(t-curt)*val%MOD);
            curt=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}