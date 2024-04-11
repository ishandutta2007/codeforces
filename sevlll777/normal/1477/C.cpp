#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    set<int> alive;
    for (int i = 1; i < n; i++) alive.insert(i);
    int now = 0;
    cout << "1 ";
    while (!alive.empty()) {
        int dist = -1, next = 0;
        for (auto pt : alive) {
            int dd = (X[pt]-X[now])*(X[pt]-X[now])+(Y[pt]-Y[now])*(Y[pt]-Y[now]);
            if (dist < dd) {
                dist = dd;
                next = pt;
            }
        }
        alive.erase(next);
        cout << next + 1 << ' ';
        now = next;
    }
    cout << '\n';
}