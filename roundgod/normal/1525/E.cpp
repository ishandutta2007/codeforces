#include<bits/stdc++.h>
#define MAXN 21
#define MAXM 50005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int d[MAXM][MAXN];
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
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&d[j][i]);
    for(int i=0;i<m;i++) sort(d[i],d[i]+n);
    int ans=m;
    int fact=1;
    for(int i=1;i<=n;i++) fact=1LL*fact*i%MOD;
    fact=pow_mod(fact,MOD-2);
    for(int i=0;i<m;i++)
    {
        int res=1;
        for(int j=n-1;j>=0;j--) res=1LL*res*max(0,d[i][j]-(j+1))%MOD;
        dec(ans,1LL*res*fact%MOD);
    }
    printf("%d\n",ans);
    return 0;
}