#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
}

struct fenvik{
    vector<int> tree;
    int n;
    fenvik() {}

    fenvik(int _n) {
        n = _n;
        tree.resize(n, 0);
    }

    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }

    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1)
        tree[pos] += val;
    }
};

int ans;

void run() {
    fenvik tree(n);
    ans = n % 2;
    for (int i = n - 1; i >= 0; i--) {
        ans += tree.get(a[i]);
        ans %= 2;
        tree.upd(a[i], 1);
    }
}

void write() {
    if (ans) {
        cout << "Um_nik" << endl;
    } else {
        cout << "Petr" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}