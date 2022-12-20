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

map<pii,int>mp1,mp3;
map<ll,set<pii> >mp2;

pii Normal(int x,int y){
    if(x==0 && y==0) return {0,0};
    int g=__gcd(x,y);
    return {x/g,y/g};
}
void Add(pii p1,pii p2,int num){
    pii P={p1.F+p2.F,p1.S+p2.S};
    if(P.F<0 || P.S<0) return;
    mp1[Normal(P.F,P.S)]+=num;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q,n=0;cin>>q;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int x,y;cin>>x>>y;
	    for(pii p:mp2[1ll*x*x+1ll*y*y])
		Add(p,{x,y},1);
	    mp2[1ll*x*x+1ll*y*y].insert({x,y});
	    mp3[Normal(x,y)]++;
	    n++;
	}
	if(task==2){
	    int x,y;cin>>x>>y;
	    mp2[1ll*x*x+1ll*y*y].erase({x,y});
	    for(pii p:mp2[1ll*x*x+1ll*y*y])
		Add(p,{x,y},-1);
	    mp3[Normal(x,y)]--;
	    n--;
	}
	if(task==3){
	    int x,y;cin>>x>>y;
	    int ans=n-mp3[Normal(x,y)]-2*mp1[Normal(x,y)]-2*mp1[{0,0}];
	    cout<<ans<<"\n";
	}
    }
}