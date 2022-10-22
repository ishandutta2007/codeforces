#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> r;
    int cl = 0, cr = n - 1;
    bool rev = false;
    for (int i = n - 1; i >= 0; --i) {
        if (!rev && a[cr] != b[i]) {
            if (a[cl] == b[i]) {
                r.push_back(1);
            }
            r.push_back(i + 1);
            ++cl;
            swap(cl, cr);
            rev = true;
        } else if (rev && a[cr] == b[i]) {
            if (a[cl] != b[i]) {
                r.push_back(1);
            }
            r.push_back(i + 1);
            --cl;
            swap(cl, cr);
            rev = false;
        } else if (!rev) {
            --cr;
        } else {
            ++cr;
        }
    }
    
    cout << r.size();
    for (int i = 0; i < r.size(); ++i) {
        cout << " " << r[i];
    }
    cout << "\n";
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