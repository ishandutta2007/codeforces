#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

// const int N = 1e5 + 10;
int n, q;

string s;

int calc(int pos) {
    if (pos < 0 || pos + 2 >= n) return 0;
    return s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c'; 
}

int cur = 0;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        cur += calc(i);
    }
    const int B = 5;
    while (q--) {
        int pos;
        char x;
        cin >> pos >> x;
        --pos;
        for (int i = pos - B; i <= pos + B; ++i) {
            cur -= calc(i);
        }
        s[pos] = x;
        for (int i = pos - B; i <= pos + B; ++i) {
            cur += calc(i);
        }
        cout << cur << '\n';
    }
    return 0;
}