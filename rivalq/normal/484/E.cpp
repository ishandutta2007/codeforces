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

const int N=2e5;
int ans[N];
int L[N],R[N],w[N];

struct node{
    int suff=0;
    int preff=0;
    int ans=0;
    int r=0;
    void merge(node &n1,node &n2){
          this->ans=max({n1.suff+n2.preff,n1.ans,n2.ans});
          preff=n1.preff;
          suff=n2.suff;
          if(n1.preff==n1.r){
          	this->preff=n1.r+n2.preff;
          }
          if(n2.suff==n2.r){
          	this->suff=n2.r+n1.suff;
          }
          r=n1.r+n2.r;

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
          t[v].preff=0;
          t[v].suff=0;
          t[v].ans=0;
          t[v].r=1;
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
            t[v].preff=val;
            t[v].suff=val;
            t[v].ans=val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
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
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};

segtree<node>seg;
vector<pii>h(N);
void dfs(int l,int r,vector<int>&rem){
	int mid=(l+r)/2;
	int a=h[mid].x;
	for(int i=l;i<=mid;i++){
		seg.upd(h[i].y,h[i].y,1);
	}
	vector<int>reml,remr;
	for(auto i:rem){
		int c=seg.query(L[i],R[i]).ans;
		if(c>=w[i]){
			reml.pb(i);
		}
		else{
			remr.pb(i);
		}
	}
	if(l==r){
		for(auto i:reml){
			ans[i]=a;
		}

		for(int i=l;i<=mid;i++){
			seg.upd(h[i].y,h[i].y,0);
		}
	}
	else{
		dfs(mid+1,r,remr);
		for(int i=l;i<=mid;i++){
			seg.upd(h[i].y,h[i].y,0);
		}
		dfs(l,mid,reml);
	}
}

int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1){
 		cin>>h[i].x;
 		h[i].y=i;
 	}
 	sort(h.begin()+1,h.end(),greater<pii>());
 	seg.build(1,1,n);
 	int m;cin>>m;
 	vector<int>rem;
 	rep(i,1,m+1){
 		cin>>L[i]>>R[i]>>w[i];
 		rem.pb(i);
 	}
 	dfs(1,n,rem);
 	rep(i,1,m+1){
 		cout<<ans[i]<<endl;
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