#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
#define MK 5005
ll n, k;
ll a[MN];

ll dp[MK][MK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    F0R(i, n){
        cin >> a[i];
    }
    sort(a, a+n);
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    //cout << dp[6][9] << "\n";

    ll ae = n/k; //amt elem, and ae+1 also works
    ll rem = n%k; //amt needed to go up one

    //cout << ae << " " << rem << "\n";

    F0R(i, k){
        F0R(j, rem){
            //cout << i << " " << j << " " << dp[i][j] << "\n";
            ll loc = i*ae+j;
            assert(loc+ae < n);
            ll res = dp[i][j] + a[loc+ae-1]-a[loc];
            dp[i+1][j] = min(dp[i+1][j], res);

            ll res2 = dp[i][j] + a[loc+ae]-a[loc];
            dp[i+1][j+1] = min(dp[i+1][j+1], res2);
        }
        ll res = dp[i][rem] + a[i*ae+rem+ae-1]-a[i*ae+rem];
        dp[i+1][rem] = min(dp[i+1][rem], res);
    }

    cout << dp[k][rem] << "\n";

    /*FOR(i, 0, k){
        FOR(j, 0, rem){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    return 0;
}