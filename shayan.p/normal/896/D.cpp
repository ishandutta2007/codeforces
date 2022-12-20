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

const int maxn=1e5+10;

int n,p,l,r,MOD;
int fac[10][maxn],ifac[10][maxn],cnt[10][maxn],arr[maxn],mm[10];
vector<int>v;
vector<int>vp;

int tavan(int a,int b,int md){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%md;
	a=(1ll*a*a)%md;
	b/=2;
    }
    return ans;
}
int C(int n,int k){
    if(n<k)return 0;
    int ans=0;
    for(int i=0;i<sz(v);i++){
	int p=v[i],pi=(p/vp[i])*(vp[i]-1);
	mm[i]=(1ll*((1ll*fac[i][n]*ifac[i][k])%p)*ifac[i][n-k])%p;
	mm[i]=(1ll*mm[i]*tavan(vp[i],cnt[i][n]-cnt[i][k]-cnt[i][n-k],p))%p;
	int X=(1ll*(MOD/p)*tavan(MOD/p,pi-1,p))%MOD;
	ans=(1ll*ans+1ll*X*mm[i])%MOD;
    }
    return ans;
}

void add(int &p,int i){
    int z=1;
    while(p%i==0)
	p/=i,z*=i;
    
    fac[sz(v)][0]=ifac[sz(v)][0]=1;
    for(int j=1;j<=n;j++){
	int x=j,cc=0;
	while(x%i==0)
	    x/=i,cc++;
	cnt[sz(v)][j]=cnt[sz(v)][j-1]+cc;
	fac[sz(v)][j]=(1ll*fac[sz(v)][j-1]*x)%z;
	arr[j]=x;
    }
    ifac[sz(v)][n]=tavan(fac[sz(v)][n],(z/i)*(i-1)-1,z);
    for(int j=n-1;j>=1;j--)
	ifac[sz(v)][j]=(1ll*ifac[sz(v)][j+1]*arr[j+1])%z;
    v.PB(z);
    vp.PB(i);
}

int main(){// p==1????
    scanf("%d%d%d%d",&n,&p,&l,&r);
    MOD=p;
    for(int i=2;(i*i)<=p;i++){
	if(p%i==0)
	    add(p,i);
    }
    if(p>1)
	add(p,p);
    int ans=0;
    for(int i=0;i<=n;i++){
	int L=l,R=r;
	if((L+i)&1)L++;
	if((R+i)&1)R--;
	if(L>R)continue;
	int A=(i+L)/2,B=(i+R)/2;
	int num=(1ll*C(i,A)-1ll*C(i,B+1))%MOD;
	ans=(1ll*ans+1ll*C(n,i)*num)%MOD;
    }
    if(ans<0)
	ans+=MOD;
    printf("%d\n",ans);
}