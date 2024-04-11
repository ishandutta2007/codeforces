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
 		int x,y; cin >> x >> y;
 		auto get = [&](int x){
 			string s;
 			while(x){
 				s.push_back('0' + x%2);
 				x /= 2;
 			}
 			reverse(all(s));
 			return s;
 		};
 		auto s = get(x);
 		auto t = s;
 		while(t.back() == '0')t.pop_back();
 		reverse(all(t));
 		auto check = [&](string s){
 			auto t = get(y);
 			if(t.length() < s.length())return 0;
 			int m = t.length();
 			int n = s.length();
 			for(int i = 0; i + n - 1 < m; i++){
 				int flag = 1;
 				for(int j = 0; j < n; j++){
 					if(t[i + j] != s[j]){
 						flag = 0;
 						break;
 					}
 				}
 				if(flag){
 					for(int j = i + n; j < m; j++){
 						if(t[j] != '1')return 0;
 					}
 					return 1;
 				}
 				if(t[i] == '0')return 0;
 			}
 			return 0;
 		};
 		bool ans = (check(t));
 		reverse(all(t));
 		ans |= (check(t));
 		if(s.back() == '1'){
 			ans |= check(s);
 		}else{
 			string temp = s + "1";
 			ans |= check(temp);
 			reverse(all(temp));
 			ans |= check(temp);
 			ans |= (s == get(y));	
 		}
 		cout << (ans ? "YES":"NO") << endl;
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