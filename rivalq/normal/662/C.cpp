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



namespace fwht{


	template<typename T>
	void hadamard_xor(vector<T> &a){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j + k];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}
	template<typename T>
	void hadamard_or(vector<T> &a,bool inverse){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j + k];
					if(inverse){
						a[i + j] = y - x;
						a[i + j +k] = x;
					}
					else{
						a[i + j] = y;
						a[i + j + k] = x + y;
					}
				}
			}
		}
	}
	template<typename T>
	void hadamard_and(vector<T> &a,bool inverse){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j +k];
					if(inverse){
						a[i + j] = x - y;
						a[i + j + k] = y;
					}
					else{
						a[i + j] = x + y;
						a[i + j + k] = y;	
					}
					
				}
			}
		}
	}
	template<typename T>
	vector<T> multiply(vector<T> a,vector<T> b){
		int eq = (b==a);
		int n = 1 ;
		while (n < (int)max(a.size(),b.size())){
			n <<= 1;
		} 
		a.resize(n);
		b.resize(n);
		hadamard_xor(a);
		if (eq) b = a; else hadamard(b);
		for(int i = 0 ; i < n ; i++){
			a[i]*=b[i];
		}
		hadamard_xor(a);
		T q = 1/static_cast<T>(n);
		for(int i = 0 ; i < n ; i++){
			a[i]*=q;
		}
		return a;
	}


}


int solve(){
 		int n,m; cin >> n >> m;
 		vector<int>mask(m+1);
 		rep(i,0,n){
 			rep(j,1,m+1){
 				char c; cin >> c;
 				int t = c - '0';
 				mask[j] += (1 << i)*t;
 			}
 		}
 		vector<int>poly(1 << n);
 		vector<int>best(1 << n);
 		for(int i = 1; i <= m; i++){
 			poly[mask[i]]++;
 		}
 		for(int i = 0; i < (1 << n); i++){
 			int z = __builtin_popcount(i);
 			best[i] = min(z,n - z);
 		}
 		fwht::hadamard_xor(poly);
 		fwht::hadamard_xor(best);

 		for(int i = 0; i < (1 << n); i++){
 			poly[i] = poly[i]*best[i];
 		}

 		fwht::hadamard_xor(poly);
 		int ans = n*m;

 		for(int i = 0; i < (1 << n); i++){
 			mins(ans,poly[i]/(1 << n));
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