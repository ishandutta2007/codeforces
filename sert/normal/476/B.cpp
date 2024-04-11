#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

const int N = 1e6 + 34;

string s1, s2;
int kv, p;
int c[100][100];

void cnt() {
    for (int i = 0; i < 34; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    cnt();
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        p += (s1[i] == '+' ? 1 : -1);
    for (int i = 0; i < s2.length(); i++)
        if (s2[i] == '?') kv++;
        else p += (s2[i] == '-' ? 1 : -1);
    p = abs(p);
    if (kv < p) {
        cout << 0;
        return 0;
    }
    cout.precision(10);
    long double ch, zn;
    ch = c[kv][(kv - p) / 2];
    zn = (1 << kv);
    cout << fixed << ch / zn;
}