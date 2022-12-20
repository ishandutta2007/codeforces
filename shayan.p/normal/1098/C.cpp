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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n;
vector<int>a;

ll F(ll x){
    a.clear();
    ll ans=0,nw=1,N=n,h=1;
    while(N>=nw){
	a.PB(nw);
	ans+=h*nw;
	h++;
	N-=nw;
	nw*=x;
    }
    if(N>0) a.PB(N);
    ans+=h*N;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll s;cin>>n>>s;
    if(2ll*s>1ll*n*(n+1) || s<2*n-1) return cout<<"No\n",0;
    int l=1,r=n-1,ans=n-1;
    while(l<=r){
	int mid=(l+r)>>1;
	if(F(mid)<=s) ans=mid,r=mid-1;
	else          l=mid+1;
    }
    s-=F(ans);	
    for(int i=sz(a)-1;i>=0;i--){
	while(a[i]>1){
	    if(sz(a)-i>s) break;
	    s-=sz(a)-i;
	    --a[i];
	    a.PB(1);
	}
	if(a[i]>1 && sz(a)-i>s){
	    --a[i];
	    ++a[i+s];
	    break;
	}
    }
    cout<<"Yes\n";
    int L=1;
    for(int i=1;i<sz(a);i++){
	for(int j=0;j<a[i];j++)
	    cout<<L+(j/ans)<<" ";
	L=L+a[i-1];
    }
    return cout<<endl,0;
}