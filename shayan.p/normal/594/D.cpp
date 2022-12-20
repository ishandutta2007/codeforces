// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,MAX=1e6+10,mod=1e9+7;

int n,zr[maxn],pr[MAX],inv[MAX],lst[MAX];
vector<pii> vp[maxn];
vector<pii>val[4*maxn];

void build(int l=1,int r=n,int ind=1){
    if(l==r){
	val[ind]=vp[r];
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*ind);
    build(mid+1,r,2*ind+1);
    val[ind].resize(sz(val[2*ind])+sz(val[2*ind+1]));
    merge(val[2*ind].begin(),val[2*ind].end(),val[2*ind+1].begin(),val[2*ind+1].end(),val[ind].begin());
}

int _ask(vector<pii>&v,int x){
    int l=0,r=sz(v)-1,ans=1;
    while(l<=r){
	int mid=(l+r)/2;
	if(v[mid].F<x){
	    ans=v[mid].S;
	    l=mid+1;
	}
	else{
	    r=mid-1;
	}
    }
    return ans;
}

int ask(int f,int s,int l=1,int r=n,int ind=1){
    if(f>s || l>r || s<l || r<f)return 1;
    if(f<=l && r<=s)return _ask(val[ind],f);
    int mid=(l+r)/2;
    return (1ll*ask(f,s,l,mid,2*ind)*ask(f,s,mid+1,r,2*ind+1))%mod;
}

int tavan(int a,int b){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%mod;
	a=(1ll*a*a)%mod;
	b/=2;
    }
    return ans;
}

int main(){
    for(int i=2;i<MAX;i++){
	if(pr[i]==0){
	    for(int j=i;j<MAX;j+=i)
		pr[j]=i;
	}
    }
    
    inv[1]=1;
    for(int i=2;i<MAX;i++){
	inv[i]=(1ll*(-(mod/i))*inv[mod%i])%mod;
	if(inv[i]<0)inv[i]+=mod;
    }
    
    zr[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	int x;scanf("%d",&x);
	zr[i]=(1ll*zr[i-1]*x)%mod;
	while(x>1){
	    int p=pr[x];
	    while(x%p==0)
		x/=p;
	    vp[i].PB({lst[p],p});
	    lst[p]=i;
	}
	sort(vp[i].begin(),vp[i].end());
    }
    
    build();

    for(int i=1;i<(4*maxn);i++){
	for(int j=0;j<sz(val[i]);j++){
	    val[i][j].S=(1ll*(val[i][j].S-1)*inv[val[i][j].S])%mod;
	    val[i][j].S=(1ll*(j==0?1:val[i][j-1].S)*val[i][j].S)%mod;
	}
    }
    
    int q;scanf("%d",&q);
    while(q--){
	int l,r;scanf("%d%d",&l,&r);
	int ans=(1ll*((1ll*zr[r]*tavan(zr[l-1],mod-2))%mod)*ask(l,r))%mod;
	printf("%d\n",ans);
    }
}