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

const int N = 5e3+5;

vector<int>g[N];

vector<vector<int>>com[2];
int c[N],vis[N];
vector<int>t[2];


void dfs(int u){
	vis[u]=1;
	t[c[u]].pb(u);
	for(auto i:g[u]){
		if(vis[i]){
			if(c[i]==c[u]){
				cout<<"NO"<<endl;exit(0);
			}
		}
		else{	
			c[i]=c[u]^1;
			dfs(i);
		}
	}
}

int solve(){
 		int n,m;cin>>n>>m;
 		int n1,n2,n3;cin>>n1>>n2>>n3;
 		for(int i=0;i<m;i++){
 			int a,b;cin>>a>>b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 		}
 		int cur=0;
 		for(int i=1;i<=n;i++){
 			if(!vis[i]){
 				cur++;
 				t[0].clear();t[1].clear();
 				dfs(i);
 				com[0].pb(t[0]);
 				com[1].pb(t[1]);
 			}
 		}
 		vector<int>ans(n+1);
 		vector<vector<int>>dp(cur+1,vector<int>(n+1));
 		dp[0][0]=1;
 		for(int i=1;i<=cur;i++){
 			for(int j=0;j<=n;j++){
 				int s=sz(com[0][i-1]);
 				if(j>=s)dp[i][j]|=dp[i-1][j-s];
 				s=sz(com[1][i-1]);
 				if(j>=s)dp[i][j]|=dp[i-1][j-s];
 			}
 		}
 		if(!dp[cur][n2]){
 			cout<<"NO"<<endl;return 0;
 		}
 		int s=n2;
 		int j=cur;
 		while(s>0){
 			int sj=sz(com[0][j-1]);
 			int xj=sz(com[1][j-1]);
 			if(s>=sj && dp[j-1][s-sj]){
 				while(!com[0][j-1].empty()){
 					ans[com[0][j-1].back()]=2;
 					com[0][j-1].pop_back();
 				}
 				s-=sj;
 				j--;
 			}
 			else{
 				assert(s>=xj && dp[j-1][s-xj]);
 				while(!com[1][j-1].empty()){
 					ans[com[1][j-1].back()]=2;
 					com[1][j-1].pop_back();
 				}
 				s-=xj;
 				j--;
 			}
 		}
 		bool f=0;
 		for(int i=0;i<cur;i++){
 			if(sz(com[0][i])<sz(com[1][i]))swap(com[0][i],com[1][i]);
 			if(f==0){
 				if(sz(com[0][i])<n1){
 					n1-=sz(com[0][i]);
 					while(!com[0][i].empty()){
 						ans[com[0][i].back()]=1;
 						com[0][i].pop_back();
 					}
 				}
 				else{
 					f=1;
 					for(int j=0;j<n1;j++){
 						ans[com[0][i][j]]=1;
 					}
 					for(int j=n1;j<sz(com[0][i]);j++){
 						ans[com[0][i][j]]=3;
 					}
 				}
 			}
 			else{
 				for(int j=0;j<sz(com[0][i]);j++){
 					ans[com[0][i][j]]=3;
 				}
 			}
 			
 		}
 		cout<<"YES"<<endl;
 		for(int i=1;i<=n;i++)cout<<ans[i];
 			cout<<endl;
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