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

const int N = 2e5+5;

struct node{
    int a=0; // to store minimum
    int cnt = 0; // count of minimum
    int ans = 0; // final answer
    int ti = 0;
    int lazy = 0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        	this->a=min(n1.a,n2.a);
        	cnt = 0;
        	if(this->a == n1.a){
        		cnt = n1.cnt;
        	}
        	if(this->a == n2.a){
        		cnt += n2.cnt;
        	}
    }

};

template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  

  void push(int v){
  		if(t[v].lazy){
  			if(tl[v]!=tr[v]){
  				t[2*v].lazy += t[v].lazy;
  				t[2*v+1].lazy += t[v].lazy;
  			}
  			t[v].a += t[v].lazy;
  			t[v].lazy = 0;
  		}
  		if(t[v].ti){
  			if(tl[v]!=tr[v]){
  				int val_l = t[2*v].a + t[2*v].lazy;
  				int val_r = t[2*v+1].a + t[2*v+1].lazy;
  				if(val_l <= val_r){
  					t[2*v].ti += t[v].ti;
  				}
  				if(val_r <= val_l){
  					t[2*v+1].ti += t[v].ti;
  				}
  			}
  			t[v].ans += t[v].cnt*t[v].ti;
  			t[v].ti = 0;
  		}
  }

  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a = 1;
          t[v].cnt = 1;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val){
      push(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].lazy = val;
            push(v);
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return 0;
      push(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v].ans;
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return a+b;
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};


segtree<node>seg;


int solve(){
 		int n;cin>>n;
 		vector<int>a(n+1);
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		int q; cin >> q;
 		vector<vector<pii>>queries(n+1);
 		vector<int>ans(q);
 		rep(i,0,q){
 			int l,r; cin >> l >> r;
 			queries[r].push_back({l,i});
 		}
 		seg.build(1,1,n);
 		vector<int>mx={0};
 		vector<int>mn={0};
 		for(int i = 1; i <= n; i++){
 			while(mx.back() and a[i] > a[mx.back()]){
 				int j = mx.back(); mx.pop_back();
 				int delta = a[i] - a[j];
 				seg.upd(mx.back()+1,j,delta);
 			}
 			mx.push_back(i);
 			while(mn.back() and a[i] < a[mn.back()]){
 				int j = mn.back(); mn.pop_back();
 				int delta = a[j] - a[i];
 				seg.upd(mn.back()+1,j,delta);
 			}
 			mn.push_back(i);
 			seg.upd(1,i,-1);
 			seg.t[1].ti++;
 			for(auto j:queries[i]){
 				ans[j.y] = seg.query(j.x,i);
 			}	
 		}
 		for(auto i:ans){
 			cout << i << endl;
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