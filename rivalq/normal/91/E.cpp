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
// for max
const int N=100005;
bool Q;
struct Line {
	mutable int k, m, p,idx;
	 bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const int inf = LLONG_MAX;
	int div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m,int idx) {
		auto z = insert({k, m, 0,idx}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	pii query(int x) {
		assert(!empty());Q=1;
		auto l = *lower_bound({0,0,x});Q=0;
		return {l.k * x + l.m,l.idx};
	}
};
struct node{
    int a=0;
    LineContainer cht;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
    }
};
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  void build(int v,int start,int end,pii arr[]){
      tl[v]=start;
      tr[v]=end;
      for(int i=tl[v];i<=tr[v];i++){
      	 t[v].cht.add(arr[i].y,arr[i].x,i);
      }
      if(start==end){
          return;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
     }
  }
  pii query(int v,int l,int r,int x){
      if(tr[v]<l || tl[v]>r)return {-1,-1};
      if(l<=tl[v] && tr[v]<=r){
         return t[v].cht.query(x);
      }
      pii a=query(2*v,l,r,x);
      pii b=query(2*v+1,l,r,x);
      return max(a,b);
  }
public:
  pii query(int l,int r,int x){
      return query(1,l,r,x);
  }
};
segtree<node>seg;
int solve(){
 int n,q;cin>>n>>q;
 pii a[n+1];
 rep(i,1,n+1)cin>>a[i];
 seg.build(1,1,n,a);
 rep3(q){
 	int l,r,t;cin>>l>>r>>t;
 	cout<<seg.query(l,r,t).y<<endl;
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