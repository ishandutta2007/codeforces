#include<bits/stdc++.h>
#define MAXN 100005
#define MAXH 32
#define MOD 7340033
#define INF 1000000000
#define F first
#define S second
using namespace std;  
typedef long long ll;
typedef pair<int,int> P;    
const ll g=3; 
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
ll rev(ll x,ll r)  
{  
    ll ans=0;  
    for(ll i=0;i<r;i++)  
        if(x&(1<<i)) ans+=1<<(r-i-1);   
    return ans;  
}  
void ntt(ll n,ll A[],ll on)
{
    ll r=0;  
    for(;;r++) if((1<<r)==n)  break;   
    for(ll i=0;i<n;i++)  
    {  
        ll tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(ll s=1;s<=r;s++)  
    {  
        ll m=1<<s;  
        ll wn=pow_mod(g,(MOD-1)/m);  
        for(ll k=0;k<n;k+=m)  
        {  
            ll w=1;  
            for(ll j=0;j<m/2;j++)  
            {  
                ll t,u;  
                t=w*A[k+j+m/2]%MOD;  
                u=A[k+j];  
                A[k+j]=(u+t);
                if(A[k+j]>=MOD) A[k+j]-=MOD;  
                A[k+j+m/2]=u+MOD-t;
                if(A[k+j+m/2]>=MOD) A[k+j+m/2]-=MOD;
                w=w*wn%MOD;  
            }  
        }  
    }  
    if(on==-1)  
    {  
        for(ll i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);  
        ll inv=pow_mod(n,MOD-2);  
        for(ll i=0;i<n;i++)  
            A[i]=A[i]*inv%MOD;  
    }  
}
ll q,n,k;
ll ans[MAXH][4100],A[4100];  
int main()
{
	memset(ans,0,sizeof(ans));
	ans[0][0]=1;
	for(ll i=1;i<=30;i++)
	{
		for(ll j=0;j<1024;j++)
			ans[i][j]=ans[i-1][j];
		ntt(4096,ans[i],1);
		for(ll j=0;j<4096;j++)
		{
			ll t=ans[i][j]*ans[i][j]%MOD;
			ans[i][j]=t*t%MOD;
		}
		ntt(4096,ans[i],-1);
		for(ll j=4095;j>1000;j--)
			ans[i][j]=0;
		for(ll j=1000;j>=1;j--)
			ans[i][j]=ans[i][j-1];
		ans[i][0]=1;
	}
    scanf("%I64d",&q);
    while(q--)
    {
    	scanf("%I64d%I64d",&n,&k);
    	ll height=0;
    	while(n>1&&n&1) {n=n/2; height++;}
    	printf("%I64d\n",ans[height][k]);
    }
    return 0;  
}