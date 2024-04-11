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

int col[1001];

int solve() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i] = col[k];
    }

    int m = *max_element(a, a + n);
    bool b = true;
    for (int i = 1; i <= m; i++) {
        if (find(a, a + n, i) == a + n) {
            for (int j = 0; j < n; j++) {
                if (a[j] >= i) a[j]--;
            }
            m--;
            i--;
        }
    }

    cout << m << endl;
    alog(a, n);
    return 0;
}

int main() {
    fast_io;
    int pr[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 0; i < 1001; i++) col[i] = 0;
    for (int c = 1; c <= 11; c++)
        for (int i = 1; i < 1001; i++)
            if (i % pr[c - 1] == 0) col[i] = c;

    int t; cin >> t;
    while (t--) solve();
    return 0;
}