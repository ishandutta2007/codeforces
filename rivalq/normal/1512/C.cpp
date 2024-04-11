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
 		int a,b; cin >> a >> b;
 		string s; cin >> s;
 		int n  = a+b;
 		for(int i = 0; i < n/2; i++){
 			if(s[i] == '0' and s[n - i - 1] == '1'){
 				cout << -1 << endl;
 				return 0;
 			}
 			if(s[i] == '1' and s[n - i - 1] == '0'){
 				cout << -1 << endl;
 				return 0;
 			}
 			if(s[i] != '?' and s[n - i - 1] == '?'){
 				s[n - i - 1] = s[i];
 			}
 			if(s[i] == '?' and s[n - i - 1] != '?'){
 				s[i] = s[n - i - 1];
 			}
 		}
 		for(int i = 0; i < n; i++){
 			if(s[i] == '1') b--;
 			if(s[i] == '0') a--;
 		}
 		if(a < 0 or b < 0){
 			cout << -1 << endl;
 			return 0;
 		}
 		//cout << "#" << s << endl;
 		if(n%2 == 0){
 			if(a%2 or b%2){
 				cout << -1 << endl;
 				return 0;
 			}
 			for(int i = 0; i < n/2; i++){
 				if(s[i] == '?'){
 					if(a > 0){
 						a -= 2;
 						s[i] = '0';
 						s[n - i - 1] = '0';
 					}
 					else{
 						b -= 2;
 						s[i] = '1';
 						s[n - i - 1] = '1';
 					}
 				}
 			}
 			cout << s << endl;
 		}
 		else{
 			if(a%2 and b%2){
 				cout << -1 << endl;
 				return 0;
 			}
 			if(a%2){
 				if(s[n/2] != '?'){
 					cout << -1 << endl;
 					return 0;
 				}
 				s[n/2] = '0';
 				a--;
 			}
 			else if(b%2){
 				if(s[n/2] != '?'){
 					cout << -1 << endl;
 					return 0;
 				}
 				b--;
 				s[n/2] = '1';
 			}
 			for(int i = 0; i < n/2; i++){
 				if(s[i] == '?'){
 					if(a > 0){
 						a-=2;
 						s[i] = '0';
 						s[n - i - 1] = '0';
 					}
 					else{
 						b-=2;
 						s[i] = '1';
 						s[n - i - 1] = '1';
 					}
 				}
 			}
 			cout << s << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}