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
typedef long double ld;

const ld Big=1e12;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ld a,b,c,d;cin>>a>>b>>c>>d;
    ld x=c-a,y=d-b;
    ld vm,t,vx,vy,wx,wy;cin>>vm>>t>>vx>>vy>>wx>>wy;
    ld l=0,r=Big;
    for(int i=0;i<300;i++){
	ld mid=(l+r)/2;
	ld m1=min(mid,t),m2=mid-m1;
	ld X=x-vx*m1-wx*m2,Y=y-vy*m1-wy*m2;
	if(sqrt(X*X+Y*Y)<=mid*vm) r=mid;
	else l=mid;
    }
    return cout<<setprecision(10)<<fixed<<r<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.