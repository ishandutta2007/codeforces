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
 		//n = 5;
 		vector<int> a(n + 1);
 		bool yes = 0;
 		for(int i = 1; i <= n; i++){
 			//if((1 << (i - 1)) & masks[cnt])a[i] = 1;
 			cin >> a[i];
 			a[i] ^= a[i - 1];
 			if(i & 1){
 				if(a[i]  == 0)yes = 1;
 			}
 		}
 		if(a[n] or !yes){
 			cout << "NO" << endl;
 			return 0;
 		}
 		vector<int> op;
 		auto perform = [&](int i){
 			a[i] = a[i + 2];
 			a[i + 1] = a[i - 1];
 			op.push_back(i);
 		};
 		
 		int j = 1;
 		while(j <= n and a[j]) j += 2;
 		assert(j <= n and !a[j]);
 		// Performed on even places
 		for(int i = j + 2; i < n; i += 2){
 			if(a[i]){
 				perform(i - 1);
 			}
 			assert(a[0] == 0);
 		}

 		for(int i = j - 2; i >= 1; i -= 2){
 			if(a[i]){
 				perform(i);
 			}
 			assert(a[0] == 0);
 		}
 		

 		for(int i = 2; i < n; i += 2){
 			if(a[i]){
 				perform(i - 1);
 			}
 			assert(a[0] == 0);
 		}
 		


 		
 		cout << "YES" << endl;
 		cout << op.size() << endl;
 		for(auto i:op)cout << i << " ";
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
    //t = masks.size();
    while(t--){
        solve();
    }
    return 0;
}