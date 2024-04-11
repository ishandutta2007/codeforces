/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_perm(int* a, int n) {
    bool* b = new bool[n + 1];
    forr(n + 1) b[i] = false;
    for (int i = 0; i < n; i++) {
        if (a[i] > n) return false;
        if (b[a[i]]) return false;
        b[a[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!b[i]) return false;
    }

    return true;
}

int solve() {
    int n;
    cin >> n;
    int* a;
    a = new int[n];
    int* b = new int[n + 1];
    forr(n + 1) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > n) return cout << 0 << endl, 0;
        b[a[i]]++;
    }

    int l1 = 0, l2 = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 2) return cout << 0 << endl, 0;
        if (b[i] == 2) {
            l1++;
        } else {
            break;
        }
    }

    l2 = n - l1;

    bool bb[2] = {false, false};
    if (is_perm(a, l1) && is_perm(a + l1, l2)) bb[0] = true;

    swap(l1, l2);
    if (is_perm(a, l1) && is_perm(a + l1, l2)) bb[1] = true;

    if (l1 == l2 && bb[0]) return cout << 1 << endl << l1 << sep << l2 << endl, 0;

    cout << bb[0] + bb[1] << endl;

    if (bb[0]) cout << l2 << sep << l1 << endl;
    if (bb[1]) cout << l1 << sep << l2 << endl;
    return 0;
}

int main() {
    fast_io;
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}