#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector <pair <int, int> > data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }
    sort(data.begin(), data.end());
    vector <int> d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    d.push_back(s);
    k++;
    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int left = 0;
        int time = 0;
        bool fl = 0;
        for (int i = 0; i < k; i++) {
            int rast = d[i] - left;
            int x = mid;
            left = d[i];
            if (x < rast) {
                fl = 1;
                break;
            }
            x -= rast;
            if (rast <= x) {
                time += rast;
            } else {
                time += x + (rast - x) * 2;
            }
        }
        if (!fl && time <= t) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << r << endl;
    for (int i = 0; i < n; i++) {
        if (data[i].second >= r) {
            cout << data[i].first << endl;
            return 0;
        }
    }
    cout << -1;
}