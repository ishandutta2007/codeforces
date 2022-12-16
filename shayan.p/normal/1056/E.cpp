// Phoenix

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

const int maxn=1e6+10,mod=1e9+7,P1=911382323,P2=972663749;

int tnf[maxn],tns[maxn];
pii hsh[maxn];
bool a[maxn];
int cnt[2],n;
string s,t;

pii Hash(int l,int r){
    if(l==0) return hsh[r];
    int A=(1ll*hsh[r].F-1ll*hsh[l-1].F*tnf[r-l+1])%mod;
    int B=(1ll*hsh[r].S-1ll*hsh[l-1].S*tns[r-l+1])%mod;
    if(A<0) A+=mod;
    if(B<0) B+=mod;
    return {A,B};
}

bool check(int ln0,int ln1){
    pii h0=hsh[ln0-1],h1;
    pii HSH={0,0};
    int nw=0;
    for(int i=0;i<n;i++){
	if(a[i]){
	    h1=Hash(nw,nw+ln1-1);
	    break;
	}
	nw+=ln0;
    }
    if(h0==h1) return 0;
    for(int i=0;i<n;i++){
	if(a[i]==0){
	    HSH.F=(1ll*HSH.F*tnf[ln0]+h0.F)%mod;
	    HSH.S=(1ll*HSH.S*tns[ln0]+h0.S)%mod;
	}
	else{
	    HSH.F=(1ll*HSH.F*tnf[ln1]+h1.F)%mod;
	    HSH.S=(1ll*HSH.S*tns[ln1]+h1.S)%mod;
	}
    }
    return (HSH==hsh[sz(t)-1]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    tnf[0]=tns[0]=1;
    for(int i=1;i<maxn;i++){
	tnf[i]=1ll*tnf[i-1]*P1 %mod;
	tns[i]=1ll*tns[i-1]*P2 %mod;
    }
    
    cin>>s>>t;
    n=sz(s);
    for(int i=0;i<n;i++)
	a[i]=(s[i]=='1')^(s[0]=='1'),cnt[a[i]]++;

    for(int i=0;i<sz(t);i++){
	hsh[i].F=(1ll*(i==0?0:hsh[i-1].F)*P1+t[i])%mod;
	hsh[i].S=(1ll*(i==0?0:hsh[i-1].S)*P2+t[i])%mod;
    }
    
    int ans=0;
    for(int ln0=1;ln0<sz(t);ln0++){
	if((sz(t)<=1ll*cnt[0]*ln0) || ((sz(t)-(cnt[0]*ln0))%cnt[1]!=0)) continue;
	int ln1=(sz(t)-(cnt[0]*ln0))/cnt[1];
	ans+=check(ln0,ln1);
    }
    cout<<ans<<endl;
    return 0;
}