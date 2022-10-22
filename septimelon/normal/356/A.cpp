#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> x[i];
        --l[i];
        --r[i];
        --x[i];
    }
    
    vector<int> vb(n, 0);
    vector<int> next(n, -1);
    int buf;
    for (int i = 0; i < m; ++i) {
        for (int j = l[i]; j <= r[i]; ++j) {
            if (j == x[i]) {
                continue;
            } else if (next[j] >= 0) {
                buf = j;
                j = next[j] - 1;
                if (buf < x[i]) {
                    next[buf] = x[i];
                } else {
                    next[buf] = r[i] + 1;
                }
            } else {
                if (j < x[i]) {
                    next[j] = x[i];
                } else {
                    next[j] = r[i] + 1;
                }
                vb[j] = x[i] + 1;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << vb[i] << " ";
    }
    
    return 0;
}