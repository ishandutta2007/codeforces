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

void check(int len) {
    vector<int> ans(len);
    iota(all(ans), 0);
    vector<int> b(len);
    int ptr = 0;
    bool ok = true;
    mergeSort(0, len, ans, b, ptr, ok);
    if (!ok) return;
    if (ptr != s.size()) return;
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
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> s;
    for (int len = 1; ; ++len) {
        check(len);
    }
    return 0;
}