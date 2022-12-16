// Mikaeel_noob_e_sag_e

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

const int maxn=5e5+10,maxn2=24*maxn,mod=1e9+7;
const ll inf=1e18;

int n,wh[4*maxn],a[maxn],C;
int ans[maxn];
vector<int> v[maxn2],vec;
bool mark[maxn2];

void build(int l=0,int r=n,int id=1){
    if(r-l==1){
	v[l].PB(wh[id]=C++);
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    v[wh[2*id]].PB(wh[id]=C++);
    v[wh[2*id+1]].PB(wh[id]);
}

void del(int pos,int l=0,int r=n,int id=1){
    wh[id]=C++;
    if(r-l==1) return;
    int mid=(l+r)>>1;
    if(pos<mid)	del(pos,l,mid,2*id);
    else del(pos,mid,r,2*id+1);
    v[wh[2*id]].PB(wh[id]);
    v[wh[2*id+1]].PB(wh[id]);
}

void add(int f,int s,int u,int l=0,int r=n,int id=1){
    if(s<=f || r<=l || s<=l || r<=f) return;
    if(f<=l && r<=s) {v[wh[id]].PB(u); return; }
    int mid=(l+r)>>1;
    add(f,s,u,l,mid,2*id);
    add(f,s,u,mid,r,2*id+1);
}

void dfs(int u){
    mark[u]=1;
    for(int y:v[u]){
	if(!mark[y])
	    dfs(y);
    }
    if(u<n){
	vec.PB(u);
    }
}

bool bl[maxn];

void checker(){
    for(int i=0;i<n;i++){
	int ANS=-1;
	for(int j=0;j<n && ANS==-1;j++){
	    if(bl[j]==0 && ans[j]>ans[i])
		ANS=j,bl[j]=1;
	}
	cout<<ANS+(ANS!=-1)<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++)
	cout<<vec[i]+1<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n; C=n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==-1) a[i]=n;
	else a[i]--;
    }
    build();
    for(int i=0;i<n;i++){
	if(a[i]<i) add(0,a[i],i);
	else add(0,i,i),add(i+1,a[i],i);
	if(a[i]!=n) del(a[i]),v[i].PB(a[i]);
    }
    for(int i=0;i<C;i++){
	if(!mark[i]) dfs(i);
    }
    reverse(vec.begin(),vec.end());
    for(int i=0;i<sz(vec);i++){
	ans[vec[i]]=i;
    }
    //    checker();
    for(int i=0;i<n;i++){
	cout<<ans[i]+1<<" ";
    }
    return cout<<endl,0;
}