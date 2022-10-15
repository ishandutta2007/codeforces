#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
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
map<int,int> mp;
int main()
{
    for(int i=1;i<500;i++)
    {
        f[i+1]=2LL*f[i]%MOD;
        dec(f[i+1],1);
    }
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1) mp[i]++; else mp[a[i]]++;
    }
    int ans=0;
    for(auto p:mp) add(ans,f[p.S]);
    dec(ans,f[n]);
    printf("%d\n",ans);
    return 0;
}