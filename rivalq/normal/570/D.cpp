#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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
const int maxn=500005;
template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n=maxn){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};
Fenwick<int> fn[26];
int tin[maxn],tout[maxn],eu[maxn],lvl[maxn];
vector<int>g[maxn];
int t=0;
char a[maxn];
vector<pair<int,char>>v[maxn];
void dfs(int u=1,int p=0,int l=1){
    tin[u]=++t;
    eu[t]=u;
    lvl[u]=l;
    v[l].pb({tin[u],a[u]});
    for(auto i:g[u]){
    	if(i!=p){
    		dfs(i,u,l+1);
    	}
    }
    tout[u]=t;
}
int query(int l,int r){
	int cnt=0;
	for(int i=0;i<26;i++){
		int c=fn[i].query(r)-fn[i].query(l-1);
		if(c&1)cnt++;
		if(cnt>1)return 0;
	}
	return 1;
}
int solve(){
 int n,m;cin>>n>>m;
 rep3(n-1){
 	int p;cin>>p;
 	g[i+2].pb(p);
 	g[p].pb(i+2);
 }
 rep3(n)cin>>a[i+1];

 dfs();

 for(auto i:v[1]){
 	char c=i.y;
 	int idx=i.x;
 	fn[c-97].update(idx,n,1);
 }
 vector<pair<pii,int>>q(m);
 rep3(m){
 	cin>>q[i].x;
 	swap(q[i].x.x,q[i].x.y);
 	q[i].y=i;
 }
 sort(all(q));
 bool ans[m];
 int l=0;
 for(int i=1;i<=n;i++){
   while(l<m && q[l].x.x==i){
       ans[q[l].y]=query(tin[q[l].x.y],tout[q[l].x.y]);
       l++;
   }
   for(auto j:v[i]){
   	  fn[j.y-97].update(j.x,n,-1);
   }
   for(auto j:v[i+1]){
   	  fn[j.y-97].update(j.x,n,1);
   }
 }
 for(int i=0;i<m;i++){
 	if(ans[i])cout<<"Yes"<<endl;
 	else cout<<"No"<<endl;
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