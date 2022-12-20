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

const int maxn=6e5+10,LG=20;

int n;
int rnk[LG][maxn],lcp[LG][maxn],arr[maxn],val[2*maxn],wh[maxn],ID;
string s;

inline int LCP(int l,int r){
    int ln=31-__builtin_clz(r-l);
    return min(lcp[ln][l],lcp[ln][r-(1<<ln)]);
}

inline bool CMP(int a,int b){
    if(rnk[ID-1][a]!=rnk[ID-1][b]) return rnk[ID-1][a]<rnk[ID-1][b];
    if(a+(1<<(ID-1))>=n && b+(1<<(ID-1))>=n) return 0;
    if(a+(1<<(ID-1))>=n) return 1;
    if(b+(1<<(ID-1))>=n) return 0;
    return rnk[ID-1][a+(1<<(ID-1))]<rnk[ID-1][b+(1<<(ID-1))];
}

int _LCP(int a,int b){
    int ans=0;
    for(int i=LG-1;i>=0;i--){
	if(a+(1<<i)<=n && b+(1<<i)<=n && rnk[i][a]==rnk[i][b])
	    ans+=(1<<i),a+=(1<<i),b+=(1<<i);
    }
    return ans;
}

void build(){
    for(int i=0;i<n;i++)
	rnk[0][i]=s[i]-'a';
    for(int i=0;i<n;i++)
	arr[i]=i;
    for(ID=1;ID<LG;ID++){
	sort(arr,arr+n,CMP);
	for(int i=1;i<n;i++)
	    rnk[ID][arr[i]]=rnk[ID][arr[i-1]]+CMP(arr[i-1],arr[i]);
    }
    for(int i=0;i<n-1;i++)
	lcp[0][i]=_LCP(arr[i],arr[i+1]);
    for(int i=1;i<LG;i++)
	for(int j=0;j<n;j++)
	    lcp[i][j]=min(lcp[i-1][j],lcp[i-1][j+(1<<(i-1))]);
    for(int i=0;i<n;i++)
	wh[arr[i]]=i;
}

int rangef(int pos,int SZ){
    int l=0,r=pos-1,ans=pos;
    while(l<=r){
	int mid=(l+r)>>1;
	if(LCP(mid,pos)>=SZ)
	    ans=mid,r=mid-1;
	else
	    l=mid+1;
    }
    return ans;
}

int ranges(int pos,int SZ){
    int l=pos+1,r=n-1,ans=pos;
    while(l<=r){
	int mid=(l+r)>>1;
	if(LCP(pos,mid)>=SZ)
	    ans=mid,l=mid+1;
	else
	    r=mid-1;
    }
    return ans;
}

vector<int>vv[4*maxn];
int start[maxn],Size[maxn],A[maxn],C;

void build_seg(int l=0,int r=n,int id=1){
    if(r-l==1){
	vv[id].PB(A[l]);
	return;
    }
    int mid=(l+r)>>1;
    build_seg(l,mid,2*id);
    build_seg(mid,r,2*id+1);
    vv[id].resize(sz(vv[2*id])+sz(vv[2*id+1]));
    merge(vv[2*id].begin(),vv[2*id].end(),vv[2*id+1].begin(),vv[2*id+1].end(),vv[id].begin());
}

int ask(int f,int s,int L,int R,int l=0,int r=n,int id=1){
    if(f>=s || L>=R || l>=r || s<=l || r<=f) return 0;
    if(f<=l && r<=s) return lower_bound(vv[id].begin(),vv[id].end(),R)-lower_bound(vv[id].begin(),vv[id].end(),L);
    int mid=(l+r)>>1;
    return ask(f,s,L,R,l,mid,2*id)+ask(f,s,L,R,mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
	string str;cin>>str;
	Size[i]=sz(str);
	start[i]=C;
	s+=str;
	C+=sz(str)+1;s+="#";
    }
    ::n=sz(s);
    build();
    for(int i=0;i<sz(s);i++){
	int id=upper_bound(start,start+n,arr[i])-start-1;
	A[i]=(s[arr[i]]=='#'?-1:id);
    }
    build_seg();
    while(q--){
	int l,r,k;cin>>l>>r>>k;--k;
	cout<<ask(rangef(wh[start[k]],Size[k]),ranges(wh[start[k]],Size[k])+1,--l,r)<<"\n";
    }
    return 0;
}