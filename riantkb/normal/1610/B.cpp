#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;


bool is_pal(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - i - 1; ++i) {
        if (a[i] != a[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> rmv;
        for (int i = 0; i < n - i - 1; ++i) {
            if (a[i] != a[n - i - 1]) {
                rmv.push_back(a[i]);
                rmv.push_back(a[n - i - 1]);
                break;
            }
        }
        if (rmv.size() == 0) {
            cout << "YES\n";
            goto A;
        }
        for (auto& r : rmv) {
            vector<int> b;
            for (auto& i : a) {
                if (i != r) {
                    b.push_back(i);
                }
            }
            if (is_pal(b)) {
                cout << "YES\n";
                goto A;
            }
        }
        cout << "NO\n";
        A: continue;
    }
    return 0;
}