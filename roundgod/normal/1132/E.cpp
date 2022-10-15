#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXW 5500000
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll W;
ll n,a[MAXN],s;
bool dp[MAXW];
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
bool deq[MAXW];
int main()
{
    scanf("%lld",&W);
    ll m=1;
    for(ll i=1;i<=8;i++) m=lcm(m,i);
    s=0;
    for(ll i=1;i<=8;i++) 
    {
        scanf("%lld",&a[i]);
        s+=i*a[i];
    }
    if(W>=s)
    {
        printf("%lld\n",s);
        return 0;
    }
    fill(dp,dp+8*m+1,false);
    dp[0]=true;
    for(ll i=1;i<=8;i++)
    {
        for(ll j=0;j<i;j++)
        {
            ll s=0,t=0,cnt=0;
            for(ll k=0;k*i+j<8*m;k++)
            {
                bool val=dp[k*i+j];
                deq[t++]=val;
                if(val) cnt++;
                if(cnt) dp[k*i+j]=true; else dp[k*i+j]=false;
                if(t-s>a[i]) 
                {
                    if(deq[s]) cnt--;
                    s++;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<=min(8*m,W);i++)
    {
        if(dp[i])
        {
            ll maxi=(W-i)/m;
            maxi=min(maxi,(s-8*m-i)/m);
            maxi=max(maxi,0LL);
            ll res=i+maxi*m;
            while(res+m<=W&&res<s-8*m) res+=m;
            ans=max(ans,res);
        }
    }
    for(ll i=0;i<8*m;i++) if(dp[i]&&s-i<=W) ans=max(ans,s-i);
    printf("%lld\n",ans);
    return 0;
}