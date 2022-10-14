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


const int N = 1e3+5;

vector<int>g[N];

int par[N];

int d[N];

int vis[N];

int reqd;

void dfs(int u,int v){
	for(auto i:g[u]){
		if(i!=v){
			d[i] = d[u] + 1;
			par[i] = u;
			dfs(i,u);
		}
	}
}

vector<int>t;
void dfs2(int u){
	reqd--;
	t.push_back(u);
	if(reqd == 0){
		return;
	}
	vis[u] = 1;
	for(auto i:g[u]){
		if(!vis[i]){
			dfs2(i);
			t.push_back(u);
			if(reqd == 0)return;
		}
	}
}

int solve(){
 		int n,k; cin >> n >> k;
 		rep(i,1,n+1){
 			g[i].clear();
 			par[i] = 0;
 			d[i] = 0;
 			vis[i]  = 0; 
 		}
 		rep(i,2,n+1){
 			int a; cin >> a;
 			g[a].push_back(i);
 			g[i].push_back(a);
 		}
 		dfs(1,1);
 		pii p ={-1,-1};
 		for(int i = 1; i <= n; i++){
 			maxs(p,make_pair(d[i]+1,i));
 		}
 		vector<int>v;
 		int u = p.y;
 		while(true){
 			vis[u]  = 1;
 			v.push_back(u);
 			u = par[u];
 			if(u==0)break;
 		}
 		reverse(all(v));

 		if(v.size() >= k){
 			cout << k - 1 << endl;
 			for(int i = 0;i < k; i++){
 				cout << v[i] << " ";
 			}
 			cout << endl;
 			return 0;
 		}
 		reqd = k - (int)v.size();
 		vector<int>ans;
 		for(int i = 0; i < v.size(); i++){
 			t.clear();
 			if(reqd){
 				ans.push_back(v[i]);
 				for(auto j:g[v[i]]){
 					if(!vis[j]){
 						dfs2(j);
 						t.push_back(v[i]);
 						if(reqd == 0){
 							break;
 						}
 					}
 				}
 				for(auto i:t)ans.push_back(i);
 			}
 			else{
 				ans.push_back(v[i]);
 			}
 		}
 		cout << sz(ans) - 1 << endl;
 		for(auto i:ans)cout <<i << " ";
 		cout << endl;
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