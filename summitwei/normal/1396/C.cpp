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

#define MN 1000005
int n;
ll r1, r2, r3, d;
ll a[MN];
ll t1[MN], t2[MN];
ll dp[MN]; //destroy 1...i
ll back[MN]; //destroy i...n going right and back
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> r2 >> r3 >> d;
    FOR(i, 1, n){
        cin >> a[i];
        t2[i] = min(r2, r1*a[i]+min(r1, r3-r1)); //if you use r3 now you save an r1 later
        t1[i] = min(r1*a[i]+r3, t2[i]+2*d+r1);
        //cout << t1[i] << " " << t2[i] << "\n";
    }
    dp[0] = -d;
    FOR(i, 1, n){
        dp[i] = dp[i-1]+d+t1[i];
        if(i>=2){
            dp[i] = min(dp[i], dp[i-2]+d+t2[i-1]+d+t2[i]+d+r1+d+r1);
        }
    }
    back[n] = t1[n];
    RFOR(i, n-1, 1){
        back[i] = t2[i]+d+back[i+1]+d+r1;
    }
    ll ans = back[1];
    FOR(i, 1, n-1){
        ans = min(ans, dp[i]+d+back[i+1]);
    }
    ans = min(ans, dp[n]);
    cout << ans << "\n";
    /*FOR(i, 1, n){
        cout << dp[i] << " ";
    }
    cout << "\n";
    FOR(i, 1, n){
        cout << back[i] << " ";
    }
    cout << "\n";*/

    return 0;
}