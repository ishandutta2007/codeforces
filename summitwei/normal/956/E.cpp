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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 10005
int n, l, r;
pii ree[MN];
//map<pii, int> bxs;
int dp[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int lp, rp;
    cin >> n >> lp >> rp;
    int sm = 0;
    F0R(i, n){
        int x;
        cin >> x; ree[i].s = -x;
        sm += x;
    }
    l = sm-rp; r=sm-lp;
    F0R(i, n){
        cin >> ree[i].f;
    }

    sort(ree, ree+n);
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;

    F0R(i, n){
        RFOR(j, sm, -ree[i].s){
            dp[j] = max(dp[j], dp[j+ree[i].s]+ree[i].f*(j >= l && j <= r));
        }
    }
    int ans = 0;
    FOR(i, 0, sm){
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

    return 0;
}