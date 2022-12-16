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
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,S1=350,S2=350;// size of block // count of block
const ll inf=4e18;

priority_queue<pii>pq;
pli p[maxn],ans[maxn];
bool mark[maxn];
int n;

struct fenwick{
    int sm[maxn],tot;
    fenwick(){
	tot=0;
	memset(sm,0,sizeof sm);
    }
    void add(int ind){
	ind++;
	tot++;
	while(ind<maxn)
	    sm[ind]++,ind+=(ind & -ind);
    }
    int ask(int ind){// baad mosavi inja
	ind=min(ind,maxn-1);
	int ans=tot;
	while(ind>0)
	    ans-=sm[ind],ind-=(ind & -ind);
	return ans;
    }
};fenwick fn;

struct CHT{
    vector<pll>vec;
    inline ll gety(int ind,ll x){
	return vec[ind].F*x+vec[ind].S;
    }
    bool bad(pll A,pll B,pll C){
	return (B.S-A.S)*(B.F-C.F)>=(B.S-C.S)*(B.F-A.F);
    }
    void add(ll a,ll b){
	if(sz(vec)>0 && vec.back().F==a){
	    if(b<vec.back().S) vec.pop_back();
	    else return;
	}
	while(sz(vec)>1 && bad(vec[sz(vec)-2],vec[sz(vec)-1],{a,b}))
	    vec.pop_back();
	vec.PB({a,b});
    }
    pli ask(ll x){
	if(sz(vec)==0) return {inf,-1};
	int l=0,r=sz(vec)-1;
	ll ans=gety(0,x);
	int ans2=-vec[0].F;
	while(l<r){
	    int mid=(l+r)>>1;
	    if(gety(mid,x)>gety(mid+1,x))
		l=mid+1,ans=gety(mid+1,x),ans2=-vec[mid+1].F;
	    else
		r=mid,ans=gety(mid,x),ans2=-vec[mid].F;
	}
	return {ans,ans2};
    }
};CHT cht[S2];

void build(){
    for(int i=0;i<n;i++)
	cht[i/S1].add(-p[i].F,-p[i].F*(n-i));
}

void Delete(int id){
    mark[id]=1;
    fn.add(id);
    int sid=id/S1,L=sid*S1,R=L+S1-1,cnt=0;
    cht[sid].vec.clear();
    for(int i=L;i<=R;i++){
	cnt+=mark[i];
    }
    for(int i=L;i<=min(n-1,R);i++){
	cnt-=mark[i];
	if(!mark[i])
	    cht[sid].add(-p[i].F,-p[i].F*(n-i-cnt));
    }
}

pli Ask(){
    pli ans={-inf,-1};
    for(int i=0;i<S2;i++){
	pli P=cht[i].ask(-fn.ask(i*S1+S1));
	P.F*=-1;ans=max(ans,P);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int w,MX=0;cin>>n>>w;
    for(int i=0;i<n;i++)
	cin>>p[i].F>>p[i].S,MX=max(MX,p[i].S);
    sort(p,p+n);
    for(int i=0;i<n;i++)
	pq.push({p[i].S,i});
    build();
    for(int i=MX+1;i>=0;i--){
	while(sz(pq) && pq.top().F>=i){
	    Delete(pq.top().S);
	    pq.pop();
	}
	pli P=Ask();
	if(P.F==-inf) P={0,0};
	ans[i]={1ll*w*i*(n-sz(pq))+P.F,P.S};
    }
    for(int i=0;i<=MX+1;i++){
	cout<<ans[i].F<<" "<<ans[i].S<<"\n";
    }
    return 0;
}