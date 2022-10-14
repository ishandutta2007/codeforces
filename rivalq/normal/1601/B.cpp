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
    int b=0;
    node (int val=0){
        a = 1e9;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        if(this->a == n1.a)this->b = n1.b;
        else this->b = n2.b;
    }
};
struct update{
  int val = 0;

  update(int t=1e9){
     val = t;
  }
  void combine(update &par,int tl,int tr){
      mins(val,par.val);
  }
  void apply(node &node){
      mins(node.a,val);
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
          t[v].a = 1e9;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val,int idx){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            if(t[v].a > val){
            	t[v].a = val;
            	t[v].b = idx;
            }
            return;
      }
      zeno(2*v,l,r,val,idx);
      zeno(2*v+1,l,r,val,idx);
      //t[v].merge(t[2*v],t[2*v+1]);
  }
  void query(int v,int i,pii &ans){
      mins(ans,make_pair(t[v].a,t[v].b));	
      if(tl[v] == tr[v]){
      }else{
      	 int mid = (tl[v] + tr[v])/2;
      	 if(i <= mid){
      	 	query(2*v,i,ans);
      	 }else{
      	 	query(2*v + 1,i,ans);
      	 }
      }
  }
public:
  pii query(int l){
      pii ans = {1e9,1e9};
      query(1,l,ans);
      return ans;
  }
  void upd(int l,int r,int val,int idx){
      return zeno(1,l,r,val,idx);
  }   
};

segtree<node,update>seg;

int solve(){
		int n; cin >> n;
		vector<int> a(n + 1),b(n + 1);
		vector<vector<int>> g(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		} 

		g[0].push_back(0);
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}

		vector<int> dp(n + 1,1e9);
		dp[n] = 0;
		vector<int> par(n + 1);
		seg.build(1,0,n);

		seg.upd(n - a[n],n,0,n);		


			
		

		for(int i = n - 1; i >= 0; i--){
			auto s = seg.query(i);
			mins(dp[i],1 + s.x);
			par[i] = s.y;			
			int j = i + b[i];
			seg.upd(j - a[j],j,dp[i],i);
		}


		if(dp[0] == 1e9)dp[0] = -1;
		cout << dp[0] << endl;

		if(dp[0] != -1){
			vector<int> ans;
			int u = 0;
			while(u != n){
				ans.push_back(u);
				int next = par[u];
				u = next;
			}
			reverse(ans.begin(),ans.end());
			for(auto i:ans)cout << i << " ";
			cout << endl;
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