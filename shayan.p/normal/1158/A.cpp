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

int a[maxn],b[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    ll ans=0,sm=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	ans+=1ll*a[i]*m;
    }
    for(int i=0;i<m;i++){
	cin>>b[i];
	sm+=b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    if(a[n-1]>b[0]) return cout<<-1<<endl,0;
    if(a[n-1]==b[0]){
	ans-=1ll * a[n-1] * m - sm;
    }
    else{
	ans-=1ll* a[n-1] * m - sm + a[n-2] - a[n-1];
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.