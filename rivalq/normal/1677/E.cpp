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
    int32_t a = 0;
    int val = 0;
    int32_t last = 0;
    node (int val=0){
    }
    void merge(node &n1,node &n2){
    	this->a = n1.a + n2.a;
        this->val = n1.val + n2.val;
    }
};

struct update{
  int val = 0;
  int32_t frst = 0;
  int32_t last = 0;
  int32_t a = -1;	
  update(int t=0){
  }
  void combine(update &par,int tl,int tr){
      
      //if(tl == tr and tl == 1){
      	// cout << "Combining " << par.val << " " << par.a << " " << par.last << " " << par.frst << endl;
      	// cout << val << " " << last << " " << frst << " " << a << endl;
      //}
      if(a == -1){
      	 val = par.val;
      	 frst = par.frst;
      	 a = par.a;
      	 last = par.last;
      }else{
      	 val += par.val;
	 val += (par.frst - last)*a;
	 last = par.last;
	 a = (par.a != -1)?par.a : a;
      }
     
  }
  void apply(node &node,int tl, int tr){
      int len = tr - tl + 1;	
      node.val += len*val + node.a*(frst - node.last);
      node.last = last;
      node.a = (a == -1) ? node.a : a * len;
      frst = last;
      val = 0;
      a = -1;
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
          //t[v].a = 0;
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
            zaker[v].combine(val,tl[v],tr[v]);
            zaker[v].apply(t[v],tl[v],tr[v]);
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }


  int query2(int v,int l,int r,int x){
      if(tr[v]<l || tl[v]>r){
      	  return 0;
      }
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
          return t[v].val;
      }
      int a=query2(2*v,l,r,x);
      int b=query2(2*v+1,l,r,x);
      return a + b;
  }

  node query(int v,int l,int r,int x){
      if(tr[v]<l || tl[v]>r){
      	 node tt = node();
      	 return tt;
      }
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
      	return t[v];
         //return t[v].val - t[v].sum_last_a + t[v].a*x;
      }
      node a=query(2*v,l,r,x);
      node b=query(2*v+1,l,r,x);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r,int x){
      return query(1,l,r,x);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};

segtree<node,update>seg;

int solve(){
 		int n,q; cin >> n >> q;
 		vector<int32_t> p(n + 1),inv(n + 1);
 		vector<vector<array<int32_t,2>>> in(n + 1);
 		vector<vector<array<int32_t,2>>> out(n + 2); //l1 l2 r1 r2
 		for(int i = 1; i <= n; i++){
 			cin >> p[i];
 			inv[p[i]] = i;
 		}
 		vector<int32_t> ng(n + 1,n),pg(n + 1,1);
 		vector<int32_t> st;
 		seg.build(1,1,n);
 		for(int i = 1; i <= n; i++){
 			while(!st.empty() and p[i] > p[st.back()]){
 				ng[st.back()] = i - 1;
 				st.pop_back();
 			}
 			st.push_back(i);
 		}
 		st.clear();
 		for(int i = n; i >= 1; i--){
 			while(!st.empty() and p[i] > p[st.back()]){
 				pg[st.back()] = i + 1;
 				st.pop_back();
 			}
 			st.push_back(i);
 		}


 		for(int i = 1; i <= n; i++){ 			
 			for(int j = i; j <= n; j += i){
 				int32_t num2 = j/i;
 				if(num2 >= i)break;
 				int32_t max_left = min({inv[i],inv[j],inv[num2]});
 				int32_t min_right = max({inv[i],inv[j],inv[num2]});
 				if(inv[i] == inv[num2])continue;
 				int32_t min_left = pg[inv[j]];
 				int32_t max_right = ng[inv[j]];
 				if(min_left <= max_left and min_right <= max_right){
 					in[min_right].push_back({min_left,max_left});
 					out[max_right + 1].push_back({min_left,max_left});
 				}
 			}
 		}
 		vector<int> ans(q);
 		vector<vector<pii>> add(n + 1);
 		for(int i = 0; i < q; i++){
 			int l,r; cin >> l >> r;
 			add[r].push_back({l,i});
 		}

 		vector<int> sum(n + 1),set(n + 1);

 		auto advance = [&](int t){
 			update upd;
 			upd.frst = upd.last = t;
 			upd.a = -1;
 			upd.val = 0;
 			seg.upd(1,n,upd);
 			//for(int i = 1; i <= n; i++)sum[i] += set[i];
 		};

 		auto update_ = [&](int l,int r,int val,int t){
 			update upd;
 			upd.val = 0;
 			upd.frst = upd.last = t;
 			upd.a = val; 			
 			seg.upd(l,r,upd);
 			
 			//for(int i = l; i <= r; i++)set[i] = val;
 		};
 		auto query = [&](int l,int r,int t){
 			return seg.query2(1,l,r,t);
 			//return accumulate(sum.begin() + l,sum.begin() + r + 1,0);
 		};

 		for(int i = 1; i <= n; i++){

 			for(auto [l,r]:out[i]){
 				//cout << "Out " <<l << " " << r << " " << i << endl;
 				update_(l,r,0,i - 1);
 			}
 			for(auto [l,r]:in[i]){
 				//cout << "Add " <<l << " " << r << " " << i << endl;
 				update_(l,r,1,i - 1);
 			}
 			advance(i);
 			for(auto [l,j]:add[i]){
 				ans[j] = query(l,i,i);
 			}
 			//for(int j = 1; j <= n; j++){
 			//	cout << seg.query2(1,j,j,i) << " ";
 			//}
 			//cout << endl;
 			//for(int i = 1; i <= n; i++)cout << sum[i] << " ";cout << endl; 

 		}
 		for(auto i:ans)cout << i << endl;




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