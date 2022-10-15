#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define REV 500000004
#define F first
#define S second
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],f[MAXN];
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
int main()
{
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    for(int i=1;i<s;i++)
    {
        f[i+1]=(1LL*(n-2)*i+s)%MOD*f[i]%MOD;
        dec(f[i+1],1LL*(n-1)*i%MOD*f[i-1]%MOD);
        dec(f[i+1],1LL*(n-1)*i%MOD);
        f[i+1]=1LL*f[i+1]*pow_mod(s-i,MOD-2)%MOD;
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,f[a[i]]);
    dec(ans,f[s]);
    printf("%d\n",ans);
    return 0;
}