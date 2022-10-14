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
 		int n;int k; cin >> n >> k;
 		string s; cin >> s;
 		int rot = 0;
 		if(s[0] != s[n - 1]){
 			bool flag = 0;
 			int j = -1;
 			for(int i = 1; i < n; i++){
 				if(s[i] == s[i - 1]){
 					flag = 1;
 					j = i;
 				}
 			}
 			if(!flag){
 				k = k%2;
 				if(k){
 					for(auto &i:s)i = i^'W'^'B';
 				}
 				cout << s << endl;
 				return 0;
 			}
 			// j - 1,j have some color
 			// rotate string left by j units
 			rot = j;
 			string t = s;
 			for(int i = 0; i < n; i++){
 				int l = ((i - j)%n + n)%n;
 				t[l] = s[i];
 			}
 			s = t;
 		}
 		assert(s[0] == s[n - 1]);
 		// find all alteranting sequences
 		vector<int> temp;
 		char st = s[0];

 		auto solve = [&](char st,char bk){
 			if(temp.empty())return;
 			int mx = sz(temp)/2 + (sz(temp) % 2 != 0);
 			mins(mx,k);
 			for(int i = 0; i < mx; i++)s[temp[i]] = st;
 			reverse(all(temp));
 			for(int i = 0; i < mx; i++)s[temp[i]] = bk;
 			int kk = k%2;
 			reverse(all(temp));
 			for(int i = mx; i < sz(temp) - mx; i++){
 				if(kk){
 					s[temp[i]] ^= 'W'^'B';
 				}
 			}

 		};	

 		for(int i = 1; i < n ; i++){
 			if(s[i] == s[i - 1]){
 				if(temp.empty()){
 					st = s[i];
 					continue;
 				}
 				char bk = s[i];
 				temp.pop_back();
 				solve(st,bk);
 				temp.clear();
 				st = s[i];
 			}else{
 				temp.push_back(i);
 			}
 		}
 		if(temp.size())temp.pop_back();
 		solve(st,s[n - 1]);
 		string t = s;
 		for(int i = 0; i < n; i++){
 			int l = ((i + rot)%n + n)%n;
 			t[l] = s[i];
 		}
 		cout << t << endl;
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