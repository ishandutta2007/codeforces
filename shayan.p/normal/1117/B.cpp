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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;i++)
	cin>>a[i];
    sort(a,a+n,greater<int>());
    ll sm=1ll*k*a[0]+1ll*a[1];
    ll ans=sm*(m/(k+1))+1ll*a[0]*(m%(k+1));
    return cout<<ans<<endl,0;
}