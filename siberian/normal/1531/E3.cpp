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

const int N = 100001;
int dpMin[N], dpMax[N];

void initDp() {
    dpMax[0] = dpMax[1] = dpMin[0] = dpMin[1] = 0;
    for (int len = 2; len < N; ++len) {
        dpMin[len] = dpMin[len / 2] + dpMin[(len + 1) / 2] + len / 2;
        dpMax[len] = dpMax[len / 2] + dpMax[(len + 1) / 2] + len - 1;
    }
}

string s;
int a[N], b[N], p[N], ptr;
bool ok;

void checkMergeSort(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    checkMergeSort(l, m);
    if (!ok) return;
    checkMergeSort(m, r);
    if (!ok) return;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (ptr == s.size()) {
            ok = false;
            return;
        }
        if (s[ptr] == '0') {
            i += 1;
        } else {
            j += 1;
        }
        k += 1;
        ++ptr;
    }
}

void mergeSort(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    mergeSort(l, m);
    if (!ok) return;
    mergeSort(m, r);
    if (!ok) return;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (ptr == s.size()) {
            ok = false;
            return;
        }
        if (s[ptr] == '0') {
            b[k] = a[i];
            i += 1;
        } else {
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

int check(int len) {
    ptr = 0;
    ok = true;
    checkMergeSort(0, len);
    if (!ok) return 1;
    if (ptr != s.size()) return -1;
    iota(a, a + len, 0);
    ptr = 0;
    ok = true;
    mergeSort(0, len);
    for (int i = 0; i < len; ++i) {
        p[a[i]] = i;
    }
    cout << len << '\n';
    for (int i = 0; i < len; ++i) {
        cout << p[i] + 1 << ' ';
    }
    cout << '\n';
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
    L--;
    chkmax(L, 0);
    R++;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(M) == -1) {
            L = M;
        } else {
            R = M;
        }
    }
    assert(false);
    return 0;
}