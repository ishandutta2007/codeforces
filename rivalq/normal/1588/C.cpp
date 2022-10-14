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


const int N = 3e5 + 5;

struct node{
    int a=0;
    int id = 0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        if(a == n1.a)id = n1.id;
        else id = n2.id;
    }
};
struct update{
  int val=0;
  int id = 0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val=par.val;
  }
  void apply(node &node){
      node.a=val;
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
          t[v].a = 1e18;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a=val.val;
            t[v].id = val.id;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return node(1e18);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }

  int find(int v,int l,int r,int val){
  	if(tr[v] < l || tl[v] > r)return -1;
  	if(l<=tl[v] && tr[v]<=r){
        	if(t[v].a < val){
        		while(tl[v] != tr[v]){
        			if(t[2*v].a < val)v = 2*v;
        			else v = 2*v + 1;
        		}
        		return tl[v];
        	} else{
        		return -1;
        	}
      	}
      	auto res = find(2*v,l,r,val);
      	if(res != -1)return res;
      	return find(2*v + 1,l,r,val);

  }

public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};

segtree<node,update>seg1;
segtree<node,update>seg2;

int solve(){
 		int n; cin >> n;
 		seg1.build(1,1,n);
 		seg2.build(1,1,n);
 		vector<int> a(n + 1);
 		vector<vector<int>> pre(2,vector<int>(n + 2));
 		map<int,vector<int>> mp;
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			pre[0][i] = pre[0][i - 1];
 			pre[1][i] = pre[1][i - 1];
 			pre[i % 2][i] += a[i];
 			update upd; upd.val = pre[i % 2][i] - pre[1 - (i % 2)][i];
 			upd.id = (i % 2);
 			mp[pre[0][i] - pre[1][i]].push_back(i);
 			if(i % 2)seg1.upd(i,i,upd);
 			else seg2.upd(i,i,upd);
 		}

 		auto query = [&](int val,int l,int r){
 			return upper_bound(all(mp[val]),r) - lower_bound(all(mp[val]),l);
 		};
 		int ans = 0;

 		for(int i = 0; i < n; i++){
 			int L = i + 1;
 			int R = n;
 			int j = n;
 			int res = seg1.find(1,i + 1,n,pre[1][i] - pre[0][i]);
 			if(res != -1)mins(j,res - 1);
 			res = seg2.find(1,i + 1,n,pre[0][i] - pre[1][i]);
 			if(res != -1)mins(j,res - 1);
 			//cout << j << endl;
 			if(j != i){
 				ans += query(pre[0][i] - pre[1][i],i + 1,j);
 			}
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