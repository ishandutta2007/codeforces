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
 		string s; cin >> s;
 		vector<int> vec(26);
 		int k; cin >> k;
 		while(k--){
 			char x; cin >> x;
 			vec[x - 97] = 1;
 		}
 		int cnt = 0;
 		for(auto &i:s){
 			i = vec[i - 97] + '0';
 			if(i == '1')cnt++;
 		}
 		//cout << s << endl;
 		int j = 0;
 		while(j < n and s[j] == '0')j++;
 		if(j == n){
 			cout << 0 << endl;
 			return 0;
 		}
 		if(cnt == n){
 			cout << 1 << endl;
 			return 0;
 		}
 		if(cnt == 1){
 			cout << j << endl;
 			return 0;
 		}


 		int i = 0;
 		int ans = 0;
 		int prev_time = 0;
 		int ones = 0;
 		
 		while(i < n){
 			if(s[i] == '1'){
 				maxs(prev_time,1);
 				ones++;
 				i++;
 				continue;
 			}
 			int j = i;
 			while(j < n and s[j] == '0')j++;
 			if(j < n){
 				int now = j - i;
 				if(now >= prev_time){
 					prev_time = now + (ones > 0);
 				}
 			}
 			i = j;
 		}
 		cout << prev_time << endl;


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