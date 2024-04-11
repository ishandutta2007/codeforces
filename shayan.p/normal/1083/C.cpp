/*// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
pii val[4*maxn];
int p[maxn],pp[maxn],n;
int arr[5];
pii Now;

int st[maxn],h[maxn],sp[20][2*maxn],CC;
vector<int>vec;
int start[maxn];

void dfs(int u=0,int par=-1){
    st[u]=CC++;
    sp[0][u]=par;
    h[u]=(par==-1?0:h[par])+1;
    start[u]=sz(vec);
    vec.PB(u);
    for(int i=1;i<20;i++){
	sp[i][u]=-1;
	if(sp[i-1][u]!=-1) sp[i][u]=sp[i-1][sp[i-1][u]];
    }
    for(int y:v[u]){
	dfs(y,u);
	vec.PB(u);
    }
}
void prep(){
    for(int i=0;i<sz(vec);i++){
	sp[0][i]=vec[i];
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<sz(vec);j++){
	    sp[i][j]=sp[i-1][j];
	    if(j+(1<<(i-1))<sz(vec)){
		int A=sp[i][j],B=sp[i-1][j+(1<<(i-1))];
		if(h[A]<h[B]) sp[i][j]=A;
		else sp[i][j]=B;
	    }
	}
    }
}
int Lca(int a,int b){
    if(a==b) return a;
    a=start[a],b=start[b];
    if(a>b) swap(a,b);
    int id=31-__builtin_clz(b-a);
    int A=sp[id][a],B=sp[id][b-(1<<id)];
    if(h[A]<h[B]) return A;
    return B;
}  
pii Merge(pii a,pii b){
    if(a.F==-1 || b.F==-1) return {-1,-1};
    arr[0]=a.F,arr[1]=a.S,arr[2]=b.F,arr[3]=b.S;
    arr[4]=arr[0];
    for(int i=1;i<4;i++)
	arr[4]=Lca(arr[4],arr[i]);
    sort(arr,arr+5,[](int a,int b){return st[a]<st[b];});
    int id=-1;
    for(int i=0;i<4;i++){
	int u=Lca(arr[i],arr[i+1]);
	if(u!=arr[i]){
	    if(u!=arr[0] || id!=-1) return {-1,-1};
	    id=i;
	}
    }
    if(id==-1) return {arr[0],arr[4]};
    return {arr[id],arr[4]};
}
void build(int l=0,int r=n,int id=1){
    if(r-l==1){
	val[id]={pp[l],pp[l]};
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    val[id]=Merge(val[2*id],val[2*id+1]);
}
void Add(int a,int b,int l=0,int r=n,int id=1){
    bool A=l<=a && a<r,B=l<=b && b<r;
    if(!A && !B) return;
    if(r-l==1){
	val[id]={pp[l],pp[l]};
	return;
    }
    int mid=(l+r)>>1;
    Add(a,b,l,mid,2*id);
    Add(a,b,mid,r,2*id+1);
    val[id]=Merge(val[2*id],val[2*id+1]);
}
int Ask(int l=0,int r=n,int id=1){
    if(r-l==1) return l;
    int mid=(l+r)>>1;
    pii pi=Merge(Now,val[2*id]);
    if(pi.F==-1) return Ask(l,mid,2*id);
    Now=pi;
    return Ask(mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i];
	pp[p[i]]=i;
    }
    for(int i=1;i<n;i++){
	int x;cin>>x;
	v[--x].PB(i);
    }
    dfs();
    prep();
    build();
    int q;cin>>q;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int a,b;cin>>a>>b;
	    swap(p[--a],p[--b]);
	    pp[p[a]]=a,pp[p[b]]=b;
	    Add(p[a],p[b]);
	}
	else{
	    Now={pp[0],pp[0]};
	    cout<<(val[1].F==-1?Ask():n)<<"\n";
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
*/


// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
pii val[4*maxn];
int p[maxn],pp[maxn],n;
int arr[5];
pii Now;

int st[maxn],h[maxn],sp[20][2*maxn],CC;

vector<int>vec;
int start[maxn];

void dfs(int u=0,int par=-1){
    st[u]=CC++;
    h[u]=(par==-1?0:h[par])+1;
    start[u]=sz(vec);
    vec.PB(u);
    for(int y:v[u]){
	dfs(y,u);
	vec.PB(u);
    }
}
void prep(){
    for(int i=0;i<sz(vec);i++){
	sp[0][i]=vec[i];
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<sz(vec);j++){
	    sp[i][j]=sp[i-1][j];
	    if(j+(1<<(i-1))<sz(vec)){
		int A=sp[i][j],B=sp[i-1][j+(1<<(i-1))];
		if(h[A]<h[B]) sp[i][j]=A;
		else sp[i][j]=B;
	    }
	}
    }
}
int Lca(int a,int b){
    if(a==b) return a;
    a=start[a],b=start[b];
    if(a>b) swap(a,b);
    int id=31-__builtin_clz(b-a+1);
    int A=sp[id][a],B=sp[id][b+1-(1<<id)];
    if(h[A]<h[B]) return A;
    return B;
}  
    
pii Merge(pii a,pii b){
    if(a.F==-1 || b.F==-1) return {-1,-1};
    arr[0]=a.F,arr[1]=a.S,arr[2]=b.F,arr[3]=b.S;
    arr[4]=arr[0];
    for(int i=1;i<4;i++)
	arr[4]=Lca(arr[4],arr[i]);
    sort(arr,arr+5,[](int a,int b){return st[a]<st[b];});
    int id=-1;
    for(int i=0;i<4;i++){
	int u=Lca(arr[i],arr[i+1]);
	if(u!=arr[i]){
	    if(u!=arr[0] || id!=-1) return {-1,-1};
	    id=i;
	}
    }
    if(id==-1) return {arr[0],arr[4]};
    return {arr[id],arr[4]};
}
void build(int l=0,int r=n,int id=1){
    if(r-l==1){
	val[id]={pp[l],pp[l]};
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    val[id]=Merge(val[2*id],val[2*id+1]);
}
void Add(int a,int b,int l=0,int r=n,int id=1){
    bool A=l<=a && a<r,B=l<=b && b<r;
    if(!A && !B) return;
    if(r-l==1){
	val[id]={pp[l],pp[l]};
	return;
    }
    int mid=(l+r)>>1;
    Add(a,b,l,mid,2*id);
    Add(a,b,mid,r,2*id+1);
    val[id]=Merge(val[2*id],val[2*id+1]);
}
int Ask(int l=0,int r=n,int id=1){
    if(r-l==1) return l;
    int mid=(l+r)>>1;
    pii pi=Merge(Now,val[2*id]);
    if(pi.F==-1) return Ask(l,mid,2*id);
    Now=pi;
    return Ask(mid,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i];
	pp[p[i]]=i;
    }
    for(int i=1;i<n;i++){
	int x;cin>>x;
	v[--x].PB(i);
    }
    dfs();
    prep();
    build();
    int q;cin>>q;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int a,b;cin>>a>>b;
	    swap(p[--a],p[--b]);
	    pp[p[a]]=a,pp[p[b]]=b;
	    Add(p[a],p[b]);
	}
	else{
	    Now={pp[0],pp[0]};
	    cout<<(val[1].F==-1?Ask():n)<<"\n";
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.