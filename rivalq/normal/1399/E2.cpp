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

const int N=1e5+5;

vector<pair<int,pii>>g[N];
int sz[N];
int dep[N];
int tot=0;

vector<pair<int,int>>e1,e2;



void dfs(int u,int p,pii edge){
	dep[u]=dep[p]+edge.x;
	if(sz(g[u])==1 && p)tot+=dep[u],sz[u]=1;
	for(auto i:g[u]){
		if(i.x!=p){
			dfs(i.x,u,i.y);
			sz[u]+=sz[i.x];
		}
	}
	if(edge.y==1){
		e1.pb({edge.x,sz[u]});
	}
	else if(edge.y==2){
		e2.pb({edge.x,sz[u]});
	}
}

int solve(){
 	int n,s;cin>>n>>s;tot=0;
 	rep(i,1,n+1){
 		g[i].clear();
 		sz[i]=0,dep[i]=0;
 	}
 	e1.clear(),e2.clear();
 	rep(i,0,n-1){
 		int a,b,w,c;cin>>a>>b>>w>>c;
 		g[a].pb({b,{w,c}});
 		g[b].pb({a,{w,c}});
 	}
 	dfs(1,0,make_pair(0,0));
 	if(s>=tot){
 		cout<<0<<endl;
 		return 0;
 	}
 	vector<int>pre1={0};
 	vector<int>pre2={0};
 	priority_queue<pair<int,pii>>pq;
 	for(auto i:e1){
 		int delta=(i.x-i.x/2)*i.y;
 		pq.push({delta,{i.x/2,i.y}});
 	}

 	while(!pq.empty()){
 		pair<int,pii> p=pq.top();pq.pop();
 		pre1.pb(pre1.back()+p.x);
 		if(p.y.x){
 			int delta=(p.y.x-p.y.x/2)*p.y.y;
 			pq.push({delta,{p.y.x/2,p.y.y}});
 		}
 	}
 	for(auto i:e2){
 		int delta=(i.x-i.x/2)*i.y;
 		pq.push({delta,{i.x/2,i.y}});
 	}
 	while(!pq.empty()){
 		pair<int,pii> p=pq.top();pq.pop();
 		pre2.pb(pre2.back()+p.x);
 		if(p.y.x){
 			int delta=(p.y.x-p.y.x/2)*p.y.y;
 			pq.push({delta,{p.y.x/2,p.y.y}});
 		}
 	}
 	int ans=hell;
 	rep(i,0,sz(pre2)){
 		int val=tot-pre2[i]-s;
 		if(pre1.back()<val)continue;
 		int j=lower_bound(all(pre1),val)-pre1.begin();
 		mins(ans,2*i+j);
 	}	
 	cout<<ans<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}