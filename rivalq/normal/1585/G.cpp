// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
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





const int N = 5e5 + 5;

vector<int> g[N];
int dp[N];



void dfs(int u,set<int> &values, deque<int> &vec){
	
	if(g[u].size() == 0){
		values.insert(0);
		vec.push_back(0);
		dp[u] = 1;
		return;
	}else{
		int v = g[u][0];
		dfs(v,values,vec);
		if(sz(g[u]) == 1){
			
			values.insert(dp[v]);
			vec.push_front(dp[v]);
			dp[u] = dp[v];
			while(values.count(dp[u]))dp[u]++;
			return;
		}

		int x = dp[v];
		int mn = sz(vec);
		for(int i = 1; i < sz(g[u]); i++){
			v = g[u][i];
			set<int> values2;
			deque<int> vec2;
			dfs(v,values2,vec2);
			x ^= dp[v];
			mins(mn,sz(vec2));
			for(int i = 0; i < mn;i++){
				vec[i] ^= vec2[i]; 
			}
		}
		vec.resize(mn);
		vec.push_front(x);
		set<int> st;
		for(auto i:vec)st.insert(i);
		values = st;
		dp[u] = 0;
		while(st.count(dp[u]))dp[u]++;

	}
}


int solve(){
 		int n; cin >> n;

 		vector<int> roots;
 		for(int i = 1; i <= n; i++)g[i].clear();
 		for(int i = 1; i <= n; i++){
 			int p; cin >> p;
 			if(p == 0){
 				roots.push_back(i);
 			}else{
 				g[p].push_back(i);
 			}
 		}
 		int x = 0;
 		for(auto i:roots){
 			deque<int> vec;
 			set<int> values;
 			dfs(i,values,vec);
 			x  ^= dp[i];
 		}
 		cout << (x ? "YES":"NO") << endl;
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