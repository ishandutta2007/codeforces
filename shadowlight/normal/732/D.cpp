#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> data(n, 0);
    vector <int> days(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> days[i];
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector <pair <int, int> > max_day(m);
        for (int i = 0; i < m; i++) {
            max_day[i] = {-1, i + 1};
        }
        for (int i = mid; i >= 0; i--) {
            if (data[i] != 0) max_day[data[i] - 1].first = max(max_day[data[i] - 1].first, i);
        }
        bool fl = 0;
        sort(max_day.begin(), max_day.end());
        if (max_day[0].first == -1) fl = 1;
        int cnt = -1;
        for (int i = 0; i < m; i++) {
            cnt += days[max_day[i].second];
            if (max_day[i].first <= cnt) {
                fl = 1;
                break;
            }
            cnt++;
        }
        //cout << mid << " " << fl << endl;
        if (fl) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r + 1 > n) {
        cout << -1 << endl;
    } else {
        cout << r + 1 << endl;
    }
}