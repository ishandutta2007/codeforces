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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int fr[3],ls[3];
vector<pii>vec;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
	int pos;
	char ch;
	cin>>pos>>ch;
	if(ch=='R'){
	    if(fr[0]==0) fr[0]=pos;
	    ls[0]=pos;
	    vec.PB({pos,0});
	}
	if(ch=='G'){
	    if(fr[1]==0) fr[1]=pos;
	    ls[1]=pos;
	    if(!vec.empty() && vec[0].S==-1){
		vec.PB({pos,-1});
		int ansr=0,ansb=0,lsr=vec[0].F,lsb=vec[0].F;
		for(int j=1;j<sz(vec);j++){
		    if(vec[j].S==0 || vec[j].S==-1) ansr=max(ansr,vec[j].F-lsr), lsr=vec[j].F;
		    if(vec[j].S==1 || vec[j].S==-1) ansb=max(ansb,vec[j].F-lsb), lsb=vec[j].F;
		}
		int val=pos-vec[0].F;
		ans+= min( val - ansr - ansb , int(0) );
	    }
	    vec.clear();
	    vec.PB({pos,-1});
	}
	if(ch=='B'){
	    if(fr[2]==0) fr[2]=pos;
	    ls[2]=pos;
	    vec.PB({pos,1});
	}
    }
    if(fr[1]==0) ans+= ls[0]-fr[0];
    else if(fr[0]==0) ans+= ls[1]-fr[1];
    else ans+= max(ls[0],ls[1]) - min(fr[0],fr[1]);

    if(fr[1]==0) ans+= ls[2]-fr[2];
    else if(fr[2]==0) ans+= ls[1]-fr[1];
    else ans+= max(ls[2],ls[1]) - min(fr[2],fr[1]);
    
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.