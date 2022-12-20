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

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

int ans[2*maxn],a[2*maxn],arr[2*maxn];

void Mul(int *a,int *b,int m){
    memset(arr,0,sizeof arr);
    for(int i=0;i<m;i++){
	for(int j=0;j<m;j++){
	    arr[i+j]=(1ll*arr[i+j]+1ll*a[i]*b[j])%mod;
	}
    }
    for(int i=2*m-2;i>=m;i--){
	arr[i-1]=(1ll*arr[i-1]+1ll*arr[i])%mod;
	arr[i-m]=(1ll*arr[i-m]+1ll*arr[i])%mod;
    }
    for(int i=0;i<m;i++){
	a[i]=arr[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;cin>>n;
    int m;cin>>m;
    ans[0]=a[1]=1;
    while(n){
	if(n&1) Mul(ans,a,m);
	Mul(a,a,m);
	n>>=1;
    }
    int ANS=0;
    for(int x:ans){
	ANS=(ANS+x)%mod;
    }
    if(ANS<0) ANS+=mod;
    return cout<<ANS<<endl,0;
}