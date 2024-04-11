#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
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
    f[1]=1LL*(s-1)*(s-1)%MOD*pow_mod(s,MOD-2)%MOD;
    for(int i=1;i<=100000;i++)
    {
        f[i+1]=1LL*((2LL*(s-i)*f[i]-1LL*(s-i)*f[i-1]-(s-1))%MOD)*pow_mod(s-i,MOD-2)%MOD;
        if(f[i+1]<0) f[i+1]+=MOD;
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,f[a[i]]);
    printf("%d\n",ans);
    return 0;
}