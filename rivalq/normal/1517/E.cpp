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
		vector<vector<int>>vec;
		vector<int>a(n+1),p1(n+1),p2(n+1);
		int s = 0;
		int ans2 = 0;
		rep(i,1,n+1){
			cin >> a[i];
			p1[i] = p1[i-1];
			p2[i] = p2[i-1];
			s += a[i];
			if(i%2)p1[i] += a[i];
			else p2[i] += a[i];
		}
		auto func = [&](vector<int>t){
			vector<int>z1;
			vector<int>z2;
			int c = 0;
			for(int i = 0; i < n; i++){
				if(t[i]){
					z1.push_back(i);
					c += a[i+1];
				}	
				else z2.push_back(i);
			}

			bool f1 = 1,f2 = 1;
			
			if(sz(z1) > 2){
				for(int i = 2; i < z1.size(); i++){
					if(z1[i] - z1[i-1] < z1[i-1] - z1[i-2]){
						f1 = 0;
					}
				}
			}
			if(sz(z2) > 2){
				for(int i = 2; i < z2.size(); i++){
					if(z2[i] - z2[i-1] > z2[i-1] - z2[i-2]){
						f2 = 0;
					}
				}
			}
			if(f1 and f2){
				vec.push_back(t);
				if(2*c < s)ans2++;
			}

		};

		/**for(int i = 0; i < (1<<n); i++){
			vector<int>t(n);
			for(int j = 0; j < n; j++){
				if((1<<j)&i)t[j] = 1;
			}
			func(t);
		}
		cout << ans2 << endl;**/
		auto brute = [&](){
			int c = a[1], p =0;
			int ans = 0;
			for(int i = 2; i <= n; i++){
				// case 1 last element is 0
				if(i == n){
					if(2*c < s)ans++;
					break;
				}
				if(i == n-1){
					if(2*c < s)ans++;
					if(2*(c + a[n])< s)ans++;
					c += a[i];
					continue;
				}
				int sp = (n - i)/2;
				int L = 1;
				int R = sp;
				int j = 0;
				if(2*c < s)ans++;
				int new_c = c + a[n];
				if(2*new_c < s)ans++;
				// kth one will be at i + 2*k - 1
				while(L <= R){
					int M = (L+R)/2;
					int new_c = c;
					if((i-1)%2){
						new_c += p1[i + 2*M - 1] - p1[i-1];
					}
					else{
						new_c += p2[i + 2*M - 1] -p2[i-1];
					}
					if(2*new_c < s){
						j = M;
						L = M+1;
					}
					else{
						R = M-1;
					}
				} 
				ans += j;
				// last will be 1
				if(i == n-2){
					c += a[i];
					continue;
				}
				sp = (n - i - 1)/2;

				L = 1;
				R = sp;
				j = 0;
				while(L <= R){
					int M = (L+R)/2;
					int new_c = c + a[n];
					if((i-1)%2){
						new_c += p1[i + 2*M - 1] - p1[i-1];
					}
					else{
						new_c += p2[i + 2*M - 1] -p2[i-1];
					}
					if(2*new_c < s){
						j = M;
						L = M+1;
					}
					else{
						R = M-1;
					}
				}
				ans += j;
				c += a[i];
			}
			c = 0;
			for(int i = n; i >= 1; i--){
				if(2*c < s)ans++;
				c += a[i];
			}
			c = a[2];
			for(int i = 3; i <= n; i++){
				// case 1 last element is 0
				if(i == n){
					if(2*c < s)ans++;
					break;
				}
				if(i == n-1){
					if(2*c < s)ans++;
					if(2*(c + a[n])< s)ans++;
					c += a[i];
					continue;
				}
				int sp = (n - i)/2;
				int L = 1;
				int R = sp;
				int j = 0;
				if(2*c < s)ans++;
				int new_c = c + a[n];
				if(2*new_c < s)ans++;
				// kth one will be at i + 2*k
				while(L <= R){
					int M = (L+R)/2;
					int new_c = c;
					if((i-1)%2){
						new_c += p1[i + 2*M - 1] - p1[i-1];
					}
					else{
						new_c += p2[i + 2*M - 1] - p2[i-1];
					}
					if(2*new_c < s){
						j = M;
						L = M+1;
					}
					else{
						R = M-1;
					}
				} 

				ans += j;
				// last will be 1
				if(i == n-2){
					c += a[i];
					continue;
				}
				sp = (n - i-1)/2;

				L = 1;
				R = sp;
				j = 0;
				while(L <= R){
					int M = (L+R)/2;
					int new_c = c + a[n];
					if((i-1)%2){
						new_c += p1[i + 2*M-1] - p1[i-1];
					}
					else{
						new_c += p2[i + 2*M-1] -p2[i-1];
					}
					if(2*new_c < s){
						j = M;
						L = M+1;
					}
					else{
						R = M-1;
					}
				}
				ans += j;
				c += a[i];	
			}
			return ans;

		};

		cout << brute()%998244353 << endl;

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