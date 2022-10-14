#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
    int a=0;
    int idx=0;
    node (int val=0){
    }
    void merge(node &n1,node &n2){
         this->a=max(n1.a,n2.a);
         if(n1.a==a)idx=n1.idx;
         else idx=n2.idx;
    }
};
const int N=500005;
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
          t[v].idx=tl[v];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int idx,int val){
      if(tl[v]==tr[v]){
      	t[v].a=val;
      	return;
      }
      int mid=(tl[v]+tr[v])/2;
      if(idx<=mid)zeno(2*v,idx,val);
      else zeno(2*v+1,idx,val);
      t[v].merge(t[2*v],t[2*v+1]);
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
  void upd(int r,int val){
      return zeno(1,r,val);
  }   
};
segtree<node>seg;
const int maxn=500005;
int ans[maxn];
pair<pii,int> q[maxn];
pii last[maxn];
int nex[maxn];
int a[maxn];
int solve(){
 int n;cin>>n;
 map<int,vector<int>>mp;
 rep(i,1,n+1){
 	cin>>a[i];
 	mp[a[i]].push_back(i);
 }
 int cur=0;
 for(auto i:mp){
 	for(int j=0;j<sz(i.y);j++){
 		if(j>0)last[cur++]={i.y[j-1],i.y[j]};
 		else last[cur++]={0,i.y[j]};
 	}
 	reverse(all(i.y));
 	for(int j=0;j<sz(i.y);j++){
 		if(j>0)nex[i.y[j]]=i.y[j-1];
 		else nex[i.y[j]]=n+1;
 	}
 }
 int m;cin>>m;
 rep3(m){
 	cin>>q[i].x.x>>q[i].x.y;
 	q[i].y=i;
 }
 sort(q,q+m);
 sort(last,last+n);
 int left=0;
 seg.build(1,1,n);
 for(int i=0;i<m;i++){
 	while(left<n && last[left].x<q[i].x.x){
 		int val=nex[last[left].y];
 		seg.upd(last[left].y,val);
 		left++;
 	}
 	int idx=q[i].y;
 	auto s=seg.query(q[i].x.x,q[i].x.y);
 	if(s.a>q[i].x.y)ans[idx]=a[s.idx];
 }
 for_each(ans,ans+m,[](int x){cout<<x<<endl;});
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