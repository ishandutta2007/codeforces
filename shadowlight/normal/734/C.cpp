#include <bits/stdc++.h>

using namespace std;

const long long INF = 4 * 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    long long n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector <pair <long long, long long> > a(m), c(k);
    for (long long i = 0; i < m; i++) {
        cin >> a[i].first;
    }
    for (long long i = 0; i < m; i++) {
        cin >> a[i].second;
    }
    for (long long j = 0; j < k; j++) {
        cin >> c[j].first;
    }
    for (long long j = 0; j < k; j++) {
        cin >> c[j].second;
    }
    sort(a.begin(), a.end());
    long long cost = a[0].second;
    for (long long i = 1; i < m; i++) {
        if (a[i - 1].second < a[i].second) {
            a[i] = a[i - 1];
        }
    }
    /*for (int i = 0; i < m; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }*/
    long long it = m - 1;
    long long min_time = x * n;
    for (long long j = k - 1; j >= 0; j--) {
        long long cost = c[j].second;
        long long mana = s - cost;
        if (cost > s) continue;
        min_time = min(min_time, (n - c[j].first) * x);
        while (it >= 0) {
            if (a[it].second > mana) {
                break;
            }
            it--;
        }
        it++;
        if (it == m) {
            it--;
            continue;
        }
        long long cnt = n - c[j].first;
        min_time = min(min_time, cnt * a[it].first);
        if (it != 0) it--;
    }
    for (int i = 0; i < m; i++) {
        if (s >= a[i].second) {
            //cout << a[i].first << endl;
            min_time = min(min_time, n * a[i].first);
        }
    }
    cout << min_time;
}
/*
    100 1 1
    200 1
    10 1
    10 1
*/