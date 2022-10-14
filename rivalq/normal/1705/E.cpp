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

const int N = 4e5 + 5;

struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a = n1.a + n2.a;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val=par.val;
  }
  void apply(node &node,int tl,int tr){
      node.a=val*(tr - tl + 1);
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
       zaker[v].apply(t[v],tl[v],tr[v]);
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
            t[v].a=val.val*(tr[v] - tl[v] + 1);
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
  int find_nearest_one(int v,int l,int r){
  	if(tr[v] < l || tl[v] > r)return -1;
  	pushdown(v);
  	if(l <= tl[v] && tr[v] <= r){
  		if(t[v].a == 0)return -1;
  		while(tl[v] != tr[v]){
  			pushdown(2*v);
  			pushdown(2*v + 1);
  			if(t[2*v].a)v = 2*v;
  			else v = 2*v + 1;
  		}
  		return tl[v];
  	}
  	int a = find_nearest_one(2*v,l,r);
  	if(a != -1)return a;
  	return find_nearest_one(2*v + 1,l,r);
  }
  int find_nearest_zero(int v,int l,int r){
  	if(tr[v] < l || tl[v] > r)return -1;
  	pushdown(v);
  	if(l <= tl[v] && tr[v] <= r){
  		if(t[v].a == tr[v] - tl[v] + 1)return -1;
  		while(tl[v] != tr[v]){
  			pushdown(2*v);
  			pushdown(2*v + 1);
  			if(t[2*v].a != tr[2*v] - tl[2*v] + 1)v = 2*v;
  			else v = 2*v + 1;
  		}
  		return tl[v];
  	}
  	int a = find_nearest_zero(2*v,l,r);
  	if(a != -1)return a;
  	return find_nearest_zero(2*v + 1,l,r);
  }
  int answer(int v = 1){
  	while(tl[v] != tr[v]){
  		pushdown(2*v);
  		pushdown(2*v + 1);
  		if(t[2*v + 1].a){
  			v = 2*v + 1;
  		}else{
  			v = 2*v;
  		}
  	}
  	return tl[v];
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
const int M = 4e5;
int solve(){
 		int n,q; cin >> n >> q;
 		seg.build(1,1,M);

 		auto add = [&](int x){
 			auto j = seg.find_nearest_zero(1,x,M);
 			if(j > x)seg.upd(x,j - 1,0);
 			seg.upd(j,j,1);
 		};
 		auto erase = [&](int x){
 			auto j = seg.find_nearest_one(1,x,M);
 			if(j > x)seg.upd(x,j - 1,1);
 			seg.upd(j,j,0);
 		};
 		vector<int> a(n);
 		for(auto &i:a)cin >> i,add(i);

 		while(q--){
 			int k,l; cin >> k >> l;
 			k--;
 			erase(a[k]);
 			a[k] = l;
 			add(a[k]);
 			cout << seg.answer() << endl;
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