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

#define SIEVE

const int N = 1000050;

int lp[N+1];
int pr[N];int t=0;

void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


int solve(){
 		int  n,e; cin >> n >> e; 
 		vector<int> a(n + 1);
 		int ans = 0;
 		vector<vector<int>>vec(e,vector<int>{0});
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			vec[i%e].push_back(a[i]);
 			ans -= (lp[a[i]]  == a[i]);
 		}

 		auto solve = [&](vector<int> a){
 			int n = a.size();n--;
 			vector<int>next_prime(n + 1,-1),ones(n + 2);
 			for(int j = n; j >= 1; j--){
	 			if(a[j] != 1){
	 				ones[j] = 0;
	 			}else{
	 				ones[j] = ones[j + 1] + 1; 
	 			}
 			}
	 		int last_prime = -1;
	 		for(int j = n; j >= 1; j--){
	 			if(a[j] == 1){
	 				if(last_prime != -1){
	 					next_prime[j] = last_prime;
	 				}
	 			}else if(lp[a[j]] == a[j]){
	 				next_prime[j] = j;
	 				last_prime = j;
	 			}else{
	 				last_prime = -1;
	 			}
	 		}

	 		int ans = 0;

	 		for(int i = 1; i <= n; i++){
	 			if(next_prime[i] == -1)continue;
	 			int mn_length = next_prime[i];
	 			int mx_length = mn_length + ones[next_prime[i] + 1];
	 			ans += mx_length - mn_length + 1; 
	 		}
	 		//cout << ans << endl;
	 		return ans;
 		};
 		for(auto i:vec){
 			ans += solve(i);
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}