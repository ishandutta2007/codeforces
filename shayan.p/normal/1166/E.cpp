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

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

bitset<maxn>bs[55],tmp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m,n;cin>>m>>n;
    for(int i=0;i<m;i++){
	int cnt;cin>>cnt;
	while(cnt--){
	    int x;cin>>x;
	    bs[i][--x]=1;
	}
    }
    for(int i=0;i<m;i++){
	for(int j=i+1;j<m;j++){
	    tmp=bs[i] & bs[j];
	    if(!tmp.any()) return cout<<"impossible\n",0;
	}
    }
    return cout<<"possible\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.