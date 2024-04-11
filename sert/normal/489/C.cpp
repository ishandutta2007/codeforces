#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;
const ll md = 1e9 + 7;

ll m, s, cur, kol;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> m >> s;

    if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }

    if (s == 0 || s > m * 9) {
        cout << "-1 -1\n";
        return 0;
    }

    cur = s;

    if ((s + 8) / 9 == m) {
        cout << (s + 8) % 9 + 1;
        for (int i = 1; i < m; i++) cout << 9;
    } else {
        cout << 1;
        kol = (s + 7) / 9;
        for (int i = 1; i < m - kol; i++) cout << 0;
        if (kol) {
            cout << (s + 7) % 9 + 1;
            for (int i = m - kol + 1; i < m; i++) cout << 9;
        }
    }

    cout << " ";

    for (int i = 0; i < m; i++)
        if (s >= 9) {
            cout << 9;
            s -= 9;
        } else {
            cout << s;
            s = 0;
        }

    return 0;
}