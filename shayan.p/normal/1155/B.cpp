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
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s,fnl="";cin>>s;
    int num=(n-11)/2,t1=0,t2=0;
    for(int i=0;i<n;i++){
	if(s[i]=='8'){
	    if(t1<num) t1++;
	    else fnl+=s[i];
	}
	else{
	    if(t2<num) t2++;
	    else fnl+=s[i];
	}
    }
    if(fnl[0]=='8') return cout<<"YES\n",0;
    return cout<<"NO\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.