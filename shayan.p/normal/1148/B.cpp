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

const int maxn=2e5+10;
const ll Big=1e11;

ll a[maxn],b[maxn];
int k,n,m;

bool check(ll x){
    if(k>=min(m,n)) return 1;
    int lm=0;
    while(lm<m && b[lm]<=x) lm++;
    int pt=0;
    for(int i=0;i<n;i++){
	while(pt<m && a[i]>b[pt]) pt++;
	if(k>=i+max(int(0),lm-pt)) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int A,B;cin>>n>>m>>A>>B>>k;
    for(int i=0;i<n;i++)
	cin>>a[i],a[i]+=A;
    for(int i=0;i<m;i++)
	cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll l=-1,r=Big;
    while(r-l>1){
    	ll mid=(l+r)>>1;
	if(check(mid)) l=mid;
	else r=mid;
    }
    if(r==Big) r=-1-B;
    return cout<<r+B<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.