// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 1e6 + 5;

int col[N];

struct node{
    int a=0;
    int mx = 0;
    int mn = 0;
    node (int val=0){
        a=val;
        mx = -1;
        mn = N + 1;
    }
    void merge(node &n1,node &n2){
        this->a= n1.a + n2.a;
        this->mx = max(n1.mx,n2.mx);
        this->mn = min(n1.mn,n2.mn);
    }
};
struct update{
  int val=0;
  int col=0;
  update(int t=0){
     val=t;
     col=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
      col=par.col;
  }
  void apply(node &node){
      node.a+=val;
      node.mx = node.mn = col;
      val=0;
  }
};
template<typename node,typename update>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  update zaker[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  inline void pushdown(int v){
     if(lazy[v]){    
       apply(zaker[v],v);
       lazy[v]=0;
       zaker[v].apply(t[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a = 0;
          t[v].mn = t[v].mx = 1;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int new_col){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r && t[v].mx == t[v].mn){
      	    // same color
      	    update upd;
      	    int old_col = t[v].mx;
      	    upd.val = col[old_col] - col[new_col];
      	    upd.col = new_col;
            t[v].a += upd.val;
            t[v].mx = t[v].mn = new_col;
            apply(upd,v); 
            return;
      }
      zeno(2*v,l,r,new_col);
      zeno(2*v+1,l,r,new_col);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return node();
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};


segtree<node,update>seg;

int solve(){
		int n,q; cin >> n >> q;
		seg.build(1,1,n);
		rep(i,0,q){
			string t; cin >> t;
			if(t == "Color"){
				int l,r,c; cin >> l >> r >> c;
				seg.upd(l,r,c);
			}else if(t == "Add"){
				int c,x; cin >> c >> x;
				col[c] += x;
			}else{
				int j; cin >> j;
				auto s = seg.query(j,j);
				int ans = s.a + col[s.mx];
				cout << ans << endl;
			}
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