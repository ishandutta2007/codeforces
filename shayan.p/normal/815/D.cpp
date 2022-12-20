// Can U hack it?

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

const int maxn=5e5+10,inf=1e9+10;

pair<int,pii> p[maxn];
pii pp[maxn];
int a[maxn],n,P,Q,R;
int mn1[4*maxn],mn2[4*maxn],cnt[4*maxn],lz[4*maxn];// az koja gharare befahmim ke bayad update he ya na
ll sm[4*maxn];

void get(int l,int r,int ind){
    if(lz[ind]<=mn1[ind])return;
    sm[ind]+=1ll*cnt[ind]*(lz[ind]-mn1[ind]);
    mn1[ind]=lz[ind];
    if(l!=r){
	lz[2*ind]=max(lz[2*ind],lz[ind]);
	lz[2*ind+1]=max(lz[2*ind+1],lz[ind]);
    }
    lz[ind]=0;
}

void Merge(int ind){
    cnt[ind]=0;
    sm[ind]=sm[2*ind]+sm[2*ind+1];
    mn1[ind]=min(mn1[2*ind],mn1[2*ind+1]);
    if(mn1[ind]==mn1[2*ind]) cnt[ind]+=cnt[2*ind];
    if(mn1[ind]==mn1[2*ind+1]) cnt[ind]+=cnt[2*ind+1];
    mn2[ind]=min(mn2[2*ind],mn2[2*ind+1]);
    if(mn1[ind]!=mn1[2*ind]) mn2[ind]=min(mn2[ind],mn1[2*ind]);
    if(mn1[ind]!=mn1[2*ind+1]) mn2[ind]=min(mn2[ind],mn1[2*ind+1]);
}

void Maximize(int f,int s,int x,int l=1,int r=Q,int ind=1){
    if(l>r || f>s)return;
    get(l,r,ind);
    if(s<l || r<f || mn1[ind]>=x)return;
    if(f<=l && r<=s && mn1[ind]<x && mn2[ind]>=x){
	lz[ind]=max(lz[ind],x);
	get(l,r,ind);
	return;
    }
    int mid=(l+r)/2;
    Maximize(f,s,x,l,mid,2*ind);
    Maximize(f,s,x,mid+1,r,2*ind+1);
    Merge(ind);
}

void build(int l=1,int r=Q,int ind=1){
    if(l==r){
	mn2[ind]=inf;
	mn1[ind]=a[l];
	cnt[ind]=1;
	sm[ind]=a[l];
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*ind);
    build(mid+1,r,2*ind+1);
    Merge(ind);
}

int main(){
    scanf("%d%d%d%d",&n,&P,&Q,&R);
    for(int i=1;i<=n;i++){
	scanf("%d%d%d",&p[i].F,&p[i].S.F,&p[i].S.S);
	pp[i]=p[i].S;
    }
    sort(p+1,p+n+1);
    sort(pp+1,pp+n+1);
    int id=n;
    for(int i=Q;i>=1;i--){
	a[i]=a[i+1];
	while(id>0 && pp[id].F>=i)
	    a[i]=max(a[i],pp[id--].S);
    }
    build();
    id=n;
    ll ans=0;
    for(int i=P;i>0;i--){
	while(id>0 && p[id].F>=i){
	    Maximize(1,p[id].S.F,R);
	    Maximize(1,Q,p[id].S.S);
	    id--;
	}
	ans+=1ll*R*Q-sm[1];
    }
    printf("%lld\n",ans);
    return 0;
}