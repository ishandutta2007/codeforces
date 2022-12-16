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

const int maxn=1e5+10,inf=1e9;

ll vl[4*maxn],lz[4*maxn];
int n,b[maxn];
set<pii>st;

void build(int l=0,int r=n,int id=1){
    if(r-l==1){
	cin>>vl[id];
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    vl[id]=vl[2*id]+vl[2*id+1];
}
void get(int l,int r,int id){
    vl[id]+=lz[id]*(r-l);
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
    if(f<=l && r<=s) {lz[id]+=x;get(l,r,id);return;}
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    vl[id]=vl[2*id]+vl[2*id+1];
}
ll Ask(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r) return 0;
    get(l,r,id);
    if(s<=l || r<=f) return 0;
    if(f<=l && r<=s) return vl[id];
    int mid=(l+r)>>1;
    return Ask(f,s,l,mid,2*id)+Ask(f,s,mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    build();
    for(int i=0;i<n-1;i++){
	cin>>b[i];
    }
    for(int i=0;i<n;i++){
	st.insert({i,i});
    }
    int q;cin>>q;
    while(q--){
	char task;cin>>task;
	if(task=='+'){
	    int pos,x;cin>>pos>>x; --pos;
	    auto it=st.upper_bound({pos,inf});
	    int L=prev(it)->F,R=prev(it)->S;
	    st.erase(prev(it));
	    if(L!=pos) st.insert({L,pos-1});
	    st.insert({pos,R});
	    --it;
	    while(true){
		int l=it->F,r=it->S;
		Add(l,r+1,x);
		if(next(it)==st.end()) break;
		int id1=next(it)->F,id2=r;
		ll A=Ask(id1,id1+1),B=Ask(id2,id2+1)+b[r];
		if(A>B) break;
		x=B-A;
		++it,st.erase(prev(it));
	    }
	    int r=it->S;
	    st.erase(it);
	    st.insert({pos,r});
	}
	else{
	    int l,r;cin>>l>>r;
	    cout<<Ask(--l,r)<<"\n";
	}
    }
    return 0;
}