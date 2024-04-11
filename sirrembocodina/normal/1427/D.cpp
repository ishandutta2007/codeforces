#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> ans;
    int l = n / 2, r = l;
    int cur = 0;
    while (r - l < n) {
        cur = 1 - cur;
        /*forn (i, n) {
            cerr << a[i] << " ";
        }
        cerr << endl;
        cerr << cur << " " << l << " " << r << endl;*/
        int f = l - 1;
        if (cur == 1) {
            f = r;
        }
        forn (i, n) {
            if (a[i] == f) {
                f = i;
                break;
            }
        }
        vector<int> curans;
        if (cur) {
            curans.push_back(f);
            curans.push_back(n - f - (r - l));
            curans.push_back(r - l);
            vector<int> b;
            for (int i = l; i < r; i++) {
                b.push_back(i);
            }
            for (int i = f; i < n - (r - l); i++) {
                b.push_back(a[i]);
            }
            for (int i = 0; i < f; i++) {
                b.push_back(a[i]);
            }
            a = b;
            r++;
        } else {
            curans.push_back(r - l);
            curans.push_back(f + 1 - (r - l));
            curans.push_back(n - f - 1);
            vector<int> b;
            for (int i = f + 1; i < n; i++) {
                b.push_back(a[i]);
            }
            for (int i = r - l; i < f + 1; i++) {
                b.push_back(a[i]);
            }
            for (int i = l; i < r; i++) {
                b.push_back(i);
            }
            a = b;
            l--;
        }
        ans.push_back(curans);
    }
    vector<vector<int>> ans2;
    forn (i, ans.size()) {
        vector<int> curans;
        forn (j, ans[i].size()) {
            if (ans[i][j]) {
                curans.push_back(ans[i][j]);
            }
        }
        if (curans.size() > 1) {
            ans2.push_back(curans);
        }
    }
    ans = ans2;
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        cout << ans[i].size() << " ";
        forn (j, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}