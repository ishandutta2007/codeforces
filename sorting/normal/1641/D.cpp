#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 1e5 + 3;
const ll M = 5 + 3;
const ll INF = 1e18 + 7;

const ll MX = 14;
const ll STATES = (1 << MX) + 3;

ll n, m;
ll a[N][M], w[N];
bool ok[N];

vector<ll> v[STATES];
vector<ll> nums;

ll min_w[STATES], val[N * M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cin >> a[i][j];
            nums.push_back(a[i][j]);
        }
        cin >> w[i];
    }

    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j)
            a[i][j] = lower_bound(all(nums), a[i][j]) - nums.begin();

    ll ans = 2 * INF;
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

    for(ll iter = 0; iter < 268; ++iter){
        ll x;
        for(ll i = 0; i < nums.size(); ++i)
            val[i] = mt() % MX;
        
        fill(min_w, min_w + (1 << MX), INF);
        for(ll i = 1; i <= n; ++i){
            ll state = 0;
            for(ll j = 1; j <= m; ++j)
                state |= 1 << val[a[i][j]];
            check_min(min_w[state], w[i]);
        }

        for(ll i = 0; i < (1 << MX); ++i){
            for(ll j = 0; j < MX; ++j){
                if(!(i & (1 << j))) continue;
                ll t  = i ^ (1 << j);
                check_min(min_w[i], min_w[t]); 
            }
        }

        for(ll i = 0; i < (1 << MX); ++i)
            check_min(ans, min_w[i] + min_w[(1 << MX) - 1 - i]);
    }

    if(ans >= INF) ans = -1;
    cout << ans << "\n";
}