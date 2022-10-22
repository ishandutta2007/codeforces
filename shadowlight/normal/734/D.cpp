#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e10 + 7;
/*
    1 2 3
    4 * 5
    6 7 8
    0
*/

long long x0, y0;

long long polozh(long long x, long long y) {
    if (x == x0) {
        if (y > y0) {
            return 2;
        } else {
            return 7;
        }
    }
    if (y == y0) {
        if (x > x0) {
            return 5;
        } else {
            return 4;
        }
    }
    long long razn = y - y0;
    long long razn1 = x - x0;
    if (razn == razn1) {
        if (x > x0) {
            return 3;
        } else {
            return 6;
        }
    }
    if (razn == -razn1) {
        if (x > x0) {
            return 8;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n >> x0 >> y0;
    vector <long long> block(9, INF), atack(9, INF);
    for (long long i = 0; i < n; i++) {
        long long x, y;
        char c;
        cin >> c >> x >> y;
        long long k = polozh(x, y);
        //cout << k << endl;
        if (k == 0) continue;
        if (c != 'B') {
            long long form1 = abs(x - x0);
            long long form2 = abs(x0 - x + y0 - y);
            if (k == 2 || k == 5 || k == 4 || k == 7) {
                atack[k] = min(atack[k], form2);
            } else {
                block[k] = min(block[k], form1);
            }
        }
        if (c != 'R') {
            long long form1 = abs(x - x0);
            long long form2 = abs(x0 - x + y0 - y);
            if (k == 2 || k == 5 || k == 4 || k == 7) {
                block[k] = min(block[k], form2);
            } else {
                atack[k] = min(atack[k], form1);
            }
        }
    }
    for (int i = 1; i < 9; i++) {
        //cout << block[i] << " " << atack[i] << endl;
        if (block[i] >= atack[i] && atack[i] != INF) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
/*
    1 2 3
    4 * 5
    6 7 8

    9
    0 0
    R -1 1
    B 0 1
    R 1 1
    B -1 0
    B 1 0
    R -1 -1
    B 0 -1
    R 1 -1
    Q 2 2
*/