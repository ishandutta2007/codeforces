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
 		vector<int> a(n),pref(n + 1),z(n + 1);
 		int cnt = 0;
 		int s = 0;



 		for(auto &i:a){
 			cin >> i;
 			s += i;
 			cnt += (i == 0);
 		}
 		auto b = a;
 		if(abs(s) > cnt*k){
 			cout << -1 << endl;
 			return 0;
 		}

 		for(int i = 1; i <= n; i++){
 			pref[i] = pref[i - 1] + a[i - 1];
 			z[i] = z[i - 1] + (a[i - 1] == 0);
 		}

 		int ans = 1;

 		if(n == 1){
 			cout << ans << endl;
 			return 0;
 		}
 		if(cnt == 1){
 			int x = -s;
 			int mx = 0;
 			int mn = 0;
 			int s2 = 0;
 			for(int i = 1; i <= n; i++){
 				if(a[i - 1] == 0)a[i - 1] = x;
 				s2 += a[i - 1];
 				maxs(mx,s2);
 				mins(mn,s2);
 			}
 			cout << mx - mn + 1 << endl;
 			return 0;
 		}

 		for(int i = 1; i <= n; i++){
 			for(int j = i + 1; j <= n; j++){
 				//max .. min
 				int cnt_2 = z[j] - z[i];
 				// make negative using cnt_2
 				int x = min((s + k*cnt)/(2*k),cnt_2);
 				int rem = cnt - x;
 				int n_s = s - k*x;
 				int to_fix = z[i] + (z[n] - z[j]);
 				int need = abs(n_s) - k*to_fix;
 				maxs(need,0LL);
 				assert(abs(n_s) <= rem*k);
 				maxs(ans,pref[i] - pref[j] + x*k + 1 -need);
 				if(x < cnt_2){
 					int min_r = s - k*cnt + k;
 					int max_r = s - 2*k*x + k*cnt - k;
 					mins(max_r,k - 1);
 					//maxs(max_r,min_r);	
 					if(max_r >= min_r and max_r >= 0){
 						n_s -= max_r;
 						rem--;
 						assert(abs(n_s) <= rem*k);
 						need = abs(n_s) - to_fix*k;
 						maxs(need,0LL);
 						maxs(ans,pref[i] - pref[j] + x*k + max_r + 1 - need);
 					}
 				}
 			}
 			for(int j = i - 1; j >= 1; j--){
 				int cnt_2 = z[i] - z[j];
 				int to_fix = z[j] + (z[n] - z[i]);
 				int x = min((k*cnt - s)/(2*k),cnt_2);
 				int rem = cnt - x;
 				int n_s = s + k*x;
 				int need = abs(n_s) - k*to_fix;
 				maxs(need,0LL);
 				maxs(ans,pref[i] - pref[j] + x*k + 1 - need);
 				if(x < cnt_2){
 					int max_r = k*cnt - s - k - 2*k*x;
 					int min_r = -k*cnt - s + k;
 					mins(max_r,k - 1);
 					//maxs(max_r,min_r);
 					if(max_r >= min_r and max_r >= 0){
 						n_s += max_r;
 						rem--;
 						need = abs(n_s) - to_fix*k;
 						maxs(need,0LL);
 						maxs(ans,pref[i] - pref[j] + x*k + 1 + max_r - need);
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}