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
 		vector<int>a(n+1),p(n+1),c(n+1),vis(n+1);
 		rep(i,1,n+1){
 			cin >> a[i];
 			p[a[i]] = i;
 		}
 		vector<vector<int>>cyc;

 		vector<pii>op;

 		auto add = [&](int i,int j){
 			op.push_back({p[i],p[j]});
 			c[i] ^= 1;
 			c[j] ^= 1;
 			swap(p[i],p[j]);
 		};

 		for(int i = 1; i <= n; i++){
 			if(!vis[i] and a[i] != i){
 				int u = a[i];
 				vector<int>t;
 				while(!vis[u]){
 					vis[u] = 1;
 					t.push_back(u);
 					u = a[u];
 				}
 				cyc.push_back(t);

 			}
 		}

 		auto pr = [&](){
 			for(int i = 1; i <= n; i++)cout << p[i] << " ";
 			cout << endl;
 			for(int i = 1; i <= n; i++)cout << c[i] << " ";
 			cout << endl;	
 		};

 		auto solve_cycle = [&](vector<int>t){
 			int m = t.size();
 			add(t[0],t[1]);
 			add(t[0],t[2]);
 			swap(t[0],t[1]);
 			add(t[0],t[1]);
 			for(int i = 2; i + 1 < t.size(); i++){
 				add(t[i],t[i+1]);
 			}
 			add(t.back(),t[1]);

 		};

 		auto solve_cycle2 = [&](vector<int>t1,vector<int>t2){
 			add(t1[0],t2[0]);
 			vector<int>t;
 			
 			for(int i = 1; i < t1.size(); i++){
 				add(t1[i],t1[i-1]);
 			}

 			for(int i = 1; i < t2.size(); i++){
 				add(t2[i],t2[i-1]);
 			}
 			add(t2.back(),t1.back());
 			
 			//pr();	
 		};

 		for(int i = 1; i < cyc.size();i += 2){
 			solve_cycle2(cyc[i],cyc[i-1]);
 		}
 		if(sz(cyc)%2){
 			bool found = 0;
 			for(int i = 1; i <= n; i++){
 				if(p[i] == i){ 					
 					solve_cycle2(cyc.back(),vector<int>{i});
 					found = 1;
 					break;
 				}
 			}
 			if(!found){
 				solve_cycle(cyc.back());
 			}
 		}
 		//pr();
 		cout << op.size() << endl;
 		for(auto i:op)cout << i << endl;

 		
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