// Never let them see you bleed...
// Shayan.P  2020-06-11

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e4 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[2][maxn], aft[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string a, b;
    cin >> a >> b;
    aft[sz(a)] = sz(a);
    for(int i = sz(a)-1; i >= 0; i--){
	if(a[i] == '.')
	    aft[i] = i;
	else if(aft[i+1] == sz(a))
	    aft[i] = sz(a);
	else
	    aft[i] = aft[aft[i+1]+1];
    }
    for(int i = sz(a)-1; i >= 0; i--){
	dp[sz(b) & 1][i] = 1 + dp[sz(b) & 1][i+1];
	if(a[i] != '.' && aft[i+1] != sz(a))
	    dp[sz(b) & 1][i] = min(dp[sz(b) & 1][i], dp[sz(b) & 1][aft[i+1]+1]);
    }
    for(int j = sz(b)-1; j >= 0; j--){
	int o = j & 1, O = 1-o;
	dp[o][sz(a)] = inf;
	for(int i = sz(a)-1; i >= 0; i--){
	    dp[o][i] = 1 + dp[o][i+1];
	    if(a[i] == b[j])
		dp[o][i] = min(dp[o][i], dp[O][i+1]);
	    if(a[i] != '.' && aft[i+1] != sz(a))
		dp[o][i] = min(dp[o][i], dp[o][aft[i+1]+1]);
	}
    }
    return cout << dp[0][0] << "\n", 0;
}