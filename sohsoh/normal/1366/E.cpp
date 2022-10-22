/*
    Soheil Mohammadkhani
    3 points remained to candidate master bro :)
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

const ll MAXN = 1e6 + 10; //Change this pls :)
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll n, m, A[MAXN], B[MAXN];
vector<ll> seg;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < m; j++) cin >> B[j];

    reverse(A, A + n);
    reverse(B, B + m);

    ll ind = 0;
    ll seg_len = 0;
//    ll tmp = 0;
    bool found = false, b = false;
    for (int i = 0; i < n; i++) {
        if (A[i] < B[ind]) {
            seg.push_back(seg_len);
            seg_len = 0;
            ind++;

            if (ind >= m || A[i] < B[ind]) return cout << "0" << endl, 0;
            found = false;
        }

        if (ind + 1 == m && A[i] == B[ind]) b = true;

        if (A[i] == B[ind] && !found && ind < m) found = true;


        if (A[i] >= B[ind] && found && ind < m) seg_len++;
    }

    if (ind >= m || !b) return cout << 0 << endl, 0;

    ll ans = 1;
    for (ll e : seg) {
        ans *= e;
        ans %= MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}