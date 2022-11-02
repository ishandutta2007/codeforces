#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int K = 18;
const int N = (1 << K) + 228;
int k;
string s;
int ans[N];
int q;

void relaxPos(int i) {
    if (i * 2 + 1 >= s.size()) {
        if (s[i] == '?') {
            ans[i] = 2;
        } else {
            ans[i] = 1;
        }
    } else {
        if (s[i] == '?') {
            ans[i] = ans[i * 2 + 1] + ans[i * 2 + 2];
        } else if (s[i] == '0') {
            ans[i] = ans[i * 2 + 2];
        } else {
            ans[i] = ans[i * 2 + 1];
        }
    }
}

void init() {
    for (int i = s.size() - 1; i >= 0; --i) {
        relaxPos(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> k;
    cin >> s;
    reverse(all(s));
    init();
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        p = s.size() - 1 - p;
        s[p] = c;
        while (p) {
            relaxPos(p);
            --p;
            p /= 2;
        }
        relaxPos(p);
        // init();
        // cerr << "ans = " << endl;
        // for (int i = 0; i < (1 << k) - 1; ++i) {
        //     cerr << ans[i] << ' ';
        // }
        // cerr << endl;
        cout << ans[0] << '\n';
    }
    // cerr << "s = " << s << endl;
    return 0;
}