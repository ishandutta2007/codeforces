#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n, m;
ll a[MN], b[MN];
ll res[MN];
ll res2[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(res, 0x3f, sizeof res);
    memset(res2, 0x3f, sizeof res2);

    cin >> n >> m;
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, m) cin >> b[i];
    ll x; cin >> x;
    F0R(i, n){
        ll sm = a[i];
        res[1] = min(res[1], sm);
        FOR(j, i+1, n-1){
            sm += a[j];
            res[j-i+1] = min(res[j-i+1], sm);
        }
    }
    RFOR(i, n-1, 1){
        res[i] = min(res[i], res[i+1]);
    }
    F0R(i, m){
        ll sm = b[i];
        res2[1] = min(res2[1], sm);
        FOR(j, i+1, m-1){
            sm += b[j];
            res2[j-i+1] = min(res2[j-i+1], sm);
        }
    }
    RFOR(i, m-1, 1){
        res2[i] = min(res2[i], res2[i+1]);
    }
    /*FOR(i, 1, n) cout << res[i] << " ";
    cout << "\n";
    FOR(i, 1, n) cout << */
    int ans = 0;
    int j = m;
    FOR(i, 1, n){
        while(j >= 1 && res[i]*res2[j] > x) --j;
        ans = max(ans, i*j);
    }
    cout << ans << "\n";
    
    return 0;
}