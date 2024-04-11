// High above the clouds there is a rainbow...

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

map<char,int>mp[2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
	string s;cin>>s;
	mp[0].clear(),mp[1].clear();
	for(int i=0;i<sz(s);i++){
	    mp[s[i]&1][s[i]]++;
	}
	if(mp[1].empty()) swap(mp[0],mp[1]);
	if(mp[0].empty()){
	    for(auto it:mp[1]){
		while(it.S--) cout<<it.F;
	    }
	    cout<<"\n";
	    goto End;
	}
	else{
	    for(auto it1:mp[0]){
		for(auto it2:mp[1]){
		    if(abs(it1.F-it2.F)!=1){
			for(auto it3:mp[0]){
			    if(it3.F==it1.F) continue;
			    while(it3.S--) cout<<it3.F;
			}
			while(it1.S--) cout<<it1.F;
			while(it2.S--) cout<<it2.F;
			for(auto it3:mp[1]){
			    if(it3.F==it2.F) continue;
			    while(it3.S--) cout<<it3.F;
			}
			cout<<"\n";
			goto End;
		    }
		}
	    }
	}
	cout<<"No answer\n";
    End:;
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.