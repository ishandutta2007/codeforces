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

ll A[MAXN] = {0}, B[MAXN];

int main() {
    fast_io;
    ll n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') A[i] = 1;
        else A[i] = -1;
    }

    pll ans_helper;
    ll ans = 0, tmp = 0;
    for (int i = 0; i < n; i++) tmp += A[i];
    if (tmp != 0) return cout << 0 << endl << 1 << " " << 1 << endl, 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(A[i], A[j]);
            B[0] = A[0];
            for (int k = 1; k < n; k++) B[k] = B[k - 1] + A[k];
            ll mn = *min_element(B, B + n);
            ll t_ans = 0;
            for (int k = 0; k < n; k++) if (B[k] == mn) t_ans++;
            if (t_ans >= ans) {
                ans = t_ans;
                ans_helper = {i + 1, j + 1};
            }
            swap(A[i], A[j]);
        }
    }

    cout << ans << endl;
    cout << ans_helper.X << ' ' << ans_helper.Y << endl;
    return 0;
}