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

const int N=500005;

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
  node nul;
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=hell;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void update(int v,int idx,int val){
  	if(idx>tr[v] || idx<tl[v])return;
  	if(tl[v]==tr[v]){
  		t[v].a=val;return;
  	}
  	update(2*v,idx,val);
  	update(2*v+1,idx,val);
  	t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return hell;
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a;
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return min(a,b);
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
};
segtree<node>seg;
int solve(){
  	int n,m;cin>>n>>m;
        vector<int>a(n+1);
        vector<int>p(n+1);
        map<int,vector<int>>mp;
        rep(i,1,n+1){
        	cin>>a[i];
        	mp[a[i]].push_back(i);
        } 
        for(auto i:mp){
        	for(int j=0;j<sz(i.y);j++){
        		if(j==0)p[i.y[0]]=-1;
        		else p[i.y[j]]=i.y[j-1];
        	}
        }
        vector<pair<int,pii>>v;
        vector<int>ans(m,hell);
        rep3(m){
        	int l,r;cin>>l>>r;
                v.pb({r,{l,i}}); 
        }
        sort(all(v));
        int j=0;
        seg.build(1,1,n);
        for(int i=1;i<=n;i++){
        	if(p[i]!=-1){
        		int val=i-p[i];
        		seg.update(1,p[i],val);
        	} 
                while(j<m && v[j].x==i){
                	ans[v[j].y.y]=seg.query(v[j].y.x,i);
                	j++;
                }
        }
        for(auto i:ans){
        	if(i==hell)cout<<-1<<endl;
        	else cout<<i<<endl;
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