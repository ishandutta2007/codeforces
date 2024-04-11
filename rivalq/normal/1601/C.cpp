// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

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


const int N = 1e6 + 4;

struct node{
    int a=0;
    node (int val=0){
        a=1e18;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
  }
  void apply(node &node){
      node.a+=val;
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
      lazy[v] = 0;
      zaker[v].val = 0;
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
            t[v].a += val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return nul;
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
 		int n,m; cin >> n >> m;
 		vector<int>a(n),b(m);
 		map<int,int> mp;
 		for(auto &i:a){
 			cin >> i;
 			mp[i]++;
 		}
 		for(auto &i:b){
 			cin >> i;
 		}
 		auto calc = [&](vector<int> t){
 			Fenwick<int> fn(n + 1);
 			auto a = t;
 			sort(all(a));
 			int ans = 0;
 			a.erase(unique(all(a)),a.end());	

 			for(int i = 0; i < t.size(); i++){
 				int k = lower_bound(all(a),t[i]) - a.begin() + 1;
 				ans += i - fn.query(k);
 				fn.update(k,n,1);
 			}


 			return ans;
 		};
 		seg.build(1,1,n + 1);

 		int ans = calc(a);
 		vector<pii> t1;
 		for(int i = 0; i < n; i++){
 			t1.push_back({a[i],i + 1});
 		}
 		sort(all(t1));
 		sort(all(b));


		for(int i = 1; i <= n; i++){
			seg.upd(i + 1,n + 1,1);
		}

		//for(int j = 1; j <= n + 1; j++)cout << seg.query(j,j).a << " ";
		//cout << endl;

 		int j = 0;		

 		int prev_value = -1;
 		vector<int> temp;

		for(int i = 0; i < m; i++){

			if(temp.size() and prev_value != b[i]){
				for(auto j:temp){
					seg.upd(1,j,1);
				}
				temp.clear();	
			}

			while(j < n and t1[j].x < b[i]){
				int k = t1[j].y;
				seg.upd(k + 1,n + 1,-1);
				seg.upd(1,k,1);
				j++;
			}
			while(j < n and t1[j].x == b[i]){
				int k = t1[j].y;
				seg.upd(k + 1,n + 1,-1);
				temp.push_back(t1[j].y);
				j++;
			}
			

			prev_value = b[i];
			auto s = seg.query(1,n + 1);
			//cout << "@" << " " << s.a << " " << j << endl;
			ans += s.a;
		}
		cout << ans << endl;


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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}