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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

pii p[maxn],pp[maxn];
int m,n;

bool check(int x){
    for(int i=0;i<m;i++)
	pp[i]={(p[i].F+x)%n, (p[i].S+x)%n};
    for(int i=0;i<m;i++)
	if(pp[i].F>pp[i].S) swap(pp[i].F,pp[i].S);
    sort(pp,pp+m);
    for(int i=0;i<m;i++)
	if(pp[i]!=p[i]) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
	cin>>p[i].F>>p[i].S;
	--p[i].F,--p[i].S;
	if(p[i].F>p[i].S) swap(p[i].F,p[i].S);
    }
    sort(p,p+m);
    for(int i=1;i<n;i++){
	if(n%i==0 && check(i)){
	    return cout<<"Yes\n",0;
	}
    }
    return cout<<"No\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.