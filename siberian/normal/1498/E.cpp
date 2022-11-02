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

void outAns(int a, int b) {
    cout << "! " << a + 1 << " " << b + 1 << endl;
    exit(0);
}

void query(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    string ans;
    cin >> ans;
    if (ans == "Yes") {
        outAns(a, b);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<int> k(n);
    for (auto& i : k) {
        cin >> i;
    }
    vector<pair<int, int>> order;

    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&] (int a, int b) {
        return k[a] > k[b];
    });

    int L = 0;
    while (L < n && k[id[L]] == n - 1 - L) ++L;
    int R = n - 1;
    while (R >= 0 && k[id[R]] == n - 1 - R) --R;

    for (int i = L; i <= R; ++i) {
        for (int j = i + 1; j <= R; ++j) {
            order.push_back({id[i], id[j]});
        }
    }
    if (order.size() > 1) {
        sort(all(order), [&] (pair<int, int> a, pair<int, int> b) {
            return abs(k[a.first] - k[a.second]) > abs(k[b.first] - k[b.second]);
        });
        for (auto i : order) {
            query(i.first, i.second);
        }
    }
    outAns(-1, -1);
    return 0;
}