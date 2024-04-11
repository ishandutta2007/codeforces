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

const int N = 5e5 + 5;

vector<int> vec[N];

int solve(){
 		int q; cin >> q;

 		auto merge = [&](int x,int y){
 			if(sz(vec[x]) <= sz(vec[y])){
 				for(auto i:vec[x])vec[y].push_back(i);
 				vec[x].clear();
 			}else{
 				for(auto i:vec[y])vec[x].push_back(i);
 				vec[y].clear();
 				swap(vec[x],vec[y]);
 			}
 		};
 		int cnt = 0;
 		vector<int> ans;
 		rep(i,0,q){
 			int t; cin >> t;
 			if(t == 1){
 				int x; cin >> x;
 				vec[x].push_back(cnt++);
 			}else{
 				int x,y; cin >> x >> y;
 				if(x == y)continue;
 				merge(x,y);
 			}
 		}
 		ans.resize(cnt);
 		for(int i = 1; i <= 5e5; i++){
 			for(auto j:vec[i]){
 				ans[j] = i;
 			}
 		}
 		for(auto i:ans)cout << i << " ";
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}