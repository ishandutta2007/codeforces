#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    //sort(a.begin(), a.end());
    //reverse(a.begin(), a.end());
    vector<int> cou;
    cou.push_back(1);
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++cou.back();
        } else {
            cou.push_back(1);
        }
    }
    int g = cou[0];
    int s = 0;
    int b = 0;
    int ind = 1;
    while (ind < cou.size() && s <= g) {
        s += cou[ind];
        ++ind;
    }
    while (ind < cou.size() && b <= g) {
        b += cou[ind];
        ++ind;
    }
    while (ind < cou.size() && (s + g + b) * 2 <= n) {
        b += cou[ind];
        ++ind;
    }
    --ind;
    b -= cou[ind];
    if (s <= g || b <= g || (s + g + b) * 2 > n) {
        cout << "0 0 0\n";
    } else {
        cout << g << " " << s << " " << b << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}