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

int cnt[maxn];
map<int,int>mp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;cin>>n;
    for(int i=1;i<=n;i++){
	int x;cin>>x;
	if(cnt[x]>0 && --mp[cnt[x]]==0) mp.erase(cnt[x]);
	mp[++cnt[x]]++;
	if(sz(mp)>2) continue;
	if(sz(mp)==1){
	    if(mp.begin()->F == 1 || mp.begin()->S == 1) ans=i;
	}
	else{
	    if(mp.rbegin()->S == 1 && (mp.rbegin()->F)-(mp.begin()->F) == 1) ans=i;
	    if(mp.begin()->F == 1 && mp.begin()->S == 1) ans=i;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.