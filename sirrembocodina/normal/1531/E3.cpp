#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

string s;

int cur;
vector<int> sum;

bool test(int len) {
    if (len == 1) {
        return true;
    }
    int len0 = len / 2, len1 = len - len0;
    if (!test(len0) || !test(len1)) {
        return false;
    }
    int cnt1 = sum[s.size()] - sum[cur];
    int cnt0 = s.size() - cur - cnt1;
    if (cnt0 < len0 && cnt1 < len1) {
        return false;
    }
    int l = cur, r = s.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        cnt1 = sum[mid] - sum[cur];
        cnt0 = mid - cur - cnt1;
        if (cnt0 < len0 && cnt1 < len1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cur = r;
    return true;
}

vector<int> a;
map<pair<int, int>, int> me;

void build_me(int l, int r) {
    if (l == r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    build_me(l, mid);
    build_me(mid, r);
    me[{l, r}] = cur;
    int cnt0 = 0, cnt1 = 0;
    while (cnt0 < mid - l && cnt1 < r - mid) {
        if (s[cur++] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
}

void build(int l, int r) {
    if (l == r - 1) {
        return;
    }
    int cur = me[{l, r}];
    int mid = (l + r) / 2;
    vector<int> b;
    for (int i = l; i < r; i++) {
        b.push_back(a[i]);
    }
    //sort(b.begin(), b.end());
    int i = l, j = mid, k = 0;
    while (i < mid && j < r) {
        if (s[cur++] == '0') {
            a[i++] = b[k++];
        } else {
            a[j++] = b[k++];
        }
    }
    while (i < mid) {
        a[i++] = b[k++];
    }
    while (j < r) {
        a[j++] = b[k++];
    }
    build(l, mid);
    build(mid, r);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    sum.resize(n + 1);
    forn (i, n) {
        sum[i + 1] = sum[i] + (s[i] == '1');
    }
    int l = 1, r = 1e5 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        cur = 0;
        if (test(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int len = l;
    forn (i, len) {
        a.push_back(i + 1);
    }
    cur = 0;
    build_me(0, len);
    build(0, len);
    cout << len << '\n';
    forn (i, len) {
        cout << a[i] << ' ';
    }
}