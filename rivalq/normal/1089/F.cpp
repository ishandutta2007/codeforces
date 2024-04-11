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


int mod_inv(int a, int m) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
}

int solve(){
 		int n; cin >> n;
 		vector<int>v;
 		int m = n - 1;
 		for(int i = 2; i <= sqrt(n);i++){
 			if(n%i == 0){
 				while(n%i == 0)n /= i;
 				v.push_back(i);
 			}
 		}
 		if(n > 1){
 			v.push_back(n);
 		}
 		if(v.size() == 1){
 			cout << "NO" << endl;
 			return 0;
 		}
 		cout << "YES" << endl;
 		int p1 = v[0],p2 = v[1];
 		// p1x + p2y = n - 1;
 		int x = mod_inv(p1,p2)*(m)%p2;
 		int y = (m - p1*x)/p2;
 		cout << 2 << endl;
 		cout << x << " " << (m+1)/p1 << endl;
 		cout << y << " " << (m+1)/p2 << endl;
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