
// only miss the sun when it starts to snow

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

vector<int> v[2];

void tell(int x){
    if(x==0) cout<<"tokitsukaze\n";
    if(x==1) cout<<"quailty\n";
    if(x==2) cout<<"once again\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,k; cin>>n>>k;

    string s; cin>>s;

    for(int i=0;i<sz(s);i++){
	v[s[i]-'0'].PB(i);
    }
    if(v[0].empty() || v[1].empty()) tell(0);
    
    if(v[0].back()-v[0][0]+1<=k) tell(0);
    if(v[1].back()-v[1][0]+1<=k) tell(0);

    for(int w=0;w<2;w++){
	for(int i=0;i<n-k+1;i++){
	    int posr=v[1-w].back(), posl= v[1-w][0];
	    if( i+k-1 >= v[1-w].back() ) posr=*(--lower_bound( v[1-w].begin(), v[1-w].end(), i) );
	    if( posl>=i ) posl=*lower_bound( v[1-w].begin(), v[1-w].end(), i+k );
	    if( posr - posl + 1 > k ) tell(2);	    
	}
    }
    tell(1);
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")