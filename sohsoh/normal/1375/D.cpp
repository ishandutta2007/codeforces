/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], cnt[MAXN] = {0};

ll solve() {
    set<ll> mex;
    vector<ll> v, ans;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) mex.insert(i);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mex.erase(A[i]);
        cnt[A[i]]++;
        if (A[i] != i) v.push_back(i);
    }

    while (!v.empty()) {
        ll mx = *mex.lower_bound(0);

        if (mx == n) {
            ll i = v.front();
            cnt[A[i]]--;
            mex.insert(A[i]);
            mex.erase(n);
            A[i] = n;
            cnt[n]++;
            ans.push_back(i);
        }

        mx = *mex.lower_bound(0);
        cnt[A[mx]]--;
        if (cnt[A[mx]] == 0) mex.insert(A[mx]);
        A[mx] = mx;
        cnt[mx]++;
        mex.erase(mx);
        ans.push_back(mx);
        v.erase(find(all(v), mx));
    }


    for (int i = 0; i < n + 10; i++) cnt[i] = 0;

    cout << ans.size() << endl;
    for (ll e : ans) cout << e + 1 << sep;
    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}