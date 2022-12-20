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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn],ans[maxn],Sum;
int L[maxn],R[maxn],par[maxn];
set<pll>st;
pll p[maxn];

int Find(int u){
    return par[u]<0?u:par[u]=Find(par[u]);
}
void Merge(int x,int y){
    x=Find(x),y=Find(y);
    int LL=L[x],RR=R[y];
    Sum-=a[R[x]]-a[L[x]]+a[R[y]]-a[L[y]];
    Sum+=a[RR]-a[LL];
    if(par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    L[x]=LL,R[x]=RR;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(par,-1,sizeof par);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
	L[i]=R[i]=i;
    }
    for(int i=0;i<n-1;i++){
	st.insert({a[i+1]-a[i],i});
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
	ll a,b;cin>>a>>b;
	p[i]={b-a,i};
    }
    sort(p,p+q);
    for(int i=0;i<q;i++){
	while(sz(st) && p[i].F>=st.begin()->F){
	    pll p=*st.begin();
	    st.erase(p);
	    p.S=Find(p.S);
	    Merge(R[p.S],R[p.S]+1);
	}
	ans[p[i].S]=Sum+1ll*(sz(st)+1)*(1+p[i].F);
    }
    for(int i=0;i<q;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.