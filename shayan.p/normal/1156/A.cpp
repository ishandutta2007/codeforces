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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    bool bad=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
	if(a[i]!=1 && a[i+1]!=1) bad=1;
	if(a[i]==1 && a[i+1]==1) bad=1;
    }
    if(bad) return cout<<"Infinite\n",0;
    int ans=0;
    for(int i=1;i<n;i++){
	if(a[i-1]==1){
	    ans+= (a[i]==2 ? 3 : 4);
	    if(i>=2 && a[i]==2 && a[i-2]==3) ans--;
	}
	if(a[i-1]==2){
	    ans+=3;
	}
	if(a[i-1]==3){
	    ans+=4;
	}
    }
    return cout<<"Finite\n"<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.