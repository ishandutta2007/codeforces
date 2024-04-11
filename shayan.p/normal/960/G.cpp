// Wanna Hack? GL...

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

const int Lg=18,maxn=1e5+10,mod=(119<<23)+1;

int fac[maxn],ifac[maxn];
int a[1<<Lg],b[1<<Lg],w[1<<Lg];

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

void prep(){
    w[0]=1,w[1]=Pow(3,119<<(23-Lg));
    for(int i=2;i<(1<<Lg);i++)
	w[i]=1ll*w[i-1]*w[1] %mod;
}

void trans(int *a,bool inv){
    for(int i=1;i<(1<<Lg);i++){
	int x=0;
	for(int j=0;j<Lg;j++)
	    x+=bit(i,j)<<(Lg-1-j);
	if(i<x) swap(a[i],a[x]);
    }
    for(int i=0;i<Lg;i++){
	for(int j=0;j<(1<<Lg);j++){
	    if(bit(j,i)){
		int &B=a[j],&A=a[j ^ (1<<i)],W=w[((inv?-1:1)*((j & ((1<<i)-1))<<(Lg-1-i)))&((1<<Lg)-1)],C=1ll*B*W %mod;B=(A-C)%mod,A=(A+C)%mod;
	    }
	}
    }
    int Inv=Pow(2,mod-1-Lg);
    if(inv){
	for(int i=0;i<(1<<Lg);i++)
	    a[i]=1ll*a[i]*Inv %mod;
    }
}
void Mul(int *a,int *b){
    for(int i=0;i<(1<<Lg);i++)
	a[i]=1ll*a[i]*b[i] %mod;
}
void Clean(int *a){
    for(int i=(1<<(Lg-1));i<(1<<Lg);i++)
	a[i]=0;
}
void Print(int *a){
    for(int i=0;i<(1<<Lg);i++)
	if(a[i]!=0)
	    cout<<i<<"   "<<(a[i]+mod)%mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    prep();
    int n,A,B;cin>>n>>A>>B;
    if(min(A,B)==0) return cout<<0<<endl,0;
    A--,B--,n--;
    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    ifac[maxn-1]=Pow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]=1ll*(i+1)*ifac[i+1] %mod;
    a[0]=1;
    for(int i=1;i<(1<<(Lg-1));i++)
	b[i]=Pow(i,mod-2);
    int N=A+B;
    while(N){
	trans(b,0);
	if(N&1) trans(a,0),Mul(a,b),trans(a,1),Clean(a);
	Mul(b,b),trans(b,1),Clean(b);
	N>>=1;
    }
    int ans=1ll*a[n] *fac[n] %mod *ifac[A] %mod *ifac[B] %mod;
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}