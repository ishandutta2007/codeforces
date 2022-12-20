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

int arr[maxn],C,x[maxn],y[maxn],lst[maxn],sm[maxn];
map<int,vector< pair<int,bool> > >mp;
ll ans[maxn],val[maxn];

inline void Change(int Cnt,int nw,int x){
    ans[Cnt]+=1ll*(nw-lst[Cnt])*val[Cnt];
    val[Cnt]+=x;
    lst[Cnt]=nw;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>x[i]>>y[i];
	mp[x[i]-k].PB({y[i],1});
	mp[x[i]].PB({y[i],0});
	arr[C++]=y[i]-k;
	arr[C++]=y[i];
    }
    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr;
    for(auto &IT:mp){
	for(auto x:IT.S){
	    int l=lower_bound(arr,arr+C,x.F-k)-arr,r=lower_bound(arr,arr+C,x.F)-arr;
	    for(int i=l;i<r;i++){
		Change(sm[i],IT.F,-arr[i+1]+arr[i]);
		Change(sm[i]=sm[i]+(x.S?1:-1),IT.F,arr[i+1]-arr[i]);
	    }
	}
    }
    for(int i=1;i<=n;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.