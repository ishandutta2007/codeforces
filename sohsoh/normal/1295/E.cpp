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
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll tree[MAXN], lz[MAXN] = {0}, A[MAXN], B[MAXN], pos[MAXN], n;

void Update(ll si, ll ss, ll se, ll us, ll ue, ll diff) {
    if (lz[si] != 0) {
        tree[si] += lz[si];
        if (ss != se) {
            lz[si * 2 + 1] += lz[si];
            lz[si * 2 + 2] += lz[si];
        }

        lz[si] = 0;
    }

    if (ss > se || ss > ue || se < us) return;

    if (ss >= us && se <= ue) {
        tree[si] += diff;
        if (ss != se) {
            lz[si * 2 + 1] += diff;
            lz[si * 2 + 2] += diff;
        }

        return;
    }

    ll mid = (ss + se) / 2;
    Update(si * 2 + 1, ss, mid, us, ue, diff);
    Update(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = min(tree[si * 2 + 1], tree[si * 2 + 2]);
}

ll RMQ(ll ss, ll se, ll qs, ll qe, ll si) {
    if (lz[si] != 0) {
        tree[si] += lz[si];
        if (ss != se) {
            lz[si * 2 + 1] += lz[si];
            lz[si * 2 + 2] += lz[si];
        }

        lz[si] = 0;
    }

    if (ss > se || ss > qe || se < qs) return INF;
    if (ss >= qs && se <= qe) return tree[si];

    ll mid = (ss + se) / 2;
    return min(RMQ(ss, mid, qs, qe, 2 * si + 1), RMQ(mid + 1, se, qs, qe, 2 * si + 2));
}

int main() {
    fast_io;
    ll ts = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i], pos[A[i]] = i;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        ts += B[i];
        Update(0, 0, n - 1, i, i, ts);
    }

    ll ans = B[0];
    for (int i = 1; i <= n; i++) {
        ll p = pos[i];
        Update(0, 0, n - 1, p, n - 1, -1 * B[p]);
        if (p > 0) Update(0, 0, n - 1, 0, p - 1, B[p]);
        ans = min(ans, RMQ(0, n - 1, 0, n - 2, 0));
    }

    cout << ans << endl;
    return 0;
}