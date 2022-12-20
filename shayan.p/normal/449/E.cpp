// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e6+10,mod=1e9+7;

int f[maxn],phi[maxn],sm0[maxn],sm1[maxn],sm2[maxn],par[maxn],arr[30],C;

int tavan(int a,int b){
    int ans=1;
    while(b>0){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b/=2;
    }
    return ans;
}

int main(){
    for(int i=2;i<maxn;i++)
	if(par[i]==0)
	    for(int j=i;j<maxn;j+=i)
		par[j]=i;
    for(int i=1;i<maxn;i++){
	int n=i,x=1;
	phi[i]=i;
	while(n>1){
	    int p=par[n],cnt=0;
	    while(n%p==0)
		n/=p,cnt++;
	    phi[i]=1ll*phi[i]*(p-1) %mod;
	    x=1ll*x*p %mod;
	}
	phi[i]=1ll*phi[i]*tavan(x,mod-2) %mod;
    }
    for(int i=1;i<maxn;i++)
	for(int j=2*i;j<maxn;j+=i)
	    f[j]=(f[j]+1ll*i*phi[j/i])%mod;
    for(int i=1;i<maxn;i++)
	f[i]=(2ll*i*i*i-6ll*i*i+7ll*i+6ll*f[i])/3 %mod;
    for(int i=1;i<maxn;i++){
	sm0[i]=(sm0[i-1]+f[i])%mod;
	sm1[i]=(sm1[i-1]+1ll*i*f[i])%mod;
	sm2[i]=(sm2[i-1]+1ll*i*i %mod *f[i])%mod;
    }
    int q;scanf("%d",&q);
    while(q--){
	int a,b;scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	int ans=(1ll*(a+1)*(b+1) %mod *sm0[a] -1ll*(a+b+2)*sm1[a] +1ll*sm2[a])%mod;
	if(ans<0)ans+=mod;
	printf("%d\n",ans);
    }
    return 0;
}