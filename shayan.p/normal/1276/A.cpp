// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2e5 + 10, inf = 1e9;

int dp[maxn][5];
pair<bool, int> opt[maxn][5];
map< pair<int, char> , int > mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 5; i++){
	for(char ch = 'a'; ch <= 'z'; ch++){
	    if(i == 0 && ch == 'o')
		mp[{i, ch}] = 1;
	    else if(i == 0 && ch == 't')
		mp[{i, ch}] = 2;
	    else if(i == 1 && ch == 'n')
		mp[{i, ch}] = 3;
	    else if(i == 2 && ch == 'w')
		mp[{i, ch}] = 4;
	    else if(i == 3 && ch == 'e')
		mp[{i, ch}] = -1;
	    else if(i == 4 && ch == 'o')
		mp[{i, ch}] = -1;
	    else if(ch == 't')
		mp[{i, ch}] = 2;
	    else if(ch == 'o')
		mp[{i, ch}] = 1;
	    else
		mp[{i, ch}] = 0;
	}
    }
    
    int q; cin>>q;
    while(q--){
	string s; cin>>s;

	for(int i = 0; i <= sz(s); i++)
	    for(int j = 0; j < 5; j++)
		dp[i][j] = inf;
	dp[0][0] = 0;
	
	for(int i = 0; i < sz(s); i++){
	    char ch = s[i];
	    for(int j = 0; j < 5; j++){
		int num = mp[{j, ch}];
		if(num != -1){
		    if(dp[i+1][num] > dp[i][j])
			dp[i+1][num] = dp[i][j], opt[i+1][num] = { 0, j };		    
		}
		if(dp[i+1][j] > 1 + dp[i][j])
		    dp[i+1][j] = 1 + dp[i][j], opt[i+1][j] = { 1, j };
	    }
	}
	int ans = inf;
	int id = 0;
	for(int i = 0; i < 5; i++){
	    if(ans > dp[sz(s)][i])
		id = i, ans = dp[sz(s)][i];
	}

	vector<int> v;
	for(int i = sz(s); i>0; i--){
	    if(opt[i][id].F)
		v.PB(i);
	    id = opt[i][id].S;
	}
	cout << sz(v) <<"\n";
	for(int x : v)
	    cout << x<<" ";
	cout <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")