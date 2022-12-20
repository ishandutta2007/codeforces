// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[maxn][2][2];
int A[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;	
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
	    A[i] = s[i] == 'R';
	}
	int ans = inf;
	for(int a : {0, 1}){
	    for(int b : {0, 1}){
		for(int i = 0; i < n; i++){
		    for(int x : {0, 1})
			for(int y : {0, 1})
			    dp[i][x][y] = inf; 
		}
		dp[1][a][b] = (A[0] != a) + (A[1] != b);
		for(int i = 1; i < n-1; i++){
		    for(int x : {0, 1}){
			for(int y : {0, 1}){
			    for(int z : {0, 1}){
				if(x == y && y == z)
				    continue;
				dp[i+1][y][z] = min(dp[i+1][y][z], dp[i][x][y] + (z != A[i+1]));
			    }
			}
		    }
		}
		for(int x : {0, 1}){
		    for(int y : {0, 1}){
			if(a == b && y == a)
			    continue;
			if(x == y && y == a)
			    continue;
			ans = min(ans, dp[n-1][x][y]);
		    }
		}
	    }
	}
	cout << ans << "\n";
    }
}