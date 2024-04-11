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
const int maxn=100005;
vector<int>g[maxn];
int eu[maxn],tin[maxn],tout[maxn],level[maxn];
vector<int>vec[maxn];
int p[maxn];
int b_p[maxn][21];
int t=0;
int res[maxn];
void dfs(int n,int e,int l){
     p[n]=e;
     level[n]=l;
     tin[n]=++t;
     eu[t]=n;
     vec[l].pb(t);
     for(auto i:g[n]){
         if(i!=e){
             dfs(i,n,l+1);
         }
     }
     tout[n]=t;
     return;
}
void lift(int n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int get(int u,int k){
   if(level[u]<k)return -1;
   for(int i=20;i>=0;i--){
   	   if(k>=(1<<i)){
   	   	  u=b_p[u][i];
   	   	  k-=(1<<i);
   	   }
   }
   return u;
}
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
Vertex* pre[maxn];
int temp[maxn];
int solve(){
 int n;cin>>n;
 vector<int>r;
 rep(i,1,n+1){
 	int p;cin>>p;
 	if(p==0)r.pb(i);
 	else{
 		g[p].pb(i);
 		g[i].pb(p);
 	} 
 }
 for(auto i:r)dfs(i,i,0);
 lift(n);
 for(auto i:vec[0])temp[i]=1;
 pre[0]=build(temp,1,n);
 for(int i=1;i<n;i++){
 	Vertex* temp=pre[i-1];
 	for(auto j:vec[i-1])temp=update(temp,1,n,j,0);
 	for(auto j:vec[i])temp=update(temp,1,n,j,1);	
 	pre[i]=temp;
 }	
 int m;cin>>m;
 rep3(m){
 	int v,k;cin>>v>>k;
 	int p=get(v,k);
 	if(p==-1){
 		cout<<0<<" ";continue;
 	}
 	Vertex* temp=pre[level[v]];
 	cout<<get_sum(temp,1,n,tin[p],tout[p])-1<<" ";
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