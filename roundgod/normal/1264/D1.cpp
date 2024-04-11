#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
int n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
char str[MAXN];
int lb[MAXN],rb[MAXN],ques[MAXN];
int sum1[MAXN],sum2[MAXN],ans;
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        lb[i]=lb[i-1]+(str[i]=='(');
        rb[i]=rb[i-1]+(str[i]==')');
        ques[i]=ques[i-1]+(str[i]=='?');
    }
    int s=ques[n];
    for(int i=0;i<=n;i++)
    {
        sum1[i]=comb(s,i);
        if(i>0) add(sum1[i],sum1[i-1]);
    }
    if(s)
    {
        for(int i=0;i<=n;i++)
        {
            sum2[i]=comb(s-1,i);
            if(i>0) add(sum2[i],sum2[i-1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(str[i]==')') continue;
        int a=lb[i],b=rb[n]-rb[i],c=ques[i],d=ques[n]-ques[i];
        if(str[i]=='?') {a++; c--;}
        if(a<=b+d)
        {
            if(str[i]=='(') add(ans,sum1[b+d-a]); else add(ans,sum2[b+d-a]);
        }
    }
    printf("%d\n",ans);
    return 0;
}