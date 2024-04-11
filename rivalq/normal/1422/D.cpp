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

const int N=2e5+5;

vector<pii>g[N];

int solve(){
 	int n,m;cin>>n>>m;
 	pii s,f;cin>>s>>f;
 	vector<pair<pii,int>>v1(m+1);
 	auto dis1=[&](pii p1,pii p2){
 		return abs(p1.x-p2.x)+abs(p1.y-p2.y);
 	};
 	auto dis2=[&](pii p1,pii p2){
 		return min(abs(p1.x-p2.x),abs(p1.y-p2.y));
 	};
 	g[m+1].eb(m+2,dis1(s,f));
 	rep(i,1,m+1){
 		cin>>v1[i].x;
 		v1[i].y=i;
 		g[m+1].eb(i,dis2(v1[i].x,s));
 		g[i].eb(m+2,dis1(v1[i].x,f));
 	}
 	sort(v1.begin()+1,v1.end());
 	rep(i,2,m+1){
 		int u=v1[i-1].y;
 		int v=v1[i].y;
 		int w=dis2(v1[i].x,v1[i-1].x);
 		g[u].eb(v,w);
 		g[v].eb(u,w);
 	}
 	sort(v1.begin()+1,v1.end(),[&](pair<pii,int>p1,pair<pii,int>p2){
 		return p1.x.y<p2.x.y;	
 	});
 	rep(i,2,m+1){
 		int u=v1[i-1].y;
 		int v=v1[i].y;
 		int w=dis2(v1[i].x,v1[i-1].x);
 		g[u].eb(v,w);
 		g[v].eb(u,w);
 	}
 	multiset<pii> pq;
 	vector<int> vi(m+3);
 	vector<int> dis(m+3);
 	rep(i,1,m+3)dis[i]=1e18;
 	dis[m+1]=0;
 	pq.insert({0,m+1});
 	while(!pq.empty()){
 	      pii v=*pq.begin();
 	      pq.erase(pq.begin());
 	      int node=v.y;
 	      int wei=v.x;
 	      if(vi[node])continue;
 	      vi[node]=1;
 	      for(auto i:g[node]){
 	          int e=i.x;
 	          int w=i.y;
 	          if(dis[node]+w<dis[e]){
 	              dis[e]=dis[node]+w;
 	              pq.insert({dis[e],e});
 	          }
 	      }
 	}
 	cout<<dis[m+2]<<endl;
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