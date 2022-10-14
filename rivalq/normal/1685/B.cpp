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
 		int a,b,c,d; cin >> a >> b >> c >> d;

 		string s; cin >> s;
 		int cnt_a = 0, cnt_b = 0;
 		for(auto i:s){
 			if(i == 'A')cnt_a++;
 			else cnt_b++;
 		}
 		if(cnt_a != a + c + d){
 			cout << "NO" << endl;
 			return 0;
 		}
 		int i = 0;
 		int n = s.length();
 		int buffer = 0;
 		vector<pii> vec;
 		int rem = 0;
 		while(i < n){
 			int j = i;
 			while(j < n){
 				if(i % 2 == j % 2 and s[i] != s[j])break;
 				if(i % 2 != j % 2 and s[i] == s[j])break;
 				j++;
 			}
 			int l = j - i;
 			if(l % 2)buffer += l / 2;
 			else vec.push_back({l / 2,s[i] - 'A'}),rem += (l / 2) - 1;
 			i = j;
 		}
 		sort(all(vec));

 		for(int i = 0; i < vec.size(); i++){
 			if(buffer + rem >= c + d){
 				cout << "YES" << endl;
 				return 0;
 			}
 			auto [l,t] = vec[i];
 			if(t == 0){
 				if(c >= l) c -= l, rem -= (l - 1);
 			}else{
 				if(d >= l) d -= l, rem -= (l - 1);
 			}
 		}
 		if(buffer + rem >= c + d){
 			cout << "YES" << endl;
 			return 0;
 		}
 		cout << "NO" << endl;


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