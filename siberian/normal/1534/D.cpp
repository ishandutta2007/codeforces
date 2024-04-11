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

const int N = 2e3 + 10;
int n;
int ans[N];
bool need[N];
bool used[N];

pair<int, int> fout[2 * N];
int topAns = 0;

void restore(int v) {
    for (int i = 0; i < n; ++i) {
        if (ans[i] != 1) continue;
        fout[topAns++] = {i, v};
    }
}

void query(int v) {
    used[v] = true;
    cout << "? " << v + 1 << endl;
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
    }
    restore(v);
}

void outAns() {
    for (int i = 0; i < topAns; ++i) {
        if (fout[i].first > fout[i].second) {
            swap(fout[i].first, fout[i].second);
        } 
    }
    sort(fout, fout + topAns);
    topAns = unique(fout, fout + topAns) - fout;
    assert(n - 1 == topAns);
    cout << "!" << endl;
    for (int i = 0; i < topAns; ++i) {
        cout << fout[i].first + 1 << " " << fout[i].second + 1 << endl;
    }
}

int cnt[2];


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    query(0);
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; ++i) {
        cnt[ans[i] % 2]++;
    }
    int fans = -1;
    if (cnt[0] <= (n + 1) / 2) {
        fans = 0;
    } else {
        assert(cnt[1] + 1 <= (n + 1) / 2);
        fans = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (fans == ans[i] % 2) {
            need[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (!need[i]) continue;
        query(i);
    }
    // assert(topAns == n - 1);
    outAns();
    return 0;
}