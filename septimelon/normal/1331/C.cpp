#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> nind{0, 5, 3, 2, 4, 1};
    vector<int> ival{32, 16, 8, 4, 2, 1};
    int a, ans = 0;
    cin >> a;
    for (int i = 0; i < 6; ++i) {
        if (a < ival[i]) {
            continue;
        }
        a -= ival[i];
        ans += ival[nind[i]];
    }
    cout << ans << "\n";
    return 0;
}