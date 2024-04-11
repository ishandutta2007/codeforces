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

const int N = 2e5 + 5;

struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        a = n1.a + n2.a;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      maxs(val,par.val);
  }
  void apply(node &node){
      maxs(node.a,val);
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
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            maxs(t[v].a,val.val);
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
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
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};
segtree<node,update>seg;



template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
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


int solve(){
 		int n,k; cin >> n >> k;
 		string s; cin >> s;
 		vector<pii> g(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> g[i];
 		}
 		string t = "0";
 		vector<int>pos(n + 1),par(n + 1),tour(n + 1),in(n + 1),out(n + 1),d(n + 1);
 		vector<int> left_p(n + 1);
 		int cur = 0,temp = 0;
 		function<void(int,int)> dfs = [&](int u,int p){
 			par[u] = p;
 			d[u] = d[p] + 1;
 			in[u] = ++temp;
 			if(g[u].x){
 				dfs(g[u].x,u);
 			}
 			pos[u] = ++cur;
 			tour[cur] = u;
 			t.push_back({s[u - 1]});
 			if(g[u].y){
 				dfs(g[u].y,u);
 			}
 			out[u] = temp;
 		};
 		dfs(1,0);
 		string res;
 		vector<pii>block;
 		map<int,int>id;
 		set<pii> st;
 		int i = 1;
 		seg.build(1,1,n);
 		while(i < t.length()){
 			int j = i;
 			int k = block.size();
 			while(j < t.length() and t[i] == t[j]){
 				id[j] = k;
 				j++;
 			}
 			block.push_back({j - i,t[i]});
 			i = j;
 		}
 		Fenwick<int> fn(n + 1);
 		auto find = [&](int x){
 			return fn.query(x) > 0;
 		};	

 		

 		for(int i = 1; i < t.size(); i++){
 			int u = tour[i];
 			auto s = seg.query(in[u],in[u]).a;
 			res.push_back(t[i]);
 			if(s == d[u]){
 				res.push_back({t[i]});
 				continue;
 			}
 			if(find(in[u])){
 				continue;
 			}

 			if(d[u] - s > k){
 				continue;
 			}
 			int blk_id = id[i];
 			if(blk_id == sz(block) - 1){
 				continue;
 			}
 			char c2 = block[blk_id + 1].y;
 			if(c2 > t[i]){
 				while(u > 0){
 					auto s = seg.query(in[u],in[u]).a;
 					if(s == d[u])break;
 					seg.upd(in[u],out[u],d[u]);
 					u = par[u];
 					k--;
 				}
 				res.push_back(t[i]);
 			}else{
 				fn.update(in[u],n,1);
 				fn.update(out[u] + 1,n,-1);
 			}
 		}
 		cout << res << endl;


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