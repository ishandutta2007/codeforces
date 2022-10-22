#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    string s, t = "";
    cin >> s >> m;
    vector<int> b(m);
    vector<int> a('z' - 'a' + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    n = s.size();
    for (int i = 0; i < m; ++i) {
        t += "_";
    }
    for (int i = 0; i < s.size(); ++i) {
        ++a[s[i] - 'a'];
    }
    
    int ca = a.size() - 1;
    int l = 0, r = 0;
    int det = 0;
    while (det < m) {
        r = det;
        l = 0;
        int dist = 0;
        int cur = 0;
        for (int i = 1; i < m; ++i) {
            if (t[i] != '_') {
                dist += i;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (t[i] != '_') {
                --r;
                ++l;
            } else {
                if (dist == b[i]) {
                    t[i] = '!';
                    ++cur;
                }
            }
            dist -= r;
            dist += l;
        }
        det += cur;
        while (a[ca] < cur) {
            --ca;
        }
        for (int i = 0; i < m; ++i) {
            if (t[i] == '!') {
                t[i] = 'a' + ca;
            }
        }
        --ca;
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}