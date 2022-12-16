// Remember...

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

const int maxn=1e5+10,mod=1e9+7;
const ld inf=1e38, inf2=7e18;

map<ll,ll> mpx, mpy;
ll limx, limy, n;

void add(ll x,ll y){
    if(mpx.count(x)) mpx[x]= min(mpx[x], y);
    else mpx[x]=y;
    if(mpy.count(y)) mpy[y]= min(mpy[y], x);
    else mpy[y]=x;
}
ll bin(ld a,ll x){
    ll l=0, r=inf2;
    while(r-l>1){
	ll mid=(l+r)>>1;
	if(a<=ld(x) * ld(mid))
	    r=mid;
	else
	    l=mid;
    }
    return r;
}
pair<ld,ll> fndx(ld s){
    ld sm=0;
    ll mn=n+1, bef=1;
    for(auto it=mpx.begin(); it!=mpx.end(); it++){
	ll nw=it->F;
	ll h= mn - limy -1;
	h=max(ll(0),h);
	ll L= max( limx+1, bef ), R=nw;
	if(L<R){
	    ld num= ld(R-L) * ld(h);
	    if(num>=s){
		ll need= bin(s, h);
		return { sm + ld(h) * ld(need), L+need-1 };
	    }
	    s-=num;
	    sm+=num;
	}	
	bef=nw;
	mn=min(mn, it->S);
    }
    return {sm, n};
}
pair<ld,ll> fndy(ld s){
    ld sm=0;
    ll mn=n+1, bef=1;
    for(auto it=mpy.begin(); it!=mpy.end(); it++){
	ll nw=it->F;
	ll h= mn - limx -1;
	h=max(ll(0),h);
	ll L= max( limy+1, bef ), R=nw;
	if(L<R){
	    ld num= ld(R-L) * ld(h);
	    if(num>=s){
		ll need= bin(s, h);
		return { sm + ld(h) * ld(need), L+need-1 };
	    }
	    s-=num;
	    sm+=num;
	}	
	bef=nw;
	mn=min(mn, it->S);
    }
    return {sm, n};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
		     
    cin>>n;

    mpx[n+1]=0;
    mpy[n+1]=0;
    
    while(true){
	ld sm= fndx(inf).F /3;
	ll x=fndx(sm).S;
	ll y=fndy(sm).S;
	cout<<x<<" "<<y<<endl;
	int ans; cin>>ans;
	if(ans==0) break;
	if(ans==1) limx=x;
	if(ans==2) limy=y;
	if(ans==3) add(x,y);
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")