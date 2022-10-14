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

		vector<string> s(2);
		for(auto &i:s)cin >> i;
		while(n > 0 and s[0][n - 1] == '.' and s[1][n - 1] == '.'){
			s[0].pop_back();
			s[1].pop_back();
			n--;
		}
		reverse(all(s[0]));
		reverse(all(s[1]));
		while(n > 0 and s[0][n - 1] == '.' and s[1][n - 1] == '.'){
			s[0].pop_back();
			s[1].pop_back();
			n--;
		}
		vector<vector<int>>dp(n + 1,vector<int>(2,-1));

		function<int(int,int)> dfs = [&](int i,int j){
			if(i == n)return 0LL;
			if(dp[i][j] != -1)return dp[i][j];
			int &ans = dp[i][j];
			ans = 2*n;

			if(s[0][i] == '*' and s[1][i] == '*'){
				mins(ans,min(2 + dfs(i + 1,j),2 + dfs(i + 1,j ^ 1)));
			}else if(s[j][i] == '*'){
				mins(ans,min(1 + dfs(i + 1,j),2 + dfs(i + 1,j^1)));
			}else if(s[j^1][i] == '*'){
				mins(ans,min(2 + dfs(i + 1,j^1),2 + dfs(i + 1,j)));
			}else{
				mins(ans,min(1 + dfs(i + 1,j),2 + dfs(i + 1,j^1)));
			}
			return ans;

		};

		if(s[0][0] == '*' and s[1][0] == '*'){
			cout << 1 + min(dfs(1,0) , dfs(1,1)) << endl;
		}else if(s[0][0] == '*'){
			cout << min(dfs(1,0),dfs(1,1) + 1) << endl;
		}else{
			cout << min(dfs(1,0) + 1,dfs(1,1)) << endl;
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