#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
string str;
int x,y;
int fact[MAXN],invf[MAXN];
int cnt[52],save[52][52];
int dp[MAXN],now[MAXN];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int find_id(char c)
{
    if(c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    cin>>str;
    n=str.size();
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) cnt[find_id(str[i])]++;
    int res=1LL*fact[n/2]*fact[n/2]%MOD;
    for(int i=0;i<52;i++) res=1LL*res*invf[cnt[i]]%MOD;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<52;i++)
    {
        if(!cnt[i]) continue;
        for(int j=n;j>=cnt[i];j--)
            add(dp[j],dp[j-cnt[i]]);
    }
    for(int id1=0;id1<52;id1++)
        for(int id2=id1+1;id2<52;id2++)
        {
            if(cnt[id1]+cnt[id2]>n/2) {save[id1][id2]=0; continue;}
            now[0]=1;
            for(int j=0;j<=n;j++)
            {
                now[j]=dp[j];
                if(j>=cnt[id1]) dec(now[j],now[j-cnt[id1]]);
            }
            for(int j=0;j<=n;j++)
            {
                if(j>=cnt[id2]) dec(now[j],now[j-cnt[id2]]);
            }
            save[id1][id2]=2LL*res*now[n/2-cnt[id1]-cnt[id2]]%MOD;
        }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y); x--;y--;
        if(str[x]==str[y])
        {
            int id=find_id(str[x]);
            if(cnt[id]>n/2) 
            {
                puts("0");
                continue;
            }
            int ans=1LL*dp[n/2]*res%MOD;
            printf("%d\n",ans);
        }
        else
        {
            int id1=find_id(str[x]),id2=find_id(str[y]);
            if(id1>id2) swap(id1,id2);
            if(id1==id2)
            {
                int ans=1LL*dp[n/2]*res%MOD;
                printf("%d\n",ans);
                continue;
            }
            printf("%d\n",save[id1][id2]);
        }
    }
    return 0;
}