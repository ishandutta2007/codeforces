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
 		map<int,vector<pii>> mp;
 		for(int i = 1; i <= n; i++){
 			int x,y; cin >> x >> y;
 			mp[x].push_back({y,i});
 		}
 		vector<vector<pii>> t;
        vector<int> pt;
 		for(auto i:mp){
 			auto &vec = i.y;
 			sort(all(vec));
 			t.push_back(vec);
            pt.push_back(i.x);
 		}
 		for(int i = 1; i < t.size(); i++){
 			if(t[i].size() >= 2){
 				cout << t[i - 1][0].y << " " << t[i][0].y << " " << t[i][1].y << endl;
 				return 0; 			
 			}
 			if(t[i - 1].size() >= 2){
 				cout << t[i - 1][0].y << " " << t[i - 1][1].y << " " << t[i][0].y << endl;
 				return 0;
 			}
 		}
 		for(int i = 2; i < t.size(); i++){
 			auto y1 = t[i - 2][0].x;
 			auto y2 = t[i - 1][0].x;
 			auto y3 = t[i][0].x;
            if((y2 - y1)*(pt[i] - pt[i - 1]) == (y3 - y2)*(pt[i - 1] - pt[i - 2])){
                continue;
            } 
            cout << t[i - 2][0].y << " " << t[i - 1][0].y << " " << t[i][0].y << endl;

 			return 0;
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