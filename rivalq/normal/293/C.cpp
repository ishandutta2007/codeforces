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
 		if(n % 3){
 			cout << 0 << endl;
 			return 0;
 		}
 		n /= 3;
 		vector<int> divs;
 		for(int i = 1; i <= sqrt(n); i++){
 			if(n % i == 0){
 				divs.push_back(i);
 			}
 		}
 		int cnt = 0;
 		set<tuple<int,int,int>> st;
 		for(auto i:divs){
 			if(i * i > n/i)break;
 			for(auto j:divs){
 				if(j < i)continue;
 				if(j * j > n / i)continue;
 				if(n % (i * j))continue;
 				int k = (n / i) / j;
 				if(k < j)break;
 				//cout << i << " " << j << " " << k << endl;
 				// a + b = i
 				// b + c = j
 				// c + a = k
 				// a - c = i - j;
 				// 2*a = i - j + k
 				if((i - j + k) % 2 == 0){
 					int a = (i - j + k)/2;
 					int b = i - a;
 					int c = k - a;
 					if(a > 0 and b > 0 and c > 0){
 						if(a > c)swap(a,c);
 						if(a > b)swap(a,b);
 						if(b > c)swap(b,c);
 						if(st.count({a,b,c}))continue;
 						int eq = 0;
 						if(a == b)eq++;
 						if(b == c)eq++;
 						int val = 6;
 						if(eq == 1)val /= 2;
 						if(eq == 2)val /= 6;
 						st.insert({a,b,c});
 						cnt += val;
 					}
 				}
 			}
 		}
 		cout << cnt << endl;

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