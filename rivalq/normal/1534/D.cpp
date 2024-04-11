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


int solve(){
 		int n; cin >> n;
 		set<int>st;
 		rep(i,1,n+1){
 			st.insert(i);
 		}
 		vector<pii>edges;
		vector<vector<int>>d(2);
		map<int,vector<int>>mp;
		auto ask = [&](int x){
			if(mp.count(x))return mp[x];
			cout << "? " << x << endl << flush;
			vector<int>d(n+1);
			rep(i,1,n+1){
				cin >> d[i];
			}
			return mp[x] = d;
		};

		auto v = ask(1);
		for(int i = 1; i <= n; i++){
			int x = v[i];
			d[x%2].push_back(i);
		} 		
		if(sz(d[0]) > sz(d[1]))swap(d[0],d[1]);

		for(auto j:d[0]){
			auto v = ask(j);
			for(int i = 1; i <= n; i++){
				int x = v[i];
				if(x == 1){
					edges.push_back({i,j});
				}
			} 		
		}
		cout << "!" << endl;
 		for(auto i:edges){
 			cout << i << endl;
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