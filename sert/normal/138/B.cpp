#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
string s, a1, a2;
int bst = -1, xx, yy, a[N], b[N];

void cnt(int x, int y) {
    if (a[x] < 1 || b[y] < 1)
        return;
    int res = 0;
    a[x]--;
    b[y]--;

    res += min(a[0], b[9]);
    res += min(a[1], b[8]);
    res += min(a[2], b[7]);
    res += min(a[3], b[6]);
    res += min(a[4], b[5]);
    res += min(a[5], b[4]);
    res += min(a[6], b[3]);
    res += min(a[7], b[2]);
    res += min(a[8], b[1]);
    res += min(a[9], b[0]);
    res += max(0, min(a[0] - b[9], b[0] - a[9]));

    if (res > bst) {
        bst = res;
        xx = x;
        yy = y;
    }

    a[x]++;
    b[y]++;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        a[s[i] - '0']++;
        b[s[i] - '0']++;
    }

    cnt(1, 9);
    cnt(2, 8);
    cnt(3, 7);
    cnt(4, 6);
    cnt(5, 5);
    cnt(6, 4);
    cnt(7, 3);
    cnt(8, 2);
    cnt(9, 1);

    if (bst != -1) {

        a[xx]--;
        b[yy]--;

        int t = min(a[0] - b[9], b[0] - a[9]);
        for (int i = 0; i < t; i++) {
            a1 += '0';
            a2 += '0';
            a[0]--;
            b[0]--;
        }

        a1 += char('0' + xx);
        a2 += char('0' + yy);

        for (int i = 0; i < 10; i++) {
            t = min(a[i], b[9 - i]);
            for (int j = 0; j < t; j++) {
                a1 += char('0' + i);
                a2 += char('0' + 9 - i);
            }
            a[i] -= t;
            b[9 - i] -= t;
        }

    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i]; j++) {
            a1 += char('0' + i);
        }
        for (int j = 0; j < b[i]; j++) {
            a2 += char('0' + i);
        }
    }

    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());

    cout << a1 << "\n" << a2 << "\n";

    return 0;
}