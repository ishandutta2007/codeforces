#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
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

#define MN 13
#define MK 105
int n;
int q, m;
int w[MN];
int amt[1<<MN];
int dp[MN][1<<MN][MK]; //first k digits are good

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    RFOR(i, n-1, 0){
        cin >> w[i];
    }
    F0R(i, m){
        string s;
        cin >> s;
        int k = 0;
        F0R(j, n){
            k = k*2+s[j]-'0';
        }
        amt[k]++;
        dp[0][k][0]++;
    }
    F0R(i, n){
        F0R(j, 1<<n){
            F0R(k, 101){
                //if(dp[i][j][k] != 0) cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
                dp[i+1][j][min(101, k+w[i])] += dp[i][j][k];
                dp[i+1][j^(1<<i)][k] += dp[i][j][k];
            }
        }
    }
    F0R(_, q){
        string s; int k;
        cin >> s >> k;
        int res = 0;
        F0R(i, n) res = res*2+s[i]-'0';
        int sm = 0;
        F0R(i, k+1) sm += dp[n][res][i];
        cout << sm << "\n";
    }
    
    return 0;
}