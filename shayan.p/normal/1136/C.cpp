// Wanna Hack? GL...

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

multiset<int>sta[maxn],stb[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    int x;cin>>x;
	    sta[i+j].insert(x);
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    int x;cin>>x;
	    stb[i+j].insert(x);
	}
    }
    for(int i=0;i<=n+m;i++){
	if(sta[i]!=stb[i]) return cout<<"NO\n",0;
    }
    return cout<<"YES\n",0;
}