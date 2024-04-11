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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int ton(string a){
    stringstream ss;
    ss<<a;
    int x; ss>>x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string x,y,z; cin>>x>>y>>z;
    int a=ton(x), ans=0;
    if(z=="week"){
	a--;
	a=(a-4+7)%7;
	ans=(366/7) + ((366%7)>(a));
    }
    else{
	if(a==31){
	    ans=7;
	}
	else if(a==30){
	    ans=11;
	}
	else{
	    ans=12;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")