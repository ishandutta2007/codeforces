#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000LL
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

#define MN 505 //at some point should probably do hungarian but screw hungarian
int n;
struct O{
    ll a, b, k;
};
bool comp(O a, O b){
    return a.b > b.b;
}

O offs[MN];
ll dp[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        cin >> offs[i].a >> offs[i].b >> offs[i].k;
    }

    ll mx = 0;

    sort(offs+1, offs+n+1, comp);

    FOR(i, 1, n){
        dp[i][0] = dp[i-1][0] + max(0LL, offs[i].a-offs[i].b*offs[i].k);
        FOR(j, 1, n){
            dp[i][j] = max(dp[i-1][j], max(dp[i-1][j]+offs[i].a-offs[i].b*offs[i].k, dp[i-1][j-1]+offs[i].a-offs[i].b*(j-1)));
            mx = max(mx, dp[i][j]);
        }
    }
    
    cout << mx << "\n";

    return 0;
}