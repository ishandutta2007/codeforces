#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,l[MAXN],s[MAXN],c[MAXN];

int dp[MAXN][MAXN];
bool has[MAXN][MAXN];

vector<P> states;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void upd(int &a,int b) {a=max(a,b);}
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
P calc(int x,int y,int z)
{
    if(x==z) return P(0,y);
    if(y==1) return P(0,0);
    P p=calc(x+1,y/2,z);
    p.F+=c[x+1]*(y/2);
    return p;
}
int main()
{
    memset(has,false,sizeof(has));
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=n;i>=1;i--) scanf("%d",&l[i]);
    for(int i=n;i>=1;i--) scanf("%d",&c[i]);
    for(int i=1;i<=n+m;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n+m;i++)
        for(int j=1;j<=n+m;j++)
            dp[i][j]=-INF;
    for (int i=1;i<=n;i++)
    {
        int x=l[i]; int v=s[x]-c[i];
        for (int j=i;j>=1;j--) upd(dp[x][j],dp[x][j-1]+v);
        for (int j=x;j<=n+m;j++)
            for (int k=0;k<=i>>(j-x);k++)
                upd(dp[j+1][k/2],dp[j][k]+(k/2)*s[j+1]);
    }
    for (int i=1;i<=n+m+1;i++) upd(ans,dp[i][0]);
    printf("%d\n",ans);
    return 0;
}