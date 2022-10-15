#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
int n;
string str;
int fact[MAXN],invf[MAXN];
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
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int cnt0=0,cnt1=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            {
                cnt0++;
                if(cnt) 
                {
                    cnt1+=cnt/2;
                    cnt=0;
                }
            }
            else cnt++;
        }
        cnt1+=cnt/2;
        printf("%d\n",comb(cnt1+cnt0,cnt1));
    }
    return 0;
}