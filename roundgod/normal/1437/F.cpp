#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
using namespace std;
int n,a[MAXN];
int dp[MAXN];
int v[MAXN],tot,cnt[MAXN],sum[MAXN];
int halfpos[MAXN];
map<int,int> mp;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int comb[MAXN][MAXN],fact[MAXN];
int id[MAXN];
int main()
{
    fact[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    for(auto p:mp) v[++tot]=p.first;
    for(int i=1;i<=tot-1;i++)
    {
        if(v[i]*2>v[tot])
        {
            puts("0");
            return 0;
        }
    }
    comb[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++) 
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    for(int i=1;i<=tot;i++)
    {
        cnt[i]=mp[v[i]];
        sum[i]=cnt[i]+sum[i-1];
    }
    if(cnt[tot]>1)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=tot;i++)
    {
        int x=v[i]/2;
        halfpos[i]=upper_bound(v+1,v+tot+1,x)-v-1;
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<tot;i++)
    {
        for(int j=i+1;j<=tot;j++)
        {
            if(i==0)
            {
                add(dp[j],1LL*cnt[j]*comb[n-1][sum[halfpos[j]]]%MOD*fact[sum[halfpos[j]]]%MOD);
            }
            else
            {
                if(v[j]<2*v[i]) continue;
                int num;
                int prenum=sum[halfpos[i]]+1; 
                num=sum[halfpos[j]]-prenum;
                add(dp[j],1LL*dp[i]*cnt[j]%MOD*comb[n-prenum-1][num]%MOD*fact[num]%MOD);
            }
        }
    }
    printf("%d\n",dp[tot]);
    return 0;
}