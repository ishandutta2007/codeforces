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

const int maxn=4e5+10,Max=2e5+4;

vector<int>v1[maxn],v2[maxn];
multiset<int>ms1,ms2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int a,b;cin>>a>>b;
	if((a+b)&1) v1[a+b+Max].PB(a-b);
	else        v2[a+b+Max].PB(a-b);
    }
    ll ans=0;
    ms1.clear(),ms2.clear();
    for(int i=1;i<maxn;i+=2){
	for(int x:v1[i])
	    ms2.insert(x);
    }
    for(int i=1;i<maxn;i+=2){
	for(int x:v1[i]){
	    ms2.erase(ms2.find(x));
	    ms1.insert(x);
	}
	if(ms1.empty() || ms2.empty()) continue;
	int L=max(*ms1.begin(),*ms2.begin()),R=min(*ms1.rbegin(),*ms2.rbegin());
	if(L<=R) ans+=(R-L)>>1;
    }

    ms1.clear(),ms2.clear();
    for(int i=0;i<maxn;i+=2){
	for(int x:v2[i])
	    ms2.insert(x);
    }
    for(int i=0;i<maxn;i+=2){
	for(int x:v2[i]){
	    ms2.erase(ms2.find(x));
	    ms1.insert(x);
	}
	if(ms1.empty() || ms2.empty()) continue;
	int L=max(*ms1.begin(),*ms2.begin()),R=min(*ms1.rbegin(),*ms2.rbegin());
	if(L<=R) ans+=(R-L)>>1;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.