#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll A;
int prime[MAXN];
bool is_prime[MAXN];
int dp[2][10005];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<ll> primes;
vector<ll> divisors;
vector<P> v;
vector<ll> trans[MAXN];
ll factor(ll d)
{
    for(int i=2;1LL*i*i<=d;i++)
    {
        if(d%i==0)
        {
            while(d%i==0) d/=i;
            if(d==1) return i;
            return 0;
        }
    }
    return d;
}
int main()
{
    sieve(1000000);
    scanf("%lld",&A);
    for(int i=1;1LL*i*i<=A;i++)
    {
        if(A%i) continue;
        if(i>2)
        {
            ll tmp=factor(i-1);
            if(tmp) v.push_back(make_pair(tmp,i));
        }
        if(1LL*i*i!=A&&A/i>2)
        {
            ll tmp=factor(A/i-1);
            if(tmp) v.push_back(make_pair(tmp,A/i));
        }
        divisors.push_back(i);
        if(1ll*i*i!=A) divisors.push_back(A/i);
    }
    sort(divisors.begin(),divisors.end());
    sort(v.begin(),v.end());
    int tot=-1;
    for(int i=0;i<(int)v.size();i++)
    {
        if(i==0||v[i].F!=v[i-1].F) ++tot;
        trans[tot].push_back(v[i].S);
    }
    dp[0][0]=1;
    for(int i=0;i<=tot;i++)
    {
        int now=i&1,nxt=now^1;
        for(int k=0;k<(int)divisors.size();k++) dp[nxt][k]=dp[now][k];
        for(int j=0;j<(int)trans[i].size();j++)
        {
            ll x=trans[i][j];
            int cur=0;
            for(int k=0;k<(int)divisors.size();k++)
            {
                while(cur<(int)divisors.size()&&divisors[cur]<divisors[k]*x) cur++;
                if(cur==(int)divisors.size()) break;
                if(divisors[k]*x!=divisors[cur]) continue;
                dp[nxt][cur]+=dp[now][k];
            }
        }
    }
    printf("%d\n",dp[(tot+1)&1][(int)divisors.size()-1]);
    return 0;
}