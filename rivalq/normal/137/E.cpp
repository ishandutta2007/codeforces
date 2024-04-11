#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
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

const int N=200005;

struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
};
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
	  int query(int v,int l,int r,int val){
	      if(tr[v]<l || tl[v]>r)return -1;
	      if(l<=tl[v] && tr[v]<=r){
	            if(t[v].a>val)return -1;
	            while(tl[v]!=tr[v]){
	            	 if(t[2*v].a<=val)v=2*v;
	            	 else v=2*v+1;
	            }
	            return tl[v];
	      }
	      int a=query(2*v,l,r,val);
	      if(a!=-1)return a;
	      int b=query(2*v+1,l,r,val);
	      
	  }
	public:
	  int query(int l,int r,int val){
	      return query(1,l,r,val);
	  }
	  void upd(int l,int r,int val){
	      return zeno(1,l,r,val);
	  }   
};
segtree<node>seg;
int solve(){
     string s;cin>>s;
     int v=0;
     int n=s.length();
     for(int i=0;i<s.length();i++){
     	  s[i]=tolower(s[i]);
     	  if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')v++;
     }
     if(v==s.length()){
     	  cout<<"No solution\n";return 0;
     }
     vector<int>l(n+1,0);
     vector<int>p(n+1,0);
     for(int i=0;i<n;i++){
     	  p[i+1]+=p[i];
          if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')p[i+1]--;
     	  else p[i+1]+=2;
     } 
     seg.build(1,0,n);
     rep(i,1,n+1){
     	   seg.upd(i,i,p[i]);
     }
     int ma=0;
     for(int i=1;i<=n;i++){
     	   int j=seg.query(0,i-1,p[i]);
     	   if(j!=-1){
     	   	maxs(ma,i-j);
     	   	l[i-j]++;
     	   }
     }
     cout<<ma<<" "<<l[ma]<<endl;
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