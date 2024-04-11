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
 			int n,m; cin >> n >> m;
 			map<int,int>mp;
 			vector<vector<int>>vec(n + 1);
 			for(int i = 1; i <= n; i++){
 				int x; cin >> x;
 				mp[x]++;
 			}	
 			for(auto i:mp){
 				vec[i.y].push_back(i.x);
 			}

 			set<pii>edges;

 			for(int i = 0; i < m; i++){
 				int x,y; cin >> x >> y;
 				edges.insert({x,y});
 				edges.insert({y,x});
 			}
 			auto check = [&](int u,int v){
 				return edges.count(make_pair(u,v)) == 0;
 			};
 			int ans = 0;
 			vector<int> non;

 			for(int k = 1; k <= n; k++){
 				sort(all(vec[k]));
 				auto &arr = vec[k];
 				if(arr.size() >= 2){
 					int n = arr.size();
 					for(int i = 0; i < n; i++){
 						int j = n - 1;
 						while(j > i and check(arr[i],arr[j]) == 0)j--;
 						if(j > i)maxs(ans,2*k*(arr[i] + arr[j]));
 					}
 				}
 				if(arr.size() >= 1){
 					non.push_back(k);
 				}
 			}

 			for(int i = 0; i < non.size(); i++){
 				for(int j = i + 1; j < non.size(); j++){
 					auto &vec1 = vec[non[i]];
 					auto &vec2 = vec[non[j]];
 					int sum = non[i] + non[j];
 					if(vec1.size() > vec2.size()){
 						int n = vec2.size();
	 					int m = vec1.size();
	 					for(int i = 0; i < n; i++){
	 						int j = m - 1;
	 						while(j >= 0 and check(vec2[i],vec1[j]) == 0)j--;
	 						if(j >= 0){
	 							maxs(ans,sum*(vec2[i] + vec1[j]));
	 						}
	 					}	
 					}else{
 						int n = vec1.size();
	 					int m = vec2.size();
	 					for(int i = 0; i < n; i++){
	 						int j = m - 1;
	 						while(j >= 0 and check(vec1[i],vec2[j]) == 0)j--;
	 						if(j >= 0){
	 							maxs(ans,sum*(vec1[i] + vec2[j]));
	 						}
	 					}
 					}
 				}
 			}
 			cout << ans << endl;





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