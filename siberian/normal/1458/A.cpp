#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n, m;
ll a[N];
ll b[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll ans[N];

void run() {
    ll nans = 0;
    for (int i = 1; i < n; ++i) {
        //cout << a[i] - a[0] << endl;
        nans = gcd(nans, a[i] - a[0]); 
    }
    //cout << "nans = " << nans << endl;
    for (int i = 0; i < m; ++i) {
        ans[i] = gcd(nans, a[0] + b[i]);
    }
}

void write() {
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}