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
int dpMin[N], dpMax[N];

void initDp() {
    dpMax[0] = dpMax[1] = dpMin[0] = dpMin[1] = 0;
    for (int len = 2; len < N; ++len) {
        dpMin[len] = dpMin[len / 2] + dpMin[(len + 1) / 2] + len / 2;
        dpMax[len] = dpMax[len / 2] + dpMax[(len + 1) / 2] + len - 1;
    }
}

string s;

void mergeSort(int l, int r, vector<int>& a, vector<int>& b, int& ptr, bool& ok) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    mergeSort(l, m, a, b, ptr, ok);
    if (!ok) return;
    mergeSort(m, r, a, b, ptr, ok);
    if (!ok) return;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (ptr == s.size()) {
            ok = false;
            return;
        }
        if (/*a[i] < a[j]*/s[ptr] == '0') {
            // log += '0';
            b[k] = a[i];
            i += 1;
        } else {
            // log += '1';
            b[k] = a[j];
            j += 1;
        }
        k += 1;
        ++ptr;
    }
    while (i < m) {
        b[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < r) {
        b[k] = a[j];
        j += 1;
        k += 1;
    }
    for (int p = l; p < r; ++p) {
        a[p] = b[p];
    }
}

void mergeSort(int l, int r, vector<int>& a, vector<int>& b, string& log) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    mergeSort(l, m, a, b, log);
    mergeSort(m, r, a, b, log);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] < a[j]) {
            log += '0';
            b[k] = a[i];
            i += 1;
        } else {
            log += '1';
            b[k] = a[j];
            j += 1;
        }
        k += 1;
    }
    while (i < m) {
        b[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < r) {
        b[k] = a[j];
        j += 1;
        k += 1;
    }
    for (int p = l; p < r; ++p) {
        a[p] = b[p];
    }
}

int check(int len) {
    vector<int> ans(len);
    iota(all(ans), 0);
    vector<int> b(len);
    int ptr = 0;
    bool ok = true;
    mergeSort(0, len, ans, b, ptr, ok);
    if (!ok) return 1;
    if (ptr != s.size()) return -1;
    vector<int> p(len);
    for (int i = 0; i < len; ++i) {
        p[ans[i]] = i;
    }
    cout << len << '\n';
    for (auto i : p) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    
    string log = "";
    mergeSort(0, len, p, b, log);
    assert(log == s);
    // return 0;
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    initDp();
    cin >> s;
    int L = 0;
    while (dpMax[L] < s.size()) ++L;
    int R = N - 1;
    while (dpMin[R] > s.size()) --R;
    // cerr << "R - L = " << R - L << endl;
    // for (int len = L; ; ++len) {
    //     cerr << check(len);
    // }
    L -= 5;
    chkmax(L, 0);
    R += 5;
    while (L < R - 10) {
        int M = (L + R) / 2;
        if (check(M) == -1) {
            L = M;
        } else {
            R = M;
        }
    }
    for (int i = L; i <= R; ++i) {
        check(i);
    }
    assert(false);
    // for (int len = 1; len < N; len *= 2) {
    //     check(len);
    // }
    // assert(false);
    return 0;
}