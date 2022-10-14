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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int maxn=300005;
int dp1[maxn],dp2[maxn],cont[maxn];
vector<int>g[maxn];
int ans=0;
void dfs1(int u=1,int p=0){
	dp1[u]=1;
	priority_queue<pii>pq;
	for(auto i:g[u]){
		if(i!=p){
           dfs1(i,u);
           pq.push({dp1[i],i});
		}
	}	
	if(!pq.empty()){
		dp1[u]+=pq.top().x;
        pq.pop();
	}
	dp1[u]+=pq.size();
}
void dfs2(int u=1,int p=0,int w=0,int cnt=-1){
	priority_queue<pii>pq;
	for(auto i:g[u]){
		if(i!=p)pq.push({dp1[i],i});
	}
	pq.push({w,0});
	dp2[u]=1;
	int c1=0,c2=0;
	if(!pq.empty())dp2[u]+=pq.top().x,c1=pq.top().y,pq.pop();
	if(!pq.empty())dp2[u]+=pq.top().x,c2=pq.top().y,pq.pop();
	if(sz(g[u])>2)dp2[u]+=sz(g[u])-2;
	while(!pq.empty())pq.pop();	
	maxs(ans,dp2[u]);
	for(auto i:g[u]){
		if(i!=p){
			int ww;
			if(i==c1)ww=dp1[c2]+1;
			else     ww=dp1[c1]+1;
			dfs2(i,u,ww,0);
		}
	}
}
int solve(){
 int n;cin>>n;
 for(int i=1;i<=n;i++)g[i].clear();
 ans=0;
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }	
 dfs1();
 dfs2();
 cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}