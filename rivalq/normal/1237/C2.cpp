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
 		map<int,map<int,vector<pii>>>mp;
 		for(int i = 0; i < n; i++){
 			int x,y,z; cin >> x >> y >> z;
 			mp[x][y].push_back({z,i + 1});
 		}
 		vector<int> rem;
 		for(auto i:mp){
 			vector<int>ids;
 			for(auto j:i.y){
 				auto &vec = j.y;
 				sort(all(vec));
 				while(vec.size() > 1){
 					int id1 = vec.back().y;
 					vec.pop_back();
 					int id2 = vec.back().y;
 					vec.pop_back();
 					cout << id1 << " " << id2 << endl;
 				}
 				if(vec.size() > 0)ids.push_back(vec[0].y);
 			}
 			auto &vec = ids;
 			while(vec.size() > 1){
				int id1 = vec.back();
				vec.pop_back();
				int id2 = vec.back();
				vec.pop_back();
				cout << id1 << " " << id2 << endl;
 			}	
 			if(vec.size() > 0)rem.push_back(vec[0]);
 		}
 		auto &vec = rem;
 		while(vec.size() > 1){
				int id1 = vec.back();
				vec.pop_back();
				int id2 = vec.back();
				vec.pop_back();
				cout << id1 << " " << id2 << endl;
 		}
 		assert(vec.size() == 0);	

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