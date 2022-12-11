#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int ask(int n, int pos, int val, int oth) {
    int mn = min(val, oth);
    val -= (mn - 1);
    oth -= (mn - 1);
    cout << "?";
    for (int i = 0; i < n; i++) {
        cout << " " << (i == pos ? val : oth);
    }
    cout << endl;
    int x;
    cin >> x;
    return x - 1;
}

void solve() {
    int n;
    cin >> n;
    int pos = -1;
    vector<int> ans(n);
    int num = 0;
    for (int i = 1; i < n; i++) {
        if (ask(n, n - 1, i, 0) != -1)
            num++;
    }
    ans.back() = n - 1 - num;

    for (int i = 0; i < n; i++) {
        if (i == ans.back()) continue;
        int dif = ans.back() - i;
        if (dif > 0)
            ans[ask(n, n - 1, 0, dif)] = i;
        else
            ans[ask(n, n - 1, -dif, 0)] = i;
    }

    cout << "!";
    for (int x : ans) cout << " " << x + 1;
    cout << endl;
}

int main() {
    int t = 1;
//    if (D) {
//        freopen("../a.in", "r", stdin);
//    }
    //cin >> t;
    while (t--) {
        solve();
    }
}