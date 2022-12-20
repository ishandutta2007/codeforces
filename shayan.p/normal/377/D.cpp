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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii>close[maxn],open[maxn];

int a[maxn],b[maxn],c[maxn],optl,optr;
int lazy[4*maxn],val[4*maxn];

void get(int l,int r,int id){
    val[id]+=lazy[id];
    if(l!=r){
	lazy[2*id]+=lazy[id];
	lazy[2*id+1]+=lazy[id];
    }
    lazy[id]=0;
}
void add(int f,int s,int x,int l=0,int r=maxn-1,int id=1){
    if(f>s || l>r) return;
    get(l,r,id);
    if(s<l || r<f) return;
    if(f<=l && r<=s) {lazy[id]+=x,get(l,r,id);return;}
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid+1,r,2*id+1);
    val[id]=max(val[2*id],val[2*id+1]);
}
pii ask(int f,int s,int l=0,int r=maxn-1,int id=1){
    if(f>s || l>r) return {-1,-1};
    get(l,r,id);
    if(s<l || r<f) return {-1,-1};
    int mid=(l+r)>>1;
    if(l==r) return {val[id],l};
    if(f<=l && r<=s){
	if(val[2*id]+lazy[2*id]>val[2*id+1]+lazy[2*id+1]) return ask(f,s,l,mid,2*id);
	return ask(f,s,mid+1,r,2*id+1);
    }
    pii ans=max(ask(f,s,l,mid,2*id),ask(f,s,mid+1,r,2*id+1));
    val[id]=max(val[2*id],val[2*id+1]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i]>>b[i]>>c[i];
	close[--c[i]].PB({--a[i],--b[i]});
	open[b[i]].PB({a[i],b[i]});
    }
    int ans=0;
    for(int i=0;i<maxn;i++){
	for(pii p:open[i])
	    add(p.F,p.S,1);
	pii p=ask(0,i);
	if(p.F>ans) optr=i,optl=p.S,ans=p.F;
	for(pii p:close[i])
	    add(p.F,p.S,-1);
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
	if(a[i]<=optl && optr<=c[i] && optl<=b[i] && b[i]<=optr)
	    cout<<i+1<<" ";
    }
    cout<<endl;
}