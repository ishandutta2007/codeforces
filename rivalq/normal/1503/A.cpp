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
 		string s;cin >> s;
 		if(s.front() == '0' or s.back() == '0'){
 			cout << "NO" << endl; return 0;
 		}
 		bool f = 0;
 		string t1(n,'0');
 		string t2(n,'0');
 		int rem = n;
 		for(int i = 0; i < n; i++){
 			if(s[i] == '0'){
 				if(f == 0){
 					t1[i] = '(';
 					t2[i] = ')';
 				}
 				else{
 					t1[i] = ')';
 					t2[i] = '(';
 				}
 				f ^= 1;
 				rem--;
 			}
 		}
 		rem /= 2;
 		if(f){
 			cout << "NO" << endl;
 			return 0;
 		}
 		for(int i = 0; i < n; i++){
 			if(t1[i] == '0'){
 				if(rem){
 					t1[i] = t2[i] ='(';
 					rem--;
 				}	
 				else{
 					t2[i] = t1[i] = ')';
 				}
 			}
 		}
 		cout << "YES" << endl;
 		cout << t1 << endl << t2 << endl;
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