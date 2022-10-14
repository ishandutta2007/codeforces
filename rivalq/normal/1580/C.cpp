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

const int B = 450;



int solve(){
 		int n,m; cin >> n >> m;

 		vector<pii> a(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}

 		vector<int> pre(m + 2);

 		vector<vector<pii>> segs(n + 1);
 		vector<int> last(n + 1,-1);

 		vector<vector<int>> cont(B,vector<int>(B));
 		int ans = 0;
 		for(int i = 1; i <= m; i++){
 			int op,k; cin >> op >> k;
 			ll x = a[k].x,y = a[k].y;
 			ll sum = x + y;
 			if(op == 1){	
				if(sum >= B){
					ll l = i + x;
					ll r = l + y;
					last[k] = i;
					while(l <= m){
						pre[l]++;
						if(r <= m)pre[r]--;
						l += sum;
						r += sum;
					}
				}else{
					ll s = i + x;
					while(y--){
						cont[sum][s%sum]++;
						s++;
					}
					last[k] = i;
				}
 			}else{
 				if(sum >= B){
 					ll l = last[k] + x;
 					ll r = l + y;
 					while(l <= m){
						if(i >= l and i < r)pre[i]--;
 						if(l > i)pre[l]--;
 						if(r > i and r <= m)pre[r]++;
 						l += sum;
 						r += sum;
					}
 					
 				}else{
 					ll s = last[k] + x;
 					while(y--){
						cont[sum][s%sum]--;
						s++;
					}
 				}
 			}
 			ans += pre[i];
 			int val = 0;
 			for(int mod = 1; mod < B; mod++){
 				val += cont[mod][i%mod];
 			}
 			cout << ans + val << endl;
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