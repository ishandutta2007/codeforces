// Faster!

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
const ll Big=3e18+10,inf=9e18;

ll x[maxn],y[maxn],z[maxn],lim[8],ansx,ansy,ansz,X,Y,Z;
pll p[4],w[4];

bool _solve(){
    for(int i=0;i<4;i++){
	if(w[i].F>w[i].S) return 0;
    }
    ll sm=w[0].F+w[1].F+w[2].F;
    X=w[0].F,Y=w[1].F,Z=w[2].F;
    if(sm>w[3].S) return 0;
    if(w[3].F<=sm) return 1;
    if(sm<w[3].F){
	ll num=min(w[3].F-sm,w[0].S-w[0].F);
	X+=num,sm+=num;
    }
    if(sm<w[3].F){
	ll num=min(w[3].F-sm,w[1].S-w[1].F);
	Y+=num,sm+=num;
    }
    if(sm<w[3].F){
	ll num=min(w[3].F-sm,w[2].S-w[2].F);
	Z+=num,sm+=num;
    }
    if(sm==w[3].F) return 1;
    return 0;
}
bool solve(){
    p[0]={-lim[1],lim[6]};
    p[1]={-lim[2],lim[5]};
    p[2]={-lim[4],lim[3]};
    p[3]={-lim[0],lim[7]};
    for(int r=0;r<2;r++){
	for(int i=0;i<4;i++){
	    w[i]=p[i];
	    if((p[i].F&1)!=r) w[i].F++;
	    if((p[i].S&1)!=r) w[i].S--;
	    w[i].F-=r,w[i].S-=r;
	    if(r && i==3) w[i].F-=2,w[i].S-=2;
	    w[i].F/=2,w[i].S/=2;
	}
	if(_solve()){
	    X=X*2+r;
	    Y=Y*2+r;
	    Z=Z*2+r;
	    return 1;
	}
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	int n;cin>>n;
	for(int i=0;i<n;i++){
	    cin>>x[i]>>y[i]>>z[i];
	}
	ansx=ansy=ansz=0;
	ll l=-1,r=Big;
	while(r-l>1){
	    ll mid=(l+r)>>1;
	    fill(lim,lim+8,inf);
	    for(int i=0;i<n;i++){
		for(int msk=0;msk<8;msk++){
		    ll num=mid;
		    if(bit(msk,0)) num+=x[i];
		    else num-=x[i];
		    if(bit(msk,1)) num+=y[i];
		    else num-=y[i];
		    if(bit(msk,2)) num+=z[i];
		    else num-=z[i];
		    lim[msk]=min(lim[msk],num);
		}
	    }
	    if(solve()){
		r=mid;
		ansx=X,ansy=Y,ansz=Z;
	    }
	    else{
		l=mid;
	    }
	}
	cout<<(ansy+ansz)/2<<" "<<(ansx+ansz)/2<<" "<<(ansx+ansy)/2<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.