// Phoenix

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

const int maxn=1e5+10;

vector<pii>v[maxn];
int n,a[maxn],bf[maxn],af[maxn];

struct Segment{// baste baz
    vector<pii>val[4*maxn];
    void build(int l=0,int r=n,int id=1){
	if(l+1==r){
	    sort(v[l].begin(),v[l].end());
	    val[id]=v[l];
	    return;
	}
	int mid=(l+r)/2;
	build(l,mid,2*id);
	build(mid,r,2*id+1);
	val[id].resize(sz(val[2*id])+sz(val[2*id+1]));
	merge(val[2*id].begin(),val[2*id].end(),val[2*id+1].begin(),val[2*id+1].end(),val[id].begin());
	for(int i=sz(val[id])-2;i>=0;i--)
	    val[id][i].S=max(val[id][i].S,val[id][i+1].S);
    }
    int ask(int f,int s,int x,int l=0,int r=n,int id=1){
	if(f>=s || l>=r || r<=f || s<=l) return -1;
	if(f<=l && r<=s){
	    pii P={x,-1};
	    auto it=lower_bound(val[id].begin(),val[id].end(),P);
	    if(it==val[id].end()) return -1;
	    return it->S;
	}
	int mid=(l+r)/2;
	return max(ask(f,s,x,l,mid,2*id),ask(f,s,x,mid,r,2*id+1));
    }
};Segment seg1,seg2;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    bf[0]=-1;
    af[n-1]=n;
    for(int i=1;i<n;i++){
	bf[i]=i-1;
	while(bf[i]>=0 && a[i]<=a[bf[i]])
	    bf[i]=bf[bf[i]];
    }
    for(int i=n-2;i>=0;i--){
	af[i]=i+1;
	while(af[i]<n && a[i]<=a[af[i]])
	    af[i]=af[af[i]];
    }
    
    for(int i=0;i<=n;i++){
	v[i].clear();
    }
    for(int i=0;i<n;i++){
	v[bf[i]+1].PB({af[i]-1,a[i]});
    }
    seg1.build();

    for(int i=0;i<=n;i++){
	v[i].clear();
    }
    for(int i=0;i<n;i++){
	v[bf[i]+1].PB({af[i]-bf[i]-1,a[i]});
    }
    seg2.build();

    int q;cin>>q;
    while(q--){
	int l,r,w;cin>>l>>r>>w;
	--l;--r;
	cout<<max(seg1.ask(0,l,l+w-1),seg2.ask(l,r-w+2,w))<<"\n";
    }
    return 0;
}