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
    set<ll> s;
    int n;
    cin >> n;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        s.insert(x);
    }
    vector<ll> ans = {a[0]};

    for (int deg = 0; deg < 31; deg++) {
        ll len = (1 << deg);
        for (int i = 0; i < n; i++) {
            if (s.find(a[i] + len) != s.end() && (int)ans.size() < 2) {
                ans = {a[i], a[i] + len};
            }
            if (s.find(a[i] + len) != s.end() && s.find(a[i] + len * 2) != s.end() && (int)ans.size() < 3) {
                ans = {a[i], a[i] + len, a[i] + len * 2};
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    //solve();
    //solve();
    //solve();
#endif
    solve();
    return 0;
}