#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    string s;
    vector <int> a(2, 0);
    for (int i = 0; i < 2; i++) {
        cin >> s;
        if (s == "monday") {
            a[i] = 0;
        } else if (s == "tuesday") {
            a[i] = 1;
        } else if (s == "wednesday") {
            a[i] = 2;
        } else if (s == "thursday") {
            a[i] = 3;
        } else if (s == "friday") {
            a[i] = 4;
        } else if (s == "saturday") {
            a[i] = 5;
        } else if (s == "sunday") {
            a[i] = 6;
        }
    }
    int n = a[0], m = a[1];
    if (n > m) m += 7;
    if (m - n == 0 || m - n == 2 || m - n == 3) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
/*
9 10
99999.445
*/