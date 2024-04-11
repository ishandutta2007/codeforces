#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

string s, k;

int d, m, y;
int kol[40][20][5];
int ans, ad, am, ay;
int kd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> s;

    for (int i = 0; i < s.length() - 9; i++) {
        k = "";
        for (int j = i; j < i + 10; j++)
            k += s[j];
        if (k[0] == '-') continue;
        if (k[1] == '-') continue;
        if (k[2] != '-') continue;
        if (k[3] == '-') continue;
        if (k[4] == '-') continue;
        if (k[5] != '-') continue;
        if (k[6] != '2') continue;
        if (k[7] != '0') continue;
        if (k[8] != '1') continue;
        if (k[9] == '-' || k[9] > '5' || k[9] < '3') continue;
        d = 10 * (k[0] - '0') + k[1] - '0';
        m = 10 * (k[3] - '0') + k[4] - '0';
        y = k[9] - '3';
        if (m > 12 || m == 0 || d == 0)
            continue;
        if (d > kd[m - 1])
            continue;
        kol[d][m][y]++;
        if (kol[d][m][y] > ans) {
            ans = kol[d][m][y];
            ad = d;
            am = m;
            ay = y + 2013;
        }
    }
    if (ad < 10)
        cout << 0;
    cout << ad << "-";
    if (am < 10)
        cout << 0;
    cout << am << "-";
    cout << ay;

    return 0;
}