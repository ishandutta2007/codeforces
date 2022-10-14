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
 		int n,k; cin >> n >> k;
 		vector<vector<int>> occ(n + 1,vector<int>(k + 1));
 		vector<int> now(n + 1);
 		for(int i = 1; i <= n*k; i++){
 			int x; cin >> x;
 			occ[x][++now[x]] = i;
 		}
 		set<int> rem;
 		for(int i = 1; i <= n; i++){
 			rem.insert(i);
 		}
 		vector<pii> ans(n + 1);
 		for(int c = 2; c <= k; c++){
 			int th = n/(k - 1);
 			if(n % (k - 1))th++;
 			vector<int> ord(n);
 			iota(all(ord),1);
 			sort(all(ord),[&](auto a,auto b){
 				return occ[a][c] < occ[b][c];
 			});
 			for(auto i:ord){
 				if(th == 0)break;
 				if(rem.count(i) == 0)continue;
 				th--;
 				ans[i] = {occ[i][c - 1],occ[i][c]};
 				rem.erase(i);
 			}
 		}
 		for(int i = 1; i <= n; i++)cout << ans[i] << endl;
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