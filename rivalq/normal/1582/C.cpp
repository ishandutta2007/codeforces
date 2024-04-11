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

bool ispalindrome(string s){
    string t=s;
    reverse(all(s));
    return t==s;
}
const int N = 1e5 + 5;

int pre[N][26];

int solve(){
 		int n; cin >> n; string s; cin >> s;
 		int mn = n + 1;


 		for(int i = 1; i <= n; i++){
 			for(int j = 0; j < 26; j++){
 				pre[i][j] = pre[i - 1][j];
 			}
 			pre[i][s[i - 1] - 97]++;
 		}

 		auto sum = [&](char c,int l,int r){
 			if(l > r)return 0LL;
 			return pre[r][c - 97] - pre[l - 1][c - 97];
 		};


 		for(char a = 'a'; a <= 'z'; a++){
 			string t; 
 			vector<int> v;
 			int L = 0, R = n + 1;
 			int cnt = 0;
 			for(int i = 0; i < n; i++){
 				if(s[i] != a){
 					cnt++;
 					v.push_back(i + 1);
 					t.push_back(s[i]);
 				}
 			}
 			if(ispalindrome(t)){
 				if(v.empty()){
 					cout << 0 << endl;
 					return 0;
 				}
 				int l = 0, r = v.size();r--;
 				while(l <= r){
 					int mn1 = sum(a,L + 1,v[l] - 1);
 					int mn2 = sum(a,v[r] + 1,R - 1);
 					cnt += 2*min(mn1,mn2);
 					if(l == r)break;
 					L = v[l++];
 					R = v[r--];
 				}
 				if(sz(v) % 2 == 0){
 					int m = sz(v);
 					int r = v[m/2];
 					int l = v[m/2 - 1];
 					cnt += sum(a,l + 1,r - 1);
 				}
 				mins(mn,n - cnt);
 			}
 		}
 		if(mn >= n)mn = -1;
 		cout << mn << endl;
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