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

const int maxn=210,mod=998244353,SQ=4e4;

int k,cof[maxn],tmp[maxn],A[maxn],Ans[maxn];

void Mul(int *ans,int *a,int *b){
    memset(tmp,0,sizeof tmp);
    for(int i=0;i<=k;i++)
	for(int j=0;j<=k;j++)
	    tmp[i+j]=(1ll*tmp[i+j]+1ll*a[i]*b[j])%(mod-1);
    for(int i=2*k;i>k;i--)
	for(int j=1;j<=k+1;j++)
	    tmp[i-j]=(1ll*tmp[i-j]+1ll*tmp[i]*cof[j])%(mod-1);
    for(int i=0;i<maxn;i++)
	ans[i]=tmp[i];
}

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

int Log(int x){
    map<int,int>mp;
    for(int i=0;i<SQ;i++)
	mp[1ll*Pow(3,mod-1-i)*x %mod]=i;
    for(int tot=0;tot<mod;tot+=SQ)
	if(mp.count(Pow(3,tot)))
	    return tot+mp[Pow(3,tot)];
    assert(0);
}

pii Inv(int a,int b){
    if(b==0) return {1,1};
    pii p=Inv(b,a%b);
    int cfa=p.S%b;
    return {cfa,(1ll-1ll*cfa*a)/b};
}
int inv(int a,int md){
    return Inv(a,md).F;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>k;
    for(int i=1;i<=k;i++)
	cin>>cof[i];
    int n,fn;cin>>n>>fn;
    int alpha=Log(fn);
    Ans[0]=A[1]=1;
    while(n>0){
	if(n&1) Mul(Ans,Ans,A);
	Mul(A,A,A);
	n>>=1;
    }
    int pw=Ans[k];
    int d=gcd(pw,mod-1);
    if(alpha%d!=0) return cout<<-1<<endl,0;
    int ans=1ll*(alpha/d)*inv(pw/d,(mod-1)/d) %((mod-1)/d);
    if(ans<0)ans+=mod-1;
    return cout<<Pow(3,ans)<<endl,0;
}