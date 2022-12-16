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

const int maxn=5e5+10,inf=5e8+10;

vector<int>tdo[maxn];
int a[maxn],p[maxn],n;
int mn[4*maxn],lz[4*maxn];

void restart(){
    for(int i=0;i<4*n+10;i++){
	mn[i]=lz[i]=0;
    }
}
void shift(int l,int r,int id){
    mn[id]+=lz[id];
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void add(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return;
    shift(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s){ lz[id]=x; shift(l,r,id); return; }
    int mid=(l+r)>>1;
    add(f,s,x,l,mid,2*id);
    add(f,s,x,mid,r,2*id+1);
    mn[id]=min(mn[2*id],mn[2*id+1]);
}
int fnd(int l=0,int r=n,int id=1){
    shift(l,r,id);
    int mid=(l+r)>>1;
    if(mn[id]>0) return -1;
    if(r-l==1) return l;
    int ans=fnd(l,mid,2*id);
    if(ans==-1) ans=fnd(mid,r,2*id+1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
	cin>>n;
	restart();
	for(int i=0;i<n;i++){
	    tdo[i].clear();
	}
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    if(a[i]!=-1){
		add(i,--a[i],1);
		if(a[i]==n) add(i,i+1,-1);
		tdo[a[i]].PB(i);
	    }
	}
	int C=0;
	for(int i=0;i<n;i++){
	    int id=fnd();
	    if(id==-1){
		cout<<-1<<"\n";
		goto Hell;
	    }
	    p[id]=C++;
	    add(id,id+1,inf);
	    if(a[id]!=-1) add(id,a[id],-1);
	    for(int x:tdo[id]) add(x,x+1,-1);
	}
	for(int i=0;i<n;i++){
	    cout<<n-p[i]<<" ";
	}
	cout<<"\n";
    Hell:;
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.