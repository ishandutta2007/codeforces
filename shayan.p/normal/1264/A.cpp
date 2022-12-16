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

const int maxn=4e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int n; cin>>n;
	int lst=-1, c=0;
	vector<int> v;
	for(int i=0;i<n;i++){
	    int x; cin>>x;
	    if(x == lst){
		c++;
	    }
	    else{
		if(c!=0)
		    v.PB(c);
		lst=x, c=1;
	    }
	}
	v.PB(c);
	int sm=0;
	for(int i=0;i<sz(v);i++){	    
	    sm+= v[i];
	    if(sm  > (n/2)){
		sm-=v[i];
		while(sz(v) > i)
		    v.pop_back();
		break;
	    }
	}
	int pt=1, cnt=0;
	while(pt<sz(v) && cnt<=v[0])
	    cnt+= v[pt++];
	if(cnt <= v[0] || pt==sz(v) || sm-cnt-v[0] <= v[0])
	    cout<<0<<" "<<0<<" "<<0<<"\n";
	else
	    cout<<v[0]<<" "<<cnt<<" "<<sm-cnt-v[0]<<"\n";
    }
		return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")