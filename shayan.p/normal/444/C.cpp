// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll mx1[4*maxn],mx2[4*maxn],cnt1[4*maxn],cnt2[4*maxn],sm[4*maxn],lazy1[4*maxn],lazy2[4*maxn],lazys[4*maxn];
ll n;

void build(ll l=1,ll r=n,ll ind=1){
    if(l==r){
	mx1[ind]=r;
	cnt1[ind]=1;
	return;
    }
    ll mid=(l+r)/2;
    mx1[ind]=r;
    mx2[ind]=r-1;
    cnt1[ind]=cnt2[ind]=1;
    build(l,mid,2*ind);
    build(mid+1,r,2*ind+1);
}

void give(ll ind,ll A,ll B,ll C){
    lazys[ind]+=C;
    if(lazy1[ind]==0){
	lazy1[ind]=A;
	lazy2[ind]=B;
	return;
    }
    lazys[ind]+=abs(lazy2[ind]-A);
    lazy2[ind]=B;
}

void get(ll l,ll r,ll ind){
    if(lazy1[ind]==0)return;
    sm[ind]+=cnt1[ind]*abs(lazy1[ind]-mx1[ind])+cnt2[ind]*abs(lazy1[ind]-mx2[ind]);
    sm[ind]+=lazys[ind]*(r-l+1);
    cnt2[ind]=0,mx2[ind]=0;
    cnt1[ind]=r-l+1,mx1[ind]=lazy2[ind];/////////
    if(l==r){
	lazy1[ind]=lazy2[ind]=lazys[ind]=0;
	return;
    }
    give(2*ind,lazy1[ind],lazy2[ind],lazys[ind]);
    give(2*ind+1,lazy1[ind],lazy2[ind],lazys[ind]);
    lazy1[ind]=lazy2[ind]=lazys[ind]=0;
}

void add(ll f,ll s,ll x,ll l=1,ll r=n,ll ind=1){
    if(l>r || f>s)return;
    get(l,r,ind);
    if(r<f || s<l)return;
    if(f<=l && r<=s && mx2[ind]==0 ){
	lazy1[ind]=lazy2[ind]=x;
	get(l,r,ind);
	//	cout<<cnt1[ind]<<" "<<cnt2[ind]<<" "<<mx1[ind]<<" "<<mx2[ind]<<" "<<sm[ind]<<endl;
	return;
    }
    ll mid=(l+r)/2;
    add(f,s,x,l,mid,2*ind);
    add(f,s,x,mid+1,r,2*ind+1);
    pll A={mx1[2*ind],cnt1[2*ind]},B={mx2[2*ind],cnt2[2*ind]},C={mx1[2*ind+1],cnt1[2*ind+1]},D={mx2[2*ind+1],cnt2[2*ind+1]};
    if(A.F==B.F)A.S+=B.S,B.S=0;
    if(A.F==C.F)A.S+=C.S,C.S=0;
    if(A.F==D.F)A.S+=D.S,D.S=0;
    if(B.F==C.F)B.S+=C.S,C.S=0;
    if(B.F==D.F)B.S+=D.S,D.S=0;
    if(C.F==D.F)C.S+=D.S,D.S=0;
    if(A.S==0)A={0,0};
    if(B.S==0)B={0,0};
    if(C.S==0)C={0,0};
    if(D.S==0)D={0,0};
    if(A<B)swap(A,B);
    if(A<C)swap(A,C);
    if(A<D)swap(A,D);
    if(B<C)swap(B,C);
    if(B<D)swap(B,D);
    mx1[ind]=A.F,cnt1[ind]=A.S;
    mx2[ind]=B.F,cnt2[ind]=B.S;
    sm[ind]=sm[2*ind]+sm[2*ind+1];
}

ll ask(ll f,ll s,ll l=1,ll r=n,ll ind=1){
    if(l>r || f>s)return 0;
    get(l,r,ind);
    if(r<f || s<l)return 0;
    if(f<=l && r<=s)return sm[ind];
    ll mid=(l+r)/2;
    return ask(f,s,l,mid,2*ind)+ask(f,s,mid+1,r,2*ind+1);
}

int main(){
    ll m;cin>>n>>m;
    build();
    while(m--){
	ll t,l,r,x;cin>>t>>l>>r;
	if(t==1){
	    cin>>x;
	    add(l,r,x);
	}
	else{
	    cout<<ask(l,r)<<endl;
	}
    }
}