#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
// build is same as dynamic seg tree;
struct node{
	int a=0;
    node *l,*r;
    node(int val):l(nullptr),r(nullptr),a(val){}
    node(node *l,node *r):l(l),r(r),a(0){
    	this->a=min(l->a,r->a);
    }
};
template<typename node>
struct segtree{

public:  

  node* build(int tl,int tr,int a[]){
  	if(tl==tr){
  		return new node(a[tl]);
  	}
  	int mid=(tl+tr)/2;
    return new node(build(tl,mid,a),build(mid+1,tr,a));
  }
  node* update(node* t,int tl,int tr,int idx,int val){
    if(tl==tr){
    	return new node(val);
    } 
    int mid=(tl+tr)/2;
    if(idx<=mid)return new node(update(t->l,tl,mid,idx,val),t->r);
    return new node(t->l,update(t->r,mid+1,tr,idx,val));
  }
  int query(node* t,int tl,int tr,int l,int r){
  	 if(tl>r || l>tr)return hell;
  	 if(tl>=l && r>=tr)return t->a;
  	 int mid=(tl+tr)/2;
  	 return min(query(t->l,tl,mid,l,r),query(t->r,mid+1,tr,l,r));
  } 
};
const int maxn=100005;
segtree<node> seg;
node *update[maxn];
int eu[maxn],tin[maxn],tout[maxn];
vector<int>g[maxn];
int lvl[maxn];
int a[maxn];
int cur=0;
map<int,vector<pii>>mp;
int temp[maxn];
void dfs(int u,int p){
	tin[u]=++cur;
	eu[cur]=u;
	mp[lvl[u]].pb({cur,a[u]});
	for(auto i:g[u]){
		if(i!=p){
			lvl[i]=1+lvl[u];
			dfs(i,u);
		}
	}
	tout[u]=cur;
}
int solve(){
 int n,r;cin>>n>>r;
 for(int i=1;i<=n;i++)cin>>a[i],temp[i]=1e9;
 rep3(n-1){
 	int a,b;cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
 }	
 dfs(r,0);
 temp[1]=a[r];
 update[0]=seg.build(1,n,temp);
 for(int i=1;i<n;i++){
 	node *temp=update[i-1];
 	for(auto j:mp[i]){
 		temp=seg.update(temp,1,n,j.x,j.y);
 	}
 	update[i]=temp;
 }
 int m;cin>>m;
 int last=0;
 rep3(m){
 	int x,y;cin>>x>>y;
 	x=(x+last)%n+1;
 	y=(y+last)%n;
 	y=min(y+lvl[x],n-1);
 	last=seg.query(update[y],1,n,tin[x],tout[x]);
 	cout<<last<<endl;
 }
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}