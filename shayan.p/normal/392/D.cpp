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

const int maxn=1e5+10,mod=1e9+7,inf=1e9;

map<int,int>mp[3];
vector<int>vec[maxn];
set<pii>st;
int lim[3],a[maxn],val[4*maxn],lz[4*maxn],n,N;

void build(int l=0,int r=N,int id=1){
    if(r-l==1){
	val[id]=l;
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    val[id]=min(val[2*id],val[2*id+1]);
}

void get(int l,int r,int id){
    val[id]+=lz[id];
    if(r-l>1){
	lz[2*id]+=lz[id];
	lz[2*id+1]+=lz[id];
    }
    lz[id]=0;
}
void Add(int f,int s,int x,int l=0,int r=N,int id=1){
    if(f>=s || l>=r) return;
    get(l,r,id);
    if(s<=l || r<=f) return;
    if(f<=l && r<=s) {lz[id]+=x; get(l,r,id); return;}
    int mid=(l+r)>>1;
    Add(f,s,x,l,mid,2*id);
    Add(f,s,x,mid,r,2*id+1);
    val[id]=min(val[2*id],val[2*id+1]);
}
int Ask(int f,int s,int l=0,int r=N,int id=1){
    if(f>=s || l>=r) return inf;
    get(l,r,id);
    if(s<=l || r<=f) return inf;
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)>>1;
    return min(Ask(f,s,l,mid,2*id),Ask(f,s,mid,r,2*id+1));
}

void _Add(int pos,int x){
    auto it=st.upper_bound({pos,1e9}); ++pos;
    if((prev(it)->S)>=x) return;
    if(it==st.end() || (it->F)>pos) st.insert({pos,prev(it)->S}),it=prev(it);
    while(it!=st.begin() && (prev(it)->S)<=x){
	int nm=prev(it)->S,ps=prev(it)->F;
	Add(ps,pos,x-nm);
	st.erase(prev(it));
	pos=ps;
    }
    st.insert({pos,x});
}
    
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n; N=n+1;
    for(int q=0;q<3;q++){
	for(int i=1;i<=n;i++){
	    int x;cin>>x;
	    if(mp[q].count(x)==0)
		mp[q][x]=i;
	}
    }
    for(int q=0;q<3;q++){
	for(pii p:mp[q]){
	    int num=0;
	    for(int w=0;w<3;w++)
		num+=mp[w].count(p.F);
	    if(num==1)
		lim[q]=max(lim[q],p.S);
	}
    }

    build();
    st.insert({0,0});
    _Add(n,lim[2]);
    
    for(pii p:mp[1]){
	if(mp[2].count(p.F) && mp[0].count(p.F)==0)
	    _Add(p.S-1,mp[2][p.F]);
    }
    for(pii p:mp[0]){
	vec[p.S].PB(p.F);
    }
    
    int ans=3*n;
    for(int i=n;i>=lim[0];i--){
	ans=min(ans,i+Ask(lim[1],N));
     	for(int x:vec[i]){
	    bool b1=mp[1].count(x),b2=mp[2].count(x);
	    if(b1 && b2){
		_Add(mp[1][x]-1,mp[2][x]);
	    }
	    else if(b1){
		lim[1]=max(lim[1],mp[1][x]);
	    }
	    else if(b2){
		_Add(n,mp[2][x]);
	    }
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.