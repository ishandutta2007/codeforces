#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;
const ll MOD = 998244353;

unordered_map<int, int> curr, prv;
int n, a[N];

int countOp(int x, int prev_min){
    return (x + prev_min - 1) / prev_min;
}

int nextMin(int x, int prev_min){
    return x / countOp(x, prev_min);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    curr.clear();
    prv.clear();
    ll ans = 0;
    for(int i = n - 1; i >= 0; --i){
        curr.clear();
        for(auto [x, cnt]: prv){
            // cout << countOp(a[i], x) << " a[i], x " << a[i] << ", " << x << endl;
            ans += (ll)cnt * (ll)(i + 1) * (countOp(a[i], x) - 1);
            ans %= MOD;
            curr[nextMin(a[i], x)] += cnt;
        }
        ++curr[a[i]];

        // cout << "curr[" << i << "]" << endl;
        // for(auto [x, cnt]: curr)
            // cout << x << " " << cnt << endl;

        swap(prv, curr);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}