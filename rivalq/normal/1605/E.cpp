// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
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



const int N = 2e5 + 5;

vector<int> d[N];

map<int,int> mp[N];

int solve(){
 		int n; cin >> n;
 		vector<ll> a(n + 1);
 		vector<ll> b(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		for(int i = 1; i <= n; i++){
 			cin >> b[i];
 		}
 		for(int i = 1; i <= n; i++){
 			mp[i][i]++;
 			for(auto j:d[i]){
 				for(auto k:mp[j]){

 					mp[i][k.x] -= k.y;
 					if(mp[i][k.x] == 0){
 						mp[i].erase(k.x);
 					}
 				}
 			}
 		}
 		for(int i = 2; i <= n; i++){
 			a[i] -= b[i];
 		}
 		vector<pair<ll,ll>> val(n + 1);
 		for(int i = 1; i <= n; i++){
 			for(auto j:mp[i]){
 				int var = j.x;
 				int coeff = j.y;
 				if(var > 1){
 					val[i].x += coeff*a[var];
 				}else{
 					val[i].x += coeff*a[var];
 					val[i].y -= coeff;
 				}
 			}
 		}

 		vector<ll>final = {0};
 		ll ans = 0;
 		for(int i = 1; i <= n; i++){
 			if(val[i].y == 0){
 				ans += abs(val[i].x);
 			}else{
 				if(val[i].y < 0){
 					val[i].y = 1;
 					val[i].x *= -1;
 				}
 				val[i].x *= -1;
 				final.push_back(val[i].x);
 			}
 		}
 		sort(final.begin() + 1,final.end());
 		int m = final.size();
 		vector<ll> pre(m);
 		pre[0] = 0;
 		for(int i = 1; i < m; i++){
 			pre[i] += pre[i - 1] + final[i];
 		}


 		auto solve = [&](int x){
 			int n = pre.size();n--;
 			int j = upper_bound(final.begin() + 1,final.end(),x) - final.begin();j--;
 			ll val = 1LL*x*(j) - pre[j];
 			val += (pre.back() - pre[j]) - 1LL*x*(n - j);
 			return val;
 		};
 		int q; cin >> q;
 		rep(i,0,q){
 			int x; cin >> x;
 			cout << ans + solve(x) << endl;
 		}
 		



 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ans = 0;
    for(int i = 1; i < N ; i++){
    	for(int j = 2*i; j < N; j += i){
    		d[j].push_back(i);
    	}
    }
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