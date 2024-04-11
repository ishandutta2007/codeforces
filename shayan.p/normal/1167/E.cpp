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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],val[4*maxn];
set<int>st;

void add(int f,int s,int x,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r || s<=l || r<=f) return;
    if(f<=l && r<=s){ val[id]=max(val[id],x); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
}
int ask(int pos,int l=0,int r=maxn,int id=1){
    if(r-l==1) return max(l,val[id]);
    int mid=(l+r)>>1,ans=val[id];
    if(pos<mid) ans=max(ans, ask(pos,l,mid,2*id));
    else        ans=max(ans, ask(pos,mid,r,2*id+1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x;cin>>n>>x;
    int lim=x;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
	auto it=st.lower_bound(a[i]);
	if(it!=st.begin()){
	    lim=min(lim,a[i]);
	    int A=*(st.begin());
	    int B=*(--it);
	    add(A+1,a[i],a[i]);
	    add(1,B,B);
	}
	st.insert(a[i]);
    }
    ll ans=0;
    for(int i=1;i<=lim;i++){
	ans+=x-ask(i)+1;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.