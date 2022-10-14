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

#define double long double

int solve(){
 		int n; cin >> n;
 		map<int,vector<int>> mp;
 		vector<int> cnt(21);
 		for(int i = 1; i <= n; i++){
 			int m,k; cin >> m >> k;
 			if(mp.count(m))mp[m][k]++;
 			else {
 				mp[m] = vector<int>(21);
 				mp[m][k]++;
 			}
 			cnt[k]++;
 		}
 		int mx = 0;
 		int den = 1;  
 		vector<int> ans;
 		int m = sz(mp);
 		for(int t = 1; t <= min(20LL,m); t++){
 			vector<pair<int,int>> rem;
 			int val = 0;
 			for(auto i:mp){
 				int c = 0;
 				auto temp = i.y;
 				for(int j = 1; j < t; j++){
 					c += j*temp[j];
 				}
 				for(int j = t; j <= 20; j++){
 					c += temp[j]*t;
 				}
 				rem.push_back({c,i.x});
 			}
 			sort(rem.begin(),rem.end());
 			reverse(all(rem));
 			vector<int> temp;
 			for(int j = 0; j < min(sz(rem),t); j++){
 				val += rem[j].x;
 				temp.push_back(rem[j].y);
 			}
 			if(mx*t < val*den){
 				mx = val;
 				den = t;
 				ans = temp;
 			}
 		}	

 		if(m > 20){
 			vector<pair<double,int>> rem;
 			int val = 0;
 			for(auto i:mp){
 				int c = 0;
 				auto temp = i.y;
 				 for(int j = 1; j <= 20; j++){
 					c += j*temp[j];
 				}
 				rem.push_back({c,i.x});
 			}
 			sort(rem.begin(),rem.end());
 			reverse(all(rem));
 			for(int j = 0; j < 20; j++){
 				val += rem[j].x;
 			}
 			int num_1 = 0, den_1 = 1;
 			int best = -1;
 			for(int t = 21; t <= m; t++){
 				val += rem[t].x;
 				if(num_1*t < val*den_1){
 					num_1 = val;
 					den_1 = t;
 					best = t;
 				}
 			}
 			if(mx*den_1 < num_1*den){
 				ans.clear();
 				for(int t = 1; t <= best; t++){
 					ans.push_back(rem[t].y);
 				}
 			}	
 		}
 		//cout << mx << endl;
 		cout << ans.size() << endl;
 		for(auto i:ans)cout << i << " ";cout << endl;

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