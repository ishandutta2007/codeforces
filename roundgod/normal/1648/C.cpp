#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s[MAXN],t[MAXN],fact[MAXN],invf[MAXN],inv[MAXN];
int cnt[MAXN];
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=200000)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
	fact[0]=invf[0]=1;
	for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	invf[200000]=pow_mod(fact[200000],MOD-2);
	for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
	for(int i=1;i<=200000;i++) inv[i]=1LL*invf[i]*fact[i-1]%MOD;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++; add(x,1);
	}
	for(int i=1;i<=m;i++) scanf("%d",&t[i]);
	int ss=fact[n];
	for(int i=1;i<=200000;i++) ss=1LL*ss*invf[cnt[i]]%MOD;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i>m) break;
		madd(ans,1LL*ss*inv[n+1-i]%MOD*sum(t[i]-1)%MOD);
		if(!cnt[t[i]]) break;
		ss=1LL*ss*inv[n+1-i]%MOD*cnt[t[i]]%MOD;
		cnt[t[i]]--;
		add(t[i],-1);
		if(i==n&&i<m) madd(ans,1);
	}
	printf("%d\n",ans);
	return 0;
}