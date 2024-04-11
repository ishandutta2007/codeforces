// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
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


const int B = 2000;
const int N = 2e5 + 5 + ((2e5)/B)*(2e5);
int mp[N];
const int shift = 2e5;
int solve(){
 		//int n; cin >> n;

 		string s; cin >> s;
 		int n = s.length();
 		vector<int> sum(n + 1);
 		vector<int> prev(n + 1);
 		for(int i = 1; i <= n; i++){
 			prev[i] = prev[i - 1];
 			sum[i] = sum[i - 1];
 			if(s[i - 1] == '1'){
 				prev[i] = i;
 				sum[i]++;
 			}
 		}
 		auto ones = [&](int l,int r){return sum[r] - sum[l - 1];};
 		auto zeroes = [&](int l,int r){return r - l + 1 - ones(l,r);};

 		long long ans = 0;
 		for(int i = 1; i <= n; i++){
 			int j = prev[i];
 			int cnt = B;
 			
 			while(j > 0 and cnt > 0){
 				int z = zeroes(j,i);
 				int o = ones(j,i);
 				int p = prev[j - 1];
 				int can = j - p - 1;
 				int r = (o - z%o)%o;
 				ans += can/o + (can % o >= r);
 				j = p;
 				cnt--;
 			}
 		}
 		// Count when ones > B

 		for(int k = 0; k*B <= n; k++){
 			int j = 0;
 			memset(mp,0,sizeof(mp));
 			for(int i = 1; i <= n; i++){
 				while(j <= n and sum[i] - sum[j] > B){
 					mp[k*sum[j] - j + shift]++;
 					j++;
 				}
 				int reqd = k*sum[i] - i + shift;
 				ans += mp[reqd];
 			}
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