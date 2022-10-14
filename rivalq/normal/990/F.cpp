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
int vis[N];
int flow[N];   // kitna flow niche se ar rha 
vector<int>ans;
vector<int>s;

// sum-(flow from u to p) =s[u]
void dfs(int u,int p,int edge){
	vis[u]=1;
	int sum=0;
	for(auto i:g[u]){
		if(!vis[i.x]){
			dfs(i.x,u,i.y);
			sum+=flow[i.x];
		}
	}
	if(u==1){
		assert(sum==s[u]);
		return;
	}
	if(edge<0){
		// edges is from u to p
		ans[-edge]=sum-s[u];
		flow[u]=ans[-edge];
	}	
	else{
		ans[edge]=s[u]-sum;
		flow[u]=-ans[edge];
	}

}


int solve(){
 	int n,m;cin>>n;
 	s.resize(n+1);
 	int sum=0;
 	rep(i,1,n+1){
 		cin>>s[i];
 		sum+=s[i];
 	}
 	if(sum){
 		cout<<"Impossible"<<endl;return 0;
 	}cin>>m;
 	ans.resize(m+1);
 	rep(i,1,m+1){
 		int a,b;cin>>a>>b;
 		g[a].pb({b,i});
 		g[b].pb({a,-i});
 	}
 	dfs(1,1,0);
 	cout<<"Possible"<<endl;
 	for(int i=1;i<=m;i++){
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