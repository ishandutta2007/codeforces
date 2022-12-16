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
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;

const int maxn=1e5+10;

ll val[20][maxn];
int lstl[20][maxn],lstr[20][maxn];
pii seg[maxn];
int C=1,wh[maxn],n;

vector<pil> v[maxn];
pil pr[maxn];
ll ds[maxn];

pil far(int u,int par=-1,ll W=0){
    pr[u]={par,W};
    pil ans={u,0};
    for(pil p:v[u]){
	if(p.F!=par){
	    pil pp=far(p.F,u,p.S);
	    if((pp.S+p.S)>ans.S)
		ans={pp.F,pp.S+p.S};
	}
    }
    return ans;
}

void dfs(int u,int par){
    seg[u].F=C;
    for(pil p:v[u]){
	if(p.F!=par){
	    ds[p.F]=ds[u]+p.S;
	    dfs(p.F,u);
	}
    }
    seg[u].S=C;
    wh[C]=u;
    C++;
}

void build(int l=1,int r=n,int h=0){
    if(l==r){
	val[h][l]=ds[wh[l]];
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,h+1);
    build(mid+1,r,h+1);
    int pt1=l,pt2=mid+1;
    for(int nw=l;nw<=r;nw++){
	if(pt1>mid){
	    val[h][nw]=val[h+1][pt2++];
	}
	else if(pt2>r){
	    val[h][nw]=val[h+1][pt1++];
	}
	else if(val[h+1][pt1]<=val[h+1][pt2]){
	    val[h][nw]=val[h+1][pt1++];
	}
	else{
	    val[h][nw]=val[h+1][pt2++];
	}
	lstl[h][nw]=pt1-1;
	lstr[h][nw]=pt2-1;
    }
}

int _ask(int f,int s,int pt,int l=1,int r=n,int h=0){
    if(f>s || l>r || s<l || r<f || pt<l) return 0;
    if(f<=l && r<=s) return pt-l+1;
    int mid=(l+r)>>1;
    return _ask(f,s,lstl[h][pt],l,mid,h+1)+_ask(f,s,lstr[h][pt],mid+1,r,h+1);
}

int ask(int f,int s,ll x){
    return _ask(f,s,upper_bound(val[0]+1,val[0]+n+1,x)-val[0]-1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;
	ll x;
	cin>>a>>b>>x;
	v[a].PB({b,x});
	v[b].PB({a,x});
    }
    int B=far(1).F;
    pil pp=far(B);
    int A=pp.F;
    ll diam=pp.S,MN=diam,W1,W2,nw=0;
    int tmp=A,M1=-1,M2=-1;
    
    while(tmp!=-1){
	if(nw<=(diam-nw) && nw+pr[tmp].S>(diam-nw-pr[tmp].S)){
	    M1=tmp;
	    M2=pr[tmp].F;
	    MN=min(W1=diam-nw,W2=nw+pr[tmp].S);
	    break;
	}
	nw+=pr[tmp].S;
	tmp=pr[tmp].F;
    }

    dfs(M1,M2);
    dfs(M2,M1);
    build();
    
    int q;cin>>q;
    while(q--){
	ll lim;cin>>lim;
	int ans=0;
	for(int i=1;i<=n;i++)
	    ans=max(ans,ask(seg[i].F,seg[i].S,lim+ds[i]));
   	ans=max(ans,ask(seg[M1].F,seg[M1].S,lim-W1+MN)+ask(seg[M2].F,seg[M2].S,lim-W2+MN));
	cout<<ans<<"\n";
    }
    return 0;
}