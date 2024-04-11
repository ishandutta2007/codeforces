#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

set<int> delivers(int n) {
    set<int> div;
    int sqrt1 = sqrt(n);
    for (int q = 1; q <= sqrt1; q++) {
        if (n % q == 0) {
            div.insert(q);
            div.insert(n/q);
        }
    }
    return div;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t1;
    cin >> t1;
    for (int q11 = 0; q11 < t1; q11++) {
        int x, y;
        cin >> x >> y;
        set<int> all = {1, 2};
        set<int> div1 = delivers(x-1), div2 = delivers(y-1);
        for (int q : div1) {
            if (div2.find(q) != div2.end()) {
                all.insert(q);
            }
        }
        div1 = delivers(x-2), div2 = delivers(y);
        for (int q : div1) {
            if (div2.find(q) != div2.end()) {
                all.insert(q);
            }
        }
        div1 = delivers(x), div2 = delivers(y-2);
        for (int q : div1) {
            if (div2.find(q) != div2.end()) {
                all.insert(q);
            }
        }
        cout << all.size() << ' ';
        for (int q : all) {
            cout << q << ' ';
        }
        cout << endl;
    }
    return 0;
}