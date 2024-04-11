#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 31607
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN][MAXN];
int val[MAXN];
int save[MAXN][(1<<21)];
int m[MAXN];
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
    int inv=pow_mod(10000,MOD-2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]=a[i][j]*inv%MOD;
        }
    for(int i=1;i<=n;i++)
    {
        val[i]=1;
        for(int j=1;j<=n;j++) val[i]=val[i]*a[i][j]%MOD;
    }
    for(int i=1;i<=n;i++)
        for(int mask=0;mask<(1<<n);mask++)
        {
            save[i][mask]=1;
            if(mask!=0) save[i][mask]=save[i][mask^(mask&(-mask))]*a[__builtin_ffs(mask)][i]%MOD;
        }
    for(int i=1;i<=n;i++)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            save[i][mask]=(MOD+1-save[i][mask]);
            if(save[i][mask]>=MOD) save[i][mask]-=MOD;
        }
    }
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++)
        for(int diag=0;diag<2;diag++)
            for(int adiag=0;adiag<2;adiag++)
            {
                int res=1;
                for(int i=0;i<n;i++) if(mask&(1<<i)) res=res*val[i+1]%MOD;
                for(int i=1;i<=n;i++) m[i]=mask;
                if(diag)
                {
                    for(int i=1;i<=n;i++) 
                    {
                        if(!(m[i]&(1<<(i-1))))
                        {
                            m[i]|=(1<<(i-1));
                            res=res*a[i][i]%MOD;
                        }
                    }
                }
                if(adiag)
                {
                    for(int i=1;i<=n;i++) 
                    {
                        if(!(m[i]&(1<<(n-i))))
                        {
                            m[i]|=(1<<(n-i));
                            res=res*a[n-i+1][i]%MOD;
                        }
                    }
                }
                for(int i=1;i<=n;i++) res=res*save[i][((1<<n)-1)^m[i]]%MOD;
                int cnt=__builtin_popcount(mask)&1;
                if(diag) cnt^=1;
                if(adiag) cnt^=1;
                if(cnt) dec(ans,res); else add(ans,res);
            }
    ans=(MOD+1-ans);
    if(ans>=MOD) ans-=MOD;
    printf("%d\n",ans);
    return 0;
}