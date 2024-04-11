#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = (int)1e9+7;

void smin(int& x, int& y) {
    if (y < x) {
        swap(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int mind = INF;
        for (int i = 1; i < n; ++i) {
            if (a[i].first != a[i - 1].first) {
                continue;
            }
            mind = min(mind, a[i].second - a[i - 1].second + 1);
        }
        if (mind == INF) {
            cout << "-1\n";
        } else {
            cout << mind << '\n';
        }
    }

    return 0;
}