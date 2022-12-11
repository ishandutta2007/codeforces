#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

inline void mxe(int &a, int b) {
    if (b > a) a = b;
}

void kek(vector<int> &a, const vector<int> &v) {
    int cur = 0;
    for (int x : v) {
        reverse(a.begin() + cur, a.begin() + cur + x);
        cur += x;
    }
    reverse(a.begin(), a.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x--;
    }
    auto fnd = [&](int x) {
        for (int i = 0; i < n; i++) if (a[i] == x) return i;
        exit(11);
    };

    int p0 = fnd(0);
    bool isL = true;
    if (n % 2 == 1) {
        if (p0 == 0) cout << n - 1 << "\n";
        else {
            cout << n << "\n" << "2 " << p0 << " " << n - p0 << "\n";
            kek(a, {p0, n - p0});
        }
    } else {
        isL = false;
        if (p0 + 1 == n) cout << n - 1 << "\n";
        else {
            cout << n << "\n" << "2 " << p0 + 1 << " " << n - p0 - 1 << "\n";
            kek(a, {p0 + 1, n - p0 - 1});
        }
    }

    auto print = [&](const vector<int> &v) {
        cout << v.size();
        for (int i : v)
            cout << " " << i;
        cout << "\n";
    };

    for (int i = 1; i < n; i++) {
        int pos = fnd(i);
        vector<int> v;
        for (int j = 0; j < i; j++) v.push_back(1);
        if (isL) {
            v.push_back(pos - i + 1);
            if (pos + 1 < n) v.push_back(n - pos - 1);
        } else {
            v.push_back(n - pos - i);
            if (pos > 0) v.push_back(pos);
            reverse(v.begin(), v.end());
        }
        print(v);
        kek(a, v);

        //cout << "a: ";
        //print(a);

        isL = !isL;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef SERT
    freopen("a.in", "r", stdin);
    solve();
    solve();
#endif
    solve();
}