#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    map <int, int> data;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        data[x] = 1;
    }
    if (!b) {
        if (data[0]) {
            cout << 0;
        } else {
            cout << "inf";
        }
        return 0;
    }
    if (abs(b) > l) {
        cout << 0;
        return 0;
    }
    if (abs(q) < 2) {
        int cnt = 0;
        if (!data[b]) cnt++;
        if (!q) {
            if (data[0]) {
                cout << cnt;
            } else {
                cout << "inf";
            }
        } else if (q == -1) {
            if (!data[-b]) {
                cnt++;
            }
            if (cnt) {
                cout << "inf";
            } else {
                cout << 0;
            }
        } else {
            if (cnt) {
                cout << "inf";
            } else {
                cout << 0;
            }
        }
        return 0;
    }
    int cnt = 0;
    while (abs(b) <= l) {
        if (!data[b]) cnt++;
        b *= q;
    }
    cout << cnt;
}