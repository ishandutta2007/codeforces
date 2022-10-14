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


const int N = 1e5+5;

vector<int>g[N];

bool draw = 0;


set<int>st;

int vis2[N];

void dfs(int u){
	st.insert(u);
	vis2[u] = 1;
	for(auto i:g[u]){
		if(st.count(i)){
			draw = 1;
		}
		else if(!vis2[i]){
			dfs(i);
		}
	}
	st.erase(u);
}


vector<int>path;
int vis[N][2];

void dfs2(int u,int par){
	path.push_back(u);
	vis[u][par]=1;
	if(par==0){
		if(g[u].size()==0){
			cout<<"Win\n";
			for(auto i:path)cout<<i<<" ";cout<<endl;
				exit(0);
		}
	}
	for(auto i:g[u]){
		if(!vis[i][par^1]){
			dfs2(i,par^1);
		}
	}
	path.pop_back();
}


int solve(){
 		int n,m;cin>>n>>m;
 		rep(i,1,n+1){
 			int k;cin>>k;
 			rep(j,0,k){
 				int t;cin>>t;
 				g[i].push_back(t);
 			}
 		}
 		int s ; cin>>s;
 		dfs2(s,1);
 		dfs(s);
 		if(draw){
 			cout<<"Draw\n";
 		}
 		else{
 			cout<<"Lose\n";
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