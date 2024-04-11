#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int n, m;
string s, t;
ll dp1[MN][MN];
ll dp2[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;
    n = s.length(); m = t.length();
    //reverse(s.begin(), s.end());
    dp1[n][0] = 1;
    if(n == m) dp2[m][0] = 1;
    RFOR(i, n-1, 0){
        dp1[i][0] = 1; //unused
        dp1[i][0] += dp1[i+1][0]; //end and useless
        dp1[i][0] %= MOD;
        if(i == m){
            dp2[i][0] = dp1[i][0]; //unused, but rest are relevant
        } else if(i < m){
            if(s[i] == t[i])
                dp2[i][0] = dp2[i+1][0];
        }
        dp1[i][m] += dp1[i+1][m]; //front and useless
        dp1[i][m] %= MOD;
        FOR(j, 1, m){
            if(s[i] == t[j-1]){
                dp1[i][j] += dp1[i+1][j-1]; //match next
            }
            dp1[i][j] += dp1[i+1][j]; //stick at end
            dp1[i][j] %= MOD;

            if(j+i == m){
                dp2[i][j] = dp1[i][j]; //rest are relevant
            }
            if(j+i < m){
                int rt = m-(j+i);

                if(s[i] == t[j-1]){
                    dp2[i][j] += dp2[i+1][j-1]; //match at front
                }
                if(s[i] == t[i+j]){ //check if off by one
                    dp2[i][j] += dp2[i+1][j]; //match at end
                }
                dp2[i][j] %= MOD;
            }
        }
    }
    /*F0R(i, n){
        F0R(j, m+1){
            cout << dp1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    F0R(i, n){
        F0R(j, m+1){
            cout << dp2[i][j] << " ";
        }
        cout << "\n";
    }*/
    ll ans = 0;
    FOR(i, 0, m){
        ans += dp2[0][i];
        ans %= MOD;
    }
    cout << ans << "\n";
    
    return 0;
}