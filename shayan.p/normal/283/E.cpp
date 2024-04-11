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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],cnt[4*maxn],n;
bool lz[4*maxn];
vector<int>on[maxn],off[maxn];

void get(int l,int r,int id){
    if(lz[id]==0) return;
    cnt[id]=r-l+1-cnt[id];
    if(l!=r){
	lz[2*id]^=1;
	lz[2*id+1]^=1;
    }
    lz[id]=0;
}

void add(int f,int s,int l=0,int r=n-1,int id=1){
    if(f>s || l>r) return;
    get(l,r,id);
    if(s<l || r<f) return;
    if(f<=l && r<=s){
	lz[id]=1;
	get(l,r,id);
	return;
    }
    int mid=(l+r)>>1;
    add(f,s,l,mid,2*id);
    add(f,s,mid+1,r,2*id+1);
    cnt[id]=cnt[2*id]+cnt[2*id+1];
}

int ask(int f,int s,int l=0,int r=n-1,int id=1){
    if(f>s || l>r) return 0;
    get(l,r,id);
    if(s<l || r<f) return 0;
    if(f<=l && r<=s) return cnt[id];
    int mid=(l+r)>>1;
    return ask(f,s,l,mid,2*id)+ask(f,s,mid+1,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k;cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<k;i++){
	int x,y;cin>>x>>y;
	x=lower_bound(a,a+n,x)-a;
	y=upper_bound(a,a+n,y)-a;
	if(x<y){
	    on[y-1].PB(x);
	    off[x].PB(y-1);
	}
    }
    ll ans=(1ll*n*(n-1)*(n-2))/6;
    for(int i=n-1;i>=0;i--){
	for(int j:on[i])
	    add(j,i);
	int num=ask(i+1,n-1)+i-ask(0,i-1);
	ans-=(1ll*num*(num-1))/2;
	for(int j:off[i])
	    add(i,j);
    }
    cout<<ans<<endl;
    return 0;
}