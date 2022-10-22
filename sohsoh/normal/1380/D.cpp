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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], B[MAXN], n, m, x, y, k;
pll C[MAXN];

int main() {
    fast_io;
    cin >> n >> m >> x >> k >> y;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    ll p = 0, cnt = 0, fire = 0;
    C[0] = {-1, 0};
    for (int i = 0; i < n; i++) if (A[i] == B[p]) C[++p] = {i, A[i]};
    if (p < m) return cout << -1 << endl, 0;
    C[m + 1] = {n, 0};

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        if (C[i].X == C[i + 1].X - 1) continue;
        ll mx = *max_element(A + C[i].X + 1, A + C[i + 1].X), len = C[i + 1].X - C[i].X - 1;
        if (mx > C[i].Y && mx > C[i + 1].Y && len < k) return cout << -1 << endl, 0;
        else if (mx > C[i].Y && mx > C[i + 1].Y) ans += x, len -= k;
        ans += min((len / k) * x + (len % k) * y, len * y);
    }

    cout << ans << endl;
    return 0;
}