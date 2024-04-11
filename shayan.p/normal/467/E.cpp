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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

map<int,int>lst;
int a[maxn],bf[maxn],n;
vector<pii> val[4*maxn];
int dp[maxn],mx[maxn],fnd1[maxn],fnd2[maxn];

void build(int l=1,int r=n,int ind=1){
    if(l==r){
	val[ind].PB({bf[r],r});
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*ind);
    build(mid+1,r,2*ind+1);
    val[ind].resize(sz(val[2*ind])+sz(val[2*ind+1]));
    merge(val[2*ind].begin(),val[2*ind].end(),val[2*ind+1].begin(),val[2*ind+1].end(),val[ind].begin());
}

pii _ask(vector<pii>&v,int x){
    int l=0,r=sz(v)-1;
    pii ans={0,0};
    while(l<=r){
	int mid=(l+r)/2;
	if(v[mid].F<x){
	    ans=v[mid];
	    l=mid+1;
	}
	else{
	    r=mid-1;
	}
    }
    return ans;
}

pii ask(int f,int s,int l=1,int r=n,int ind=1){
    if(f>s || l>r || s<l || r<f)return {0,0};
    if(f<=l && r<=s) return _ask(val[ind],f);
    int mid=(l+r)/2;
    return max(ask(f,s,l,mid,2*ind),ask(f,s,mid+1,r,2*ind+1));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	bf[i]=lst[a[i]];
	lst[a[i]]=i;
    }
    build();
    
    for(int i=1;i<=n;i++){
	mx[i]=mx[i-1];
	if(bf[i]==0)continue;
	pii p1=ask(bf[i]+1,i-1);
	pii p2={bf[bf[bf[i]]],bf[i]};
	pii p=max(p1,p2);
	if(p.F==0)continue;
	fnd1[i]=p.S;
	fnd2[i]=mx[p.F-1];
	dp[i]=1+dp[mx[p.F-1]];
	if(dp[i]>dp[mx[i-1]])
	    mx[i]=i;
    }

    printf("%d\n",4*dp[mx[n]]);

    int pt=mx[n];
    vector<int>ans;

    while(pt>0){
	ans.PB(a[pt]);
	ans.PB(a[fnd1[pt]]);
	ans.PB(a[pt]);
	ans.PB(a[fnd1[pt]]);
	pt=fnd2[pt];
    }

    reverse(ans.begin(),ans.end());

    for(int x:ans){
	printf("%d ",x);
    }
}