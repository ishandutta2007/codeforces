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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],arr[maxn],fn[maxn],n;
ll ans;

void add(int pos,int x){
    for(pos=pos+2;pos<maxn;pos+=(pos & -pos)){
	fn[pos]+=x;
	if(fn[pos]>=mod) fn[pos]-=mod;
    }
}
int ask(int pos){
    int ans=0;
    for(pos=pos+2;pos>0;pos-=(pos & -pos)){
	ans+=fn[pos];
	if(ans>=mod) ans-=mod;
    }
    return ans;
}

void calc(){
    memset(fn,0,sizeof fn);
    for(int i=0;i<n;i++){
	int id=lower_bound(arr,arr+n,a[i])-arr;
	ans=(ans + 1ll*ask(id)*(n-i) %mod * a[i])%mod;
	add(id,i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	ans=(ans + 1ll*(i+1)*(n-i) %mod *a[i])%mod;
	arr[i]=a[i];
    }
    sort(arr,arr+n);
    calc();
    reverse(a,a+n);
    calc();
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.