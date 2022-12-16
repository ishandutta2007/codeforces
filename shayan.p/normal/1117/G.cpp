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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

vector<int> vl[maxn],vr[maxn];
int a[maxn],aft[maxn],bef[maxn],l[maxn],r[maxn],n;
ll lz[4*maxn],val[4*maxn],ans[maxn];

void Restart(){
    memset(lz,0,sizeof lz);
    memset(val,0,sizeof val);
}
void get(int l,int r,int id){
    val[id]+=lz[id]*(r-l);
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void Add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) { lz[id]+=x;get(l,r,id);return;}
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    val[id]=val[2*id]+val[2*id+1];
}
ll Ask(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return 0;
    get(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>n>>q;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    bef[0]=-1;
    for(int i=1;i<n;i++){
	bef[i]=i-1;
	while(bef[i]>=0 && a[bef[i]]<=a[i]) bef[i]=bef[bef[i]];
    }
    aft[n-1]=n;
    for(int i=n-2;i>=0;i--){
	aft[i]=i+1;
	while(aft[i]<n  && a[aft[i]]<=a[i]) aft[i]=aft[aft[i]];
    }
    for(int i=0;i<q;i++){
	cin>>l[i]; --l[i];
	vl[l[i]].PB(i);
    }
    for(int i=0;i<q;i++){
	cin>>r[i]; --r[i];
	vr[r[i]].PB(i);
    }
    for(int i=0;i<n;i++){
	Add(bef[i]+1,i,1);
	for(int id:vr[i])
	    ans[id]+=Ask(l[id],r[id]+1);
    }
    Restart();
    for(int i=n-1;i>=0;i--){
	Add(i+1,aft[i],1);
	for(int id:vl[i])
	    ans[id]+=Ask(l[id],r[id]+1);
    }
    for(int i=0;i<q;i++){
	cout<<ans[i]+r[i]-l[i]+1<<" ";
    }
    return cout<<endl,0;
}