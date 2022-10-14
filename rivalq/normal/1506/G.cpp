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
 		string s;cin>>s;
 		vector<queue<int>>mp(26);
 		int n = s.length();
 		for(int i = 0; i < n; i++){
 			mp[s[i]-97].push(i);
 		}
 		int cnt = mp.size();
 		while(cnt--){
 			for(int i = 25; i >= 0; i--){
 				if(mp[i].empty()){
 					continue;
 				}
 				int f_occ = mp[i].front();
 				bool bad = 0;
 				for(int j = 0; j < 26; j++){
 					if(!mp[j].empty() and mp[j].back() < f_occ){
 						bad  = 1;
 						break;
 					}
 				}
 				if(!bad){
 					cout<<char(i+97);
 					for(int j = 0; j < 26; j++){
 						if(i!=j){
 							while(!mp[j].empty() and mp[j].front() < f_occ)mp[j].pop();
 						}
 					}
 					while(!mp[i].empty())mp[i].pop();
 					break;
 				}
 			}
 		}
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