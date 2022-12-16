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

const int maxn=2e5+10,inf=1e9;

int a[maxn],ANS=-1,L=-1,R=-1,n,k;
ll mn[4*maxn],lz[4*maxn];

inline void Best(int l,int r){
    if(r-l>ANS) ANS=r-l,R=r-1,L=l;
    if(r-l==ANS && l<L) R=r-1,L=l;
}

void get(int l,int r,int id){
    mn[id]+=lz[id];
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
    if(f<=l && r<=s) {lz[id]+=x; get(l,r,id) ; return; }
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    mn[id]=min(mn[2*id],mn[2*id+1]);
}
int Ask(int x,int l=0,int r=n,int id=1){
    get(l,r,id);
    if(r-l==1) return l;
    int mid=(l+r)>>1;
    if(mn[2*id]+lz[2*id]<=x) return Ask(x,l,mid,2*id);
    return Ask(x,mid,r,2*id+1);
}

void solve(int f,int s){// [)
    map<int,int>lst;
    deque<int> MX,MN;
    MX.PB(-1),MN.PB(-1);
    int pos=f;
    for(int i=f;i<s;i++){
	if(lst.count(a[i])){
	    int num=lst[a[i]]+1;
	    Add(pos,num,inf);
	    pos=max(pos,num);
	}
	lst[a[i]]=i;
	while(MX.back()!=-1 && a[MX.back()]<a[i]){
	    Add(MX[sz(MX)-2]+1,MX.back()+1,a[i]-a[MX.back()]);
	    MX.pop_back();
	}
	while(MN.back()!=-1 && a[MN.back()]>a[i]){
	    Add(MN[sz(MN)-2]+1,MN.back()+1,a[MN.back()]-a[i]);
	    MN.pop_back();
	}
	MX.PB(i),MN.PB(i);
	Add(pos,i,-1);
	Best(Ask(k),i+1);
    }
    Add(pos,s,inf);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int d;cin>>n>>k>>d;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    if(d==0){
	int beg=0,bef=a[0];
	for(int i=0;i<n;i++){
	    if(a[i]!=bef){
		Best(beg,i);
		beg=i,bef=a[i];
	    }
	}
	Best(beg,n);
    }
    else{
	int beg=0,bef=a[0]%d;
	for(int i=0;i<n;i++){
	    int num=a[i]%d;
	    num=(num+d)%d;
	    a[i]=(a[i]-num)/d;
	    if(bef!=num)
		solve(beg,i),beg=i,bef=num;
	}
	solve(beg,n);
    }
    return cout<<L+1<<" "<<R+1<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.