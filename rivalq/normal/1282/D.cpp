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


const int N = 300;
int solve(){

 		auto ask = [&](string t){
 			cout << t << endl << flush;
 			int x; cin >> x;
 			if(x == 0)exit(0);
 			return x;
 		};
 		int d1 = ask(string(N,'a')); 
 		int d2 = ask(string(N,'b'));
 		int n = 2*N - d1 - d2;
 		
 		int a = d2 - N + n;
 		int b = d1 - N + n;

 		int dis = b;
 		string t(n,'a');

 		for(int i = 0; i + 1 < n; i++){
 			t[i] = 'b';
 			auto x = ask(t);
 			if(x > dis){
 				t[i] = 'a';
 			}
 			dis = min(dis,x);
 		}
 		if(dis > 0)t[n - 1] = 'b';
 		ask(t);

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