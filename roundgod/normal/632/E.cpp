#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define MAXN 2000005
#define MOD1 998244353
#define MOD2 1004535809
#define INF 1000000000
#define F first
#define S second
using namespace std;  
typedef long long ll;
typedef pair<int,int> P;    
const int g=3; 
ll pow_mod(ll a,ll i,ll MOD)
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
int rev(int x,int r)  
{  
    int ans=0;  
    for(int i=0;i<r;i++)  
        if(x&(1<<i)) ans+=1<<(r-i-1);   
    return ans;  
}  
void ntt(int n,ll A[],int on,ll MOD)
{
    int r=0;  
    for(;;r++) if((1<<r)==n)  break;   
    for(int i=0;i<n;i++)  
    {  
        int tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(int s=1;s<=r;s++)  
    {  
        int m=1<<s;  
        ll wn=pow_mod(g,(MOD-1)/m,MOD);  
        for(int k=0;k<n;k+=m)  
        {  
            ll w=1;  
            for(int j=0;j<m/2;j++)  
            {  
                ll t,u;  
                t=w*(A[k+j+m/2]%MOD)%MOD;  
                u=A[k+j]%MOD;  
                A[k+j]=(u+t)%MOD;  
                A[k+j+m/2]=((u-t)%MOD+MOD)%MOD;  
                w=w*wn%MOD;  
            }  
        }  
    }  
    if(on==-1)  
    {  
        for(int i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);  
        ll inv=pow_mod(n,MOD-2,MOD);  
        for(int i=0;i<n;i++)  
            A[i]=A[i]%MOD*inv%MOD;  
    }  
}
ll n,k,A[MAXN],B[MAXN],ans[MAXN];  
int main()
{
    scanf("%I64d%I64d",&n,&k);
    ll len=1;
    memset(A,0,sizeof(A));
    ll maxx=0;
    for(ll i=0;i<n;i++)
    {
    	ll x;
    	scanf("%I64d",&x);
        maxx=max(maxx,x);
    	A[x]=1;
    }
    while(len<maxx*k) len*=2;
    copy(A,A+len,B);
    ntt(len,A,1,MOD1);
    ntt(len,B,1,MOD2);
    for(int i=0;i<len;i++)
    {
        A[i]=pow_mod(A[i],k,MOD1);
        B[i]=pow_mod(B[i],k,MOD2);
    }
    ntt(len,A,-1,MOD1);
    ntt(len,B,-1,MOD2);
    for(int i=0;i<len;i++)
        if(A[i]||B[i]) printf("%d ",i);
    return 0;  
}