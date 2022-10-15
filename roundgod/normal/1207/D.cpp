#include<bits/stdc++.h>
#define MAXN 300005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN];
int n;
int a[MAXN],b[MAXN];
map<int,int> mp;
map<P,int> mp2;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    fact[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    int ans=fact[n];
    mp.clear();
    for(int i=1;i<=n;i++) mp[a[i]]++;
    int res=1;
    for(auto x:mp) res=1LL*res*fact[x.S]%MOD;
    dec(ans,res);
    mp.clear();
    for(int i=1;i<=n;i++) mp[b[i]]++;
    res=1;
    for(auto x:mp) res=1LL*res*fact[x.S]%MOD;
    dec(ans,res);
    mp.clear();
    for(int i=1;i<=n;i++) mp2[P(a[i],b[i])]++;
    res=1;
    bool f=true;
    int lastx=-INF,lasty=-INF;
    for(auto x:mp2)
    {
        if(x.F.F<lastx||x.F.S<lasty) f=false;
        res=1LL*res*fact[x.S]%MOD;
        lastx=x.F.F; lasty=x.F.S;
    }
    if(f) add(ans,res);
    printf("%d\n",ans);
    return 0;
}