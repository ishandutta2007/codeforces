#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    int s, b;
    int mis = 1000000, mab = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        mis = min(s, mis);
    }
    for (int j = 0; j < m; ++j) {
        cin >> b;
        mab = max(b, mab);
    }
    if (mab <= mis) {
        cout << r << '\n';
        return 0;
    }
    cout << r % mis + r / mis * mab << '\n';

    return 0;
}