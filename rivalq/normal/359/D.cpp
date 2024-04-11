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
const int N=3e5+5;
struct node{
    int a=0;
    int g=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        this->g=gcd(n1.g,n2.g);
    }
}nul;
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
	  void build(int v,int start,int end,int arr[]){
	      tl[v]=start;
	      tr[v]=end;
	      if(start==end){
	          t[v].a=arr[start];
	          t[v].g=t[v].a;
	      }
	      else{
	          int m=(start+end)/2;
	          build(2*v,start,m,arr);
	          build(2*v+1,m+1,end,arr);
	          t[v].merge(t[2*v],t[2*v+1]);
	      }
	  }
	  node query(int v,int l,int r){
	      if(tr[v]<l || tl[v]>r)return nul;
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
};
segtree<node>seg;
int a[N];
int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1)cin>>a[i];
 	seg.build(1,1,n,a);
 	vector<int>temp;
 	auto f=[&](int l){
              temp.clear();
              for(int i=1;i+l-1<=n;i++){
              	   auto s=seg.query(i,i+l-1);
              	   if(s.g>=s.a){
              	   	temp.pb(i);
              	   }
              }  
              return sz(temp)>0;
 	};
 	int lo=0;
 	int hi=n-1;
 	int ans=0;
 	while(lo<=hi){
 		int m=(lo+hi)/2;
 		if(f(m+1)){
                    	ans=m;
                    	lo=m+1;
 		}
 		else{
 			hi=m-1;
 		}
 	}
 	f(ans+1);
 	cout<<sz(temp)<<" "<<ans<<endl;
 	for(auto i:temp)cout<<i<<" ";cout<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    nul.a=hell;
    nul.g=0;
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