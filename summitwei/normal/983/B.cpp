#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n;
ll a[MN];
ll dp[MN][MN];
int q;
int l, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        dp[i][i] = a[i];
    }
    FOR(d, 1, n-1){
        FOR(i, 1, n){
            int j = i+d;
            if(j > n) continue;
            dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
        }
    }
    FOR(d, 1, n-1){
        FOR(i, 1, n){
            int j = i+d;
            if(j > n) continue;
            dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i+1][j]));
        }
    }

    cin >> q;
    F0R(_, q){
        cin >> l >> r;
        cout << dp[l][r] << "\n";
    }

    return 0;
}