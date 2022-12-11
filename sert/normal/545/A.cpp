#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 7;

int n, x;
vector <int> ans;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1 || x == 3)
                ok = false;
        }
        if (ok) ans.push_back(i + 1);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}