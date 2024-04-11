// Jump, and you will find out how to unfold your wings as you fall.

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
typedef double ld;
typedef pair<ld,ld> pld;

const int maxn=1e5+10,mod=1e9+7;

pld p[maxn];

bool CMP(pld a,pld b){
    if(a.F==0 && b.F==0) return abs(a.S)<=abs(b.S);
    if(a.F==0) return 1;
    if(b.F==0) return 0;
    ld A=a.S/a.F;
    ld B=b.S/b.F;
    if(A==B) return a.F*a.F+a.S*a.S <= b.F*b.F+b.S*b.S;
    return A>B;
}

ld cross(pld a,pld b){
    return a.F*b.S-a.S*b.F;
}

ld cr(pld a,pld b,pld c){
    return cross(a,b)+cross(b,c)+cross(c,a);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].F>>p[i].S;
	p[i].S-=p[i].F*p[i].F;
	if(p[i].F<p[0].F) swap(p[i],p[0]);
    }
    for(int i=0;i<n;i++){
	if(p[0].F==p[i].F && p[0].S>p[i].S)
	    swap(p[0],p[i]);
    }
    for(int i=n-1;i>=0;i--){
	p[i].F-=p[0].F;
	p[i].S-=p[0].S;
    }
    sort(p+1,p+n,CMP);
    vector<pld>vec;
    vec.PB({0,0});
    for(int i=1;i<n;i++){
	while(sz(vec)>1){
	    ld num=cr(vec[sz(vec)-2],vec.back(),p[i]);
	    if(num>=0) vec.pop_back();
	    else break;
	}
	vec.PB(p[i]);
    }
    int ans=0;
    for(int i=1;i<sz(vec);i++){
	ans+=vec[i-1].F<vec[i].F;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.