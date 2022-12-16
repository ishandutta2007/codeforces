// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define y1 salam

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10;
const ll inf=4e18;

int x1[maxn],x2[maxn],y1[maxn],y2[maxn],arr1[2*maxn],arr2[2*maxn],C1,C2;
vector<pair<int,pair<pii,int> > >tdo[2*maxn];// range weight // pos is weght
int cnt[8*maxn],wh[8*maxn],par[maxn];
ll W[maxn],S[maxn];
int lz[8*maxn];

int Find(int u){
    if(par[u]<0) return u;
    return (par[u]=Find(par[u]));
}

void Merge(int a,int b){
    if((a=Find(a))==(b=Find(b))) return;
    if(par[a]>par[b]) swap(a,b);
    S[a]+=S[b];
    W[a]+=W[b];
    par[a]+=par[b];
    par[b]=a;
}

void get(int l,int r,int id){
    if(lz[id]==-1) return;
    if(l!=r){
	if(lz[2*id]==-1) lz[2*id]=lz[id];
	else Merge(lz[2*id],lz[id]);
	if(lz[2*id+1]==-1) lz[2*id+1]=lz[id];
	else Merge(lz[2*id+1],lz[id]);
    }
    if(l==r && cnt[id]!=0)
	Merge(lz[id],wh[id]);
    lz[id]=-1;
}

void Add(int pos,int x,int delta,int l=0,int r=2*maxn-1,int id=1){
    get(l,r,id);
    if(pos<l || r<pos)return;
    if(l==r){
	if(delta==1) wh[id]=x,cnt[id]=1;
	else wh[id]=0,cnt[id]=0;
	return;
    }
    int mid=(l+r)/2;
    Add(pos,x,delta,l,mid,2*id);
    Add(pos,x,delta,mid+1,r,2*id+1);
    cnt[id]=cnt[2*id]+cnt[2*id+1];
}

void Merge_seg(int f,int s,int x,int l=0,int r=2*maxn-1,int id=1){
    get(l,r,id);
    if(s<l || r<f || cnt[id]==0) return;
    if(f<=l && r<=s){
	S[Find(x)]+=cnt[id];
	lz[id]=x;
	get(l,r,id);
	return;
    }
    int mid=(l+r)/2;
    Merge_seg(f,s,x,l,mid,2*id);
    Merge_seg(f,s,x,mid+1,r,2*id+1);
}

int main(){
    memset(par,-1,sizeof par);
    memset(lz,-1,sizeof lz);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	arr1[C1++]=x1[i];
	arr1[C1++]=x2[i];
	arr2[C2++]=y1[i];
	arr2[C2++]=y2[i];
    }
    sort(arr1,arr1+C1);
    sort(arr2,arr2+C2);
    C1=unique(arr1,arr1+C1)-arr1;
    C2=unique(arr2,arr2+C2)-arr2;
    for(int i=0;i<n;i++){
	if(x1[i]==x2[i]) W[i]=y2[i]-y1[i]+1;
	else W[i]=x2[i]-x1[i]+1;
	x1[i]=lower_bound(arr1,arr1+C1,x1[i])-arr1;
	x2[i]=lower_bound(arr1,arr1+C1,x2[i])-arr1;
	y1[i]=lower_bound(arr2,arr2+C2,y1[i])-arr2;
	y2[i]=lower_bound(arr2,arr2+C2,y2[i])-arr2;
	if(x1[i]==x2[i]) tdo[y1[i]].PB({0,{{x1[i],1},i}}),tdo[y2[i]].PB({2,{{x1[i],0},i}});
	if(y1[i]==y2[i]) tdo[y1[i]].PB({1,{{x1[i],x2[i]},i}});
    }
    for(int i=0;i<2*maxn;i++){
	sort(tdo[i].begin(),tdo[i].end());
	for(auto it:tdo[i]){
	    int task=it.F;
	    if(task==0){// add
		Add(it.S.F.F,it.S.S,1);
	    }
	    if(task==1){// merge
		Merge_seg(it.S.F.F,it.S.F.S,it.S.S);
	    }
	    if(task==2){// delete
		Add(it.S.F.F,it.S.S,-1);
	    }
	}
    }
    for(int i=0;i<2*maxn;i++){
	Add(i,0,0);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
	if(par[i]<0){
	    ans=max(ans,W[i]-S[i]-1);
	}
    }
    printf("%lld\n",ans);
    return 0;
}