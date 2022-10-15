#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN];
int sum[MAXN],cnt[MAXN];
int fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    fact[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    int rem=0,s=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&c[i]); 
        add(s,c[i]);
        if(c[i]&1) {rem++; sum[2]++; sum[c[i]+1]--;}
        else {sum[1]++; sum[c[i]+1]--;}
    }
    for(int i=2;i<=1000000;i++) sum[i]+=sum[i-2];
    int r=s,l=1,ans=0,ways=1;
    for(int i=1000000;i>=1;i--)
    {
        int c=sum[i];
        add(ans,1LL*(2LL*r-c+1+MOD)%MOD*c%MOD*INV%MOD*i%MOD);
        dec(ans,1LL*(2LL*l+c-1)%MOD*c%MOD*INV%MOD*i%MOD);
        dec(r,c); add(l,c);
        ways=1LL*ways*fact[c]%MOD*fact[c]%MOD;
    }
    ways=1LL*ways*fact[rem]%MOD;
    printf("%d %d\n",ans,ways);
    return 0;
}