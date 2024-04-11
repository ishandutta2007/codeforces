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
const int inf = 1e9;

struct node{
    int a[5][5];
    node (int val=0){
    }
    void merge(node &n1,node &n2){
       for(int i = 0; i < 5; i++){
       	for(int j = 0; j < 5; j++){
       		a[i][j] = inf;
       	}
       }
       for(int i = 0; i < 5; i++){
       	for(int j = 0; j < 5; j++){
       		for(int k = 0; k < 5; k++){
       			mins(a[i][j],n1.a[i][k] + n2.a[k][j]);
       		}
       	}
       }
    }
};

void process(int a[][5],char c){
	for(int i = 0; i < 5; i++){
	       	for(int j = 0; j < 5; j++){
	       		a[i][j] = inf;
	       	}
       	}
       	for(int i = 0; i < 5; i++)a[i][i] = 0;
       	if(c == '2')a[0][0] = 1,a[0][1] = 0;
        if(c == '0')a[1][1] = 1,a[1][2] = 0;
        if(c == '1')a[2][2] = 1,a[2][3] = 0;
        if(c == '6')a[3][3] = 1,a[4][4] = 1;
        if(c == '7')a[3][3] = 0,a[3][4] = 0;


}

template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;


  void build(int v,int start,int end,string &arr){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          process(t[v].a, arr[start - 1]);
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
      int mid = (tl[v] + tr[v])/2;
      if(r <= mid)return query(2*v,l,r);
      else if(l > mid) return query(2*v + 1,l,r);
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

int solve(){
 		int n,q; cin >> n >> q;
 		string s; cin >> s;
 		seg.build(1,1,n,s);
 		rep(i,0,q){
 			int l,r; cin >> l >> r;
 			auto s = seg.query(l,r).a[0][4];
 			if(s == inf)s = -1;
 			cout << s << endl;
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