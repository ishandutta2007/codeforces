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

const int N = 1e5 + 10;
int n;
int p[N];

int myLen[N];

int pref[N];
int suff[N];

int myL[N];
int myR[N];

void build() {
    for (int i = 0; i < n; ++i) {
        myL[i] = 0;
        if (i > 0 && p[i - 1] < p[i]) chkmax(myL[i], myL[i - 1] + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        myR[i] = 0;
        if (i + 1 < n && p[i + 1] < p[i]) chkmax(myR[i], myR[i + 1] + 1);
    }
    for (int i = 0; i < n; ++i) {
        myLen[i] = max(myL[i], myR[i]);
    }
    for (int i = 0; i < n; ++i) {
        pref[i] = myLen[i];
        if (i > 0) chkmax(pref[i], pref[i - 1]);
    }
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = myLen[i];
        if (i + 1 < n) chkmax(suff[i], suff[i + 1]);
    }
    // cerr << "myLen = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << myLen[i] << " ";
    // }
    // cerr << endl;
    // cerr << "pref = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << pref[i] << " ";
    // }
    // cerr << endl;
    // cerr << "suff = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << suff[i] << " ";
    // }
    // cerr << endl;
}

int getMax(int l, int r) {
    int ans = 0;
    if (l >= 0) chkmax(ans, pref[l]);
    if (r < n) chkmax(ans, suff[r]);
    return ans;
}

bool check(int pos) {
    // int L = pos - 1;
    // while (L >= 0 && p[L] < p[L + 1]) --L;
    // if (L == pos - 1) return false;
    // int R = pos + 1;
    // while (R < n && p[R] < p[R - 1]) ++R;
    // if (R == pos + 1) return false;
    // cerr << "L = " << L << " R = " << R << endl;
    // int lenL = pos - L - 1;
    // int lenR = R - pos - 1;
    // cerr << "lenL = " << lenL << " lenR = " << lenR << endl;
    int lenL = myL[pos];
    int lenR = myR[pos];
    if (lenL == 0 || lenR == 0) return false;
    if (lenL != lenR) return false;
    if (lenL % 2 != 0) return false;
    int mxLen = getMax(pos - lenL - 1, pos + lenR + 1);
    if (mxLen >= lenL) return false;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int ans = 0;
    build();
    // cerr << "check(2) = " << check(2) << endl;
    // cerr << check(2) << endl;
    // exit(0);
    for (int i = 1; i + 1 < n; ++i) {
        if (check(i)) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}