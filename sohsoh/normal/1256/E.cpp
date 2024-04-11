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

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, dp[MAXN], dp_helper[MAXN], a[MAXN], ind[MAXN], ans[MAXN], ans2[MAXN];

bool cmp(ll i, ll j) {
    return a[i] < a[j];
}

int main() {
    fast_io;
    dp[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[i] = i;
    }

    sort(ind + 1, ind + n + 1, cmp);
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) dp[i] = INF;

    for (int i = 0; i <= n; i++) {
        if (i > 2 && dp[i - 3] + a[i] - a[i - 2] < dp[i]) {
            dp[i] = dp[i - 3] + a[i] - a[i - 2];
            dp_helper[i] = 3;
        }

        if (i > 3 && dp[i - 4] + a[i] - a[i - 3] < dp[i]) {
            dp[i] = dp[i - 4] + a[i] - a[i - 3];
            dp_helper[i] = 4;
        }

        if (i > 4 && dp[i - 5] + a[i] - a[i - 4] < dp[i]) {
            dp[i] = dp[i - 5] + a[i] - a[i - 4];
            dp_helper[i] = 5;
        }
    }

    cout << dp[n] << sep;
    ll t = 1;
    for (int i = n; i > 0; ) {
        for (int j = 0; j < dp_helper[i]; j++) {
            ans[i - j] = t;
        }

        t++;
        i -= dp_helper[i];
    }

    cout << *max_element(ans + 1, ans + 1 + n) << endl;

    for (int i = 1; i <= n; i++) {
        ans2[ind[i]] = ans[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans2[i] << sep;
    }
    cout << endl;
    return 0;
}