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

const int maxn=1e5+10,inf=2e9;

int mn[4*maxn],mx[4*maxn],lz[4*maxn],arrs[maxn],arrm[maxn],arrr[maxn],n;
pii srt1[20][maxn],srt2[20][maxn];
ll begs[4*maxn],smm1[20][maxn],smm2[20][maxn],smr1[20][maxn],smr2[20][maxn];

void build(int l=1,int r=n,int ind=1,int h=0){
    if(l==r){
	if(arrr[l]==0){
	    srt1[h][l]=srt2[h][l]={inf,l};
	}
	else{
	    srt1[h][l]={(arrm[l]-arrs[l]+arrr[l]-1)/arrr[l],l};
	    srt2[h][l]={(arrm[l]+arrr[l]-1)/arrr[l],l};
	}
	begs[ind]=arrs[l];
	smm1[h][l]=arrm[l]-arrs[l];
	smm2[h][l]=arrm[l];
	smr1[h][l]=smr2[h][l]=arrr[l];
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*ind,h+1);
    build(mid+1,r,2*ind+1,h+1);
    merge(srt1[h+1]+l,srt1[h+1]+mid+1,srt1[h+1]+mid+1,srt1[h+1]+r+1,srt1[h]+l);
    merge(srt2[h+1]+l,srt2[h+1]+mid+1,srt2[h+1]+mid+1,srt2[h+1]+r+1,srt2[h]+l);
    begs[ind]=begs[2*ind]+begs[2*ind+1];
    for(int i=l;i<=r;i++){
	smm1[h][i]=(i==l?0:smm1[h][i-1])+arrm[srt1[h][i].S]-arrs[srt1[h][i].S];
	smm2[h][i]=(i==l?0:smm2[h][i-1])+arrm[srt2[h][i].S];
    }
    for(int i=r;i>=l;i--){
	smr1[h][i]=(i==r?0:smr1[h][i+1])+arrr[srt1[h][i].S];
	smr2[h][i]=(i==r?0:smr2[h][i+1])+arrr[srt2[h][i].S];
    }
}

void get(int l,int r,int ind){
    if(lz[ind]==-1) return;
    mn[ind]=mx[ind]=lz[ind];
    if(l!=r)
	lz[2*ind]=lz[2*ind+1]=lz[ind];
    lz[ind]=-1;
}

ll ask(int f,int s,int tm,int l=1,int r=n,int ind=1,int h=0){
    if(l>r || f>s)return 0;
    get(l,r,ind);
    if(s<l || r<f) return 0;
    if(f<=l && r<=s && mn[ind]==mx[ind]){
	ll ans=0;
	if(mn[ind]==-1){
	    ans=begs[ind];
	    pii P={tm,inf};
	    int pos=upper_bound(srt1[h]+l,srt1[h]+r+1,P)-srt1[h];
	    if(pos<=r)	ans+=smr1[h][pos]*tm;
	    if(pos>l) ans+=smm1[h][pos-1];
	}
	else{
	    pii P={tm-mn[ind],inf};
	    int pos=upper_bound(srt2[h]+l,srt2[h]+r+1,P)-srt2[h];
	    if(pos<=r) ans+=smr2[h][pos]*(tm-mn[ind]);
	    if(pos>l) ans+=smm2[h][pos-1];
	}
	lz[ind]=tm;
	get(l,r,ind);
  	return ans;
    }
    int mid=(l+r)/2;
    ll ans=ask(f,s,tm,l,mid,2*ind,h+1)+ask(f,s,tm,mid+1,r,2*ind+1,h+1);
    mn[ind]=min(mn[2*ind],mn[2*ind+1]);
    mx[ind]=max(mx[2*ind],mx[2*ind+1]);
    return ans;
}

int main(){
    memset(lz,-1,sizeof lz);
    memset(mn,-1,sizeof mn);
    memset(mx,-1,sizeof mx);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
	cin>>arrs[i]>>arrm[i]>>arrr[i];
    build();
    int q;cin>>q;
    while(q--){
	int t,l,r;cin>>t>>l>>r;
	cout<<ask(l,r,t)<<"\n";
    }
    return 0;
}