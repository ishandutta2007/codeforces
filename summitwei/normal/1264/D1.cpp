#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pll> vpll;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
string s;
int n;
int ps[MN];
ll pows[MN];
ll dp[MN][MN];

ll calc(int l, int r){
    if(r <= l) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;

    if(s[l] != '('){
        dp[l][r] = (dp[l][r]+calc(l+1, r))%MOD;
    }
    if(s[r] != ')'){
        dp[l][r] = (dp[l][r]+calc(l, r-1))%MOD;
    }
    if(s[l] != '(' && s[r] != ')'){
        dp[l][r] = (dp[l][r]-calc(l+1, r-1)+MOD)%MOD;
    }
    if(s[l] != ')' && s[r] != '('){
        //cout << l << " " << r << " " << ps[r-1] << " " << ps[l] << " " << pows[ps[r-1]-ps[l]] << "\n";
        ll nw = calc(l+1, r-1)+pows[ps[r-1]-ps[l]];
        dp[l][r] = (dp[l][r]+nw)%MOD;
    }
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> s;
    n = s.length();
    ps[0] = s[0]=='?' ? 1 : 0;
    pows[0] = 1;
    FOR(i, 1, n-1){
        ps[i] = ps[i-1]+(s[i]=='?' ? 1 : 0);
        pows[i] = (pows[i-1]*2)%MOD;
    }

    cout << calc(0, n-1) << "\n";
    /*F0R(i, n){
        F0R(j, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    return 0;
}