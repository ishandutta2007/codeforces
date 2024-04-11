#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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

const int N=2e5+5;

struct node{
    int a=0;
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
    }
}zero;
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a=val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return -1e9;
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a;
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return max(a,b);
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};
segtree<node> seg[32];

int solve(){
 	int n,k;cin>>n>>k;
 	int m=(1<<k);
 	for(int i=0;i<m;i++){
 		seg[i].build(1,1,n);
 	}
 	auto update=[&](int x,vector<int>vec){
 		rep(i,0,m){
 			int s=0;
 			rep(j,0,k){
 				if((1<<j)&i){
 					s=s+vec[j];
 				}
 				else{
 					s=s-vec[j];
 				}
 			}
 			seg[i].upd(x,x,s);
 		}
 	};
 	auto query=[&](int l,int r){
 		int mx=0;
 		rep(i,0,m){
 			int j=(m-1)^i;
 			if(j<i)continue;
 			maxs(mx,seg[i].query(l,r)+seg[j].query(l,r));
 		}
 		return mx;
 	};
 	rep(i,1,n+1){
 		vector<int>vec(k);
 		rep(j,0,k)cin>>vec[j];
 		update(i,vec);
 	}
 	
 	int q;cin>>q;
 	rep(i,0,q){
 		int t;cin>>t;
 		if(t==1){
 			int x;cin>>x;
 			vector<int>vec(k);
 			rep(j,0,k)cin>>vec[j];
 			update(x,vec);
 		}
 		else{
 			int l,r;cin>>l>>r;
 			cout<<query(l,r)<<endl;
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