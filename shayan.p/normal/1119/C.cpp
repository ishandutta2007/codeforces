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

const int maxn=510,mod=1e9+7;
const ll inf=1e18;

bool c[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int w=0;w<2;w++){
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		bool x;cin>>x;
		c[0][0]^=x;
		c[i][0]^=x;
		c[0][j]^=x;
	    }
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(c[i][j]) return cout<<"No\n",0;
	}
    }
    return cout<<"Yes\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.