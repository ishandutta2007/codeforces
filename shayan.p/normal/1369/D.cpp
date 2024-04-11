// Never let them see you bleed...
// Shayan.P  2020-06-30

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 2; i < maxn; i++){
	dp[i] = ((1ll * dp[i-1] + 2ll * dp[i-2]) + (i % 3 == 2 ? 4 : 0)) % mod;
    }
    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	cout << dp[n-1] << "\n";
    }
    return 0;
}