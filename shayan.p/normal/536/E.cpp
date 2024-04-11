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

int func[maxn],SZ[maxn],tp[maxn],st[maxn],h[maxn],w[maxn],C,n;
vector<pii>v[maxn];

int prep(int u,int par=0){
    SZ[u]=1;h[u]=h[par]+1;
    for(pii p:v[u]){
	if(p.F!=par)
	    SZ[u]+=prep(p.F,u);
    }
    return SZ[u];
}
void build(int u,int W=inf,int par=0,bool is=0){
    sort(v[u].begin(),v[u].end(),[](pii a,pii b){return SZ[a.F]<SZ[b.F];});
    if(par==0) v[u].PB({0,0});
    st[u]=C++;
    if(is) tp[u]=tp[par];
    else tp[u]=u;
    if(sz(v[u])>1)
	build(v[u][sz(v[u])-2].F,v[u][sz(v[u])-2].S,u,1);
    for(int i=0;i<sz(v[u])-2;i++)
	build(v[u][i].F,v[u][i].S,u,0);
    w[st[u]]=W;
}


int a[20][maxn],sonl[20][maxn],sonr[20][maxn];
pair<int,pii>p[20][maxn];

inline int Len(int l,int r){
    return max(0,r-l);
}
void buildS(int l=0,int r=n,int h=0){
    if(r-l==1){
	a[h][l]=w[l];
	p[h][l]={0,{1,1}};
	return;
    }
    int mid=(l+r)>>1;
    buildS(l,mid,h+1);
    buildS(mid,r,h+1);
    int pos1=mid,pos2=r,pos=r;
    while(l<pos){
	if(pos2==mid || (pos1!=l && a[h+1][pos1-1]>=a[h+1][pos2-1]))
	    a[h][--pos]=a[h+1][--pos1];
	else
	    a[h][--pos]=a[h+1][--pos2];
	sonl[h][pos]=pos1;
	sonr[h][pos]=pos2;
	auto p1=p[h+1][pos1],p2=p[h+1][pos2];
	if(pos1==mid) p1={0,{0,0}};
	if(pos2==r )  p2={0,{0,0}}; 
	p[h][pos]={p1.F+p2.F,{p1.S.F,p2.S.S}};
	bool all1=p1.S.F==mid-l,all2=p2.S.S==r-mid;
	if(all1) p[h][pos].S.F+=p2.S.F;
	if(all2) p[h][pos].S.S+=p1.S.S;
	if(!all1 && !all2) p[h][pos].F+=func[p1.S.S+p2.S.F];
    }
}
pair<int,pii> _Ask(int f,int s,int pos,int l=0,int r=n,int h=0){
    if(f>=s || l>=r || s<=l || r<=f || pos<l || r<=pos) return {0,{0,0}};
    if(f<=l && r<=s) return p[h][pos];
    int mid=(l+r)>>1;
    auto p1=_Ask(f,s,sonl[h][pos],l,mid,h+1),p2=_Ask(f,s,sonr[h][pos],mid,r,h+1);
    bool all1=p1.S.F==Len(max(f,l),min(s,mid)),all2=p2.S.S==Len(max(f,mid),min(s,r));
    pair<int,pii> ans={p1.F+p2.F,{p1.S.F,p2.S.S}};
    if(all1) ans.S.F+=p2.S.F;
    if(all2) ans.S.S+=p1.S.S;
    if(!all1 && !all2) ans.F+=func[p1.S.S+p2.S.F];
    return ans;
}
pair<int,pii> Ask(int f,int s,int x){
    return _Ask(f,s,lower_bound(a[0],a[0]+n,x)-a[0]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>n>>q;
    for(int i=1;i<=n-1;i++){
	cin>>func[i];
    }
    for(int i=1;i<=n-1;i++){
	int a,b,c;cin>>a>>b>>c;
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    prep(1);
    build(1);
    buildS();
    while(q--){
	int a,b,x;cin>>a>>b>>x;
	int cnta=0,cntb=0,ans=0;
	while(tp[a]!=tp[b]){
	    if(h[tp[a]]<h[tp[b]]) swap(a,b),swap(cnta,cntb);
	    auto it=Ask(st[tp[a]],st[a]+1,x);
	    if(it.S.S==st[a]-st[tp[a]]+1){
		cnta+=it.S.S;
	    }
	    else{
		ans+=func[it.S.S+cnta]+it.F;
		cnta=it.S.F;
	    }
	    a=v[tp[a]].back().F;
	}
	if(h[a]<h[b]) swap(a,b),swap(cnta,cntb);
	auto it=Ask(st[b]+1,st[a]+1,x);
	if(it.S.S==st[a]-st[b]){
	    ans+=func[cnta+cntb+it.S.S];
	}
	else{
	    ans+=func[cnta+it.S.S]+func[cntb+it.S.F]+it.F;
	}
	cout<<ans<<"\n";
    }
    return 0;
}