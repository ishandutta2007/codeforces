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

const int maxn=3500,mod=1e9+7,modi=5e8+4;
ll ls[2][maxn][2],mr[2][maxn][2],tt[2][maxn][2];// kamtar mosavi // bishtar akid
ll p,q,a[maxn],b[maxn];

void print(){
    for(int i=11;i>=0;i--)
	cout<<a[i];
    cout<<endl;
}

inline ll f(ll x){
    if(x<0) return 0;
    return (((x+1)*(x+2))/2)%mod;
    
}
inline ll g(ll x){
    if(x<0)return 0;
    return ((p*(p-1)-(p-x-2)*(p-x-1))/2)%mod;
}


int main(){
    string s;cin>>p>>q>>s;
    if(q>(maxn-5)){
	printf("0\n");
	return 0;
    }
    for(int i=0;i<sz(s);i++)
	a[sz(s)-i-1]=s[i]-'0';
    for(int i=0;i<maxn;i++){
	ll tn=1;
	for(int j=0;j<maxn;j++){
	    b[i]=(a[j]*tn+b[i])%p;
	    tn=1ll*tn*10 %p;
	}
	if(b[i]<0) b[i]+=p;
	a[0]-=b[i];
	for(int j=maxn-1;j>0;j--){
	    ll num=a[j]%p;
	    a[j]/=p;
	    a[j-1]+=num*10;
	}
	a[0]/=p;
	for(int j=0;j<maxn-1;j++){
	    ll num=a[j]/10;
	    a[j]%=10;
	    a[j+1]+=num;
	}
    }
    ls[0][0][0]=f(b[0]);
    ls[0][1][1]=g(b[0]);
    mr[0][0][0]=(f(p-1)-f(b[0]))%mod;
    mr[0][1][1]=(g(p-1)-g(b[0]))%mod;
    tt[0][0][0]=(ls[0][0][0]+mr[0][0][0])%mod;
    tt[0][1][1]=(ls[0][1][1]+mr[0][1][1])%mod;

    for(int i=1;i<maxn;i++){
	int o=i&1,O=1-o;
	ll A0=f(b[i]-1),B0=f(p-1)-f(b[i]),C0=b[i]+1;
	ll A1=f(b[i]-2),B1=f(p-2)-f(b[i]-1),C1=b[i];
	ll A2=g(b[i]-1),B2=g(p-1)-g(b[i]),C2=p-b[i]-1;
	ll A3=g(b[i]-2)+(b[i]?p:0),B3=g(p-1)-g(b[i]-1),C3=p-b[i];
	ls[o][0][0]=( A0*tt[O][0][0] + C0*ls[O][0][0])%mod;
	mr[o][0][0]=( B0*tt[O][0][0] + C0*mr[O][0][0])%mod;
	tt[o][0][0]=(ls[o][0][0]+mr[o][0][0])%mod;
	for(int j=1;j<maxn;j++){
	    ls[o][j][0]=(A0*tt[O][j][0] + C0*ls[O][j][0] + A1*tt[O][j][1] + C1*ls[O][j][1])%mod;
	    mr[o][j][0]=(B0*tt[O][j][0] + C0*mr[O][j][0] + B1*tt[O][j][1] + C1*mr[O][j][1])%mod;
	    tt[o][j][0]=(ls[o][j][0]+mr[o][j][0])%mod;
	    ls[o][j][1]=(A2*tt[O][j-1][0] + C2*ls[O][j-1][0] + A3*tt[O][j-1][1] + C3*ls[O][j-1][1])%mod;
	    mr[o][j][1]=(B2*tt[O][j-1][0] + C2*mr[O][j-1][0] + B3*tt[O][j-1][1] + C3*mr[O][j-1][1])%mod;
	    tt[o][j][1]=(ls[o][j][1]+mr[o][j][1])%mod;
	}
    }
    ll ans=0;
    for(int i=q;i<maxn;i++)
	ans=(ans+ls[0][i][0])%mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
    return 0;
}