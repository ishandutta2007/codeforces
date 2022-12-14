#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, a[N];
ll s[N], k;
int ft[N];
ll all[N];

int gt(int x) {
    int res = 0;
    for (int i = x; i >= 0; i &= i + 1, --i)
        res += ft[i];
    return res;
}

void upd(int x, int v) {
    for (int i = x; i < N; i |= i + 1)
        ft[i] += v;
}

ll chk(ll x) {
    memset(ft, 0, sizeof ft);
    FOR(i, 0, n) all[i] = s[i];
    sort(all, all + n + 1);
    upd(lower_bound(all, all + n + 1, s[0]) - all, +1);
    ll res = 0;
    FOR(i, 1, n) {
        res += gt(upper_bound(all, all + n + 1, s[i] - x) - all - 1);
        upd(lower_bound(all, all + n + 1, s[i]) - all, +1);
    }
    return res;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    ll l = -1e14, r = 1e14, rs = 0;
//    cout << chk(10) << endl;
//    return 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (chk(m) >= k) {
            l = m + 1;
            rs = m;
        } else {
            r = m - 1;
        }
    }
    cout << rs << endl;
    return 0;
}