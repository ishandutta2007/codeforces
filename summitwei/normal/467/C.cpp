#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n, m, k;
ll p[MN];
ll ps[MN];
ll dp[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n){
        cin >> p[i];
        ps[i] = ps[i-1]+p[i];
    }
    FOR(i, 1, n){
        FOR(j, 1, k){
            dp[i][j] = dp[i-1][j];
            if(i >= m){
                dp[i][j] = max(dp[i][j], dp[i-m][j-1]+ps[i]-ps[i-m]);
            }
        }
    }
    cout << dp[n][k] << "\n";

    return 0;
}