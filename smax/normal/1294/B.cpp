#include <bits/stdc++.h>
using namespace std;

pair<int, int> pts[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> pts[i].first >> pts[i].second;

        sort(pts, pts + n);
        int maxY = 0;
        bool ok = true;
        for (int i=0; i<n; i++) {
            if (pts[i].second < maxY) {
                ok = false;
                break;
            }
            maxY = pts[i].second;
        }

        if (ok) {
            cout << "YES\n";
            for (int i=0; i<n; i++) {
                for (int j=0; j<pts[i].first - (i > 0 ? pts[i-1].first : 0); j++)
                    cout << 'R';
                for (int j=0; j<pts[i].second - (i > 0 ? pts[i-1].second : 0); j++)
                    cout << 'U';
            }
            cout << "\n";
        } else
            cout << "NO\n";
    }

    return 0;
}