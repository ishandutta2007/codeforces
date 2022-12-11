//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

struct K {
    int sum, ni, nx;
    K(int s, int i, int x) {
        sum = s;
        ni = i;
        nx = x;
    }
    bool operator < (const K &a) const {
        return (sum == a.sum ? ni < a.ni : sum < a.sum);
    }
};

void solve() {
    vector<K> a;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<int> d(m);
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> d[j];
            sum += d[j];
        }
        for (int j = 0; j < m; j++) {
            a.push_back(K(sum - d[j], i, j));
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i].sum == a[i - 1].sum && a[i].ni != a[i - 1].ni) {
            cout << "YES\n";
            cout << a[i - 1].ni + 1 << " " << a[i - 1].nx + 1 << "\n";
            cout << a[i].ni + 1 << " " << a[i].nx + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    //solve();
    //solve();
#endif
    solve();
    return 0;
}