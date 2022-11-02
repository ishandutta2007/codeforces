#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 505
int n;
string s;

int dp[MN][MN];

int calc(int i, int j){
    if(dp[i][j] != 0) return dp[i][j];
    
    if(i == j) return 1;
    if(i > j) return 0;
    int res = INF;
    
    res = min(res, 1+calc(i+1, j));
    FOR(k, i+1, j){
        if(s[i] == s[k]){
            res = min(res, calc(i+1, k-1)+calc(k, j));
        }
    }
    
    dp[i][j] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    
    cout << calc(0, n-1) << "\n";
    
    return 0;
}