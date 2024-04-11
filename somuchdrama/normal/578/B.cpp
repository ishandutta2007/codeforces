#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5+2;
ll arr[MAXN], pref[MAXN], suf[MAXN];

int main() {    
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    int n, k;
    ll x;
    cin >> n >> k >> x;
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pref[i] = pref[i - 1] | arr[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i > 0; --i)
        suf[i] = suf[i + 1] | arr[i];

    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        ll cur = arr[i];
        for (int j = 0; j < k; ++j)
            cur *= x;
        mx = max(mx, pref[i - 1] | cur | suf[i + 1]);
    }

    cout << mx << '\n';
    
    return 0;
}