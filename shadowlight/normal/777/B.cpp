#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> used(n, 0);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        b[i] = x - '0';
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[j] >= a[i] && !used[j]) {
                used[j] = 1;
                cnt--;
                break;
            }
        }
    }
    cout << cnt << endl;
    int cnt1 = 0;
    used.clear();
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[j] > a[i] && !used[j]) {
                used[j] = 1;
                cnt1++;
                break;
            }
        }
    }
    cout << cnt1;
}
/*
1 2
0
1 1
1 1
*/