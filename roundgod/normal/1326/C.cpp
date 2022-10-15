#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
vector<int> v;
int main()
{
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]>=n-k+1)
        {
            ans+=a[i];
            v.push_back(i);
        }
    }
    int res=1;
    for(int i=1;i<(int)v.size();i++) res=1LL*res*(v[i]-v[i-1])%MOD;
    printf("%lld %d\n",ans,res);
    return 0;
}