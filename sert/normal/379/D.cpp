#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int N = 1e6 + 7;

ll k, x, n, m, kolm = -1, koln, ko, mn, mm;
ll k1[N], k2[N], k12[N], k21[N], k11[N], k22[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> k >> x >> n >> m;
    k1[0] = 1;
    k2[1] = 1;
    for (int i = 2; i < k; i++) {
        k1[i] = k1[i - 1] + k1[i - 2];
        k2[i] = k2[i - 1] + k2[i - 2];
        k12[i] = k12[i - 1] + k12[i - 2];
        k21[i] = k21[i - 1] + k21[i - 2];
        k22[i] = k22[i - 1] + k22[i - 2];
        if (i == 2) k12[i]++;
        if (i % 2 == 1) k21[i]++;
        if (i % 2 == 0 && i > 2) k22[i]++;
        //cerr << k1[i] << "\n";
    }

 /*   ll xx = x;
    for (int i = 0; i <= k1[k]; i++) {
        xx -= k2[k];
        if (xx % k1[k] == 0) {
            kolm = i;
            break;
        }
    }

    if (kolm == -1) {
        cout << "Happy new year!";
        return 0;
    }

    while (xx % k2[k] != 0) {
        koln++;
        xx -= k1[k];
    }

    ko = xx / (k1[k] * k2[k]);

    mn = n / 2 - koln;
    mm = m / 2 - kolm;*/

    //cout << k1[k - 1] << " " << k2[k - 1] << "\n";
   // cerr << k12[k - 1] << " " << k21[k - 1] << "\n";
    //cerr << k22[k - 1] << "\n";
    ll res;
    //cout << k2[k - 1] + k12[k - 1] << "\n";
   // cout << x << "\n";

    for (int i = 0; i <= n / 2; i++)
    for (int j = 0; j <= m / 2; j++) {
        //cerr << i << " " << j << "\n";

        res = k1[k - 1] * i + k2[k - 1] * j;
        if (res == x && i * 2 <= n && j * 2 <= m) {
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i; ii++) cout << "S";
            cout << "\n";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j; ii++) cout << "S";
            return 0;
        }
        if (res + k22[k - 1] == x && i * 2 < n && j * 2 < m - 1) {
            cout << "S";
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i - 1; ii++) cout << "S";
            cout << "\n";
            cout << "C";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j - 2; ii++) cout << "S";
            cout << "A";
            return 0;
        }
        if (res + k12[k - 1] == x && i * 2 < n && j * 2 < m) {
            //cerr << "ok\n";
            //cout << k2[k - 1] + k12[k - 1] << "\n";
            //cout << x << "\n";
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i - 1; ii++) cout << "S";
            cout << "A";
            cout << "\n";
            cout << "C";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j - 1; ii++) cout << "S";
            return 0;
        }
        if (res + k22[k - 1] + k12[k - 1] == x && i * 2 < n && j * 2 < m - 1) {
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i - 1; ii++) cout << "S";
            cout << "A";
            cout << "\n";
            cout << "C";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j - 2; ii++) cout << "S";
            cout << "A";
            return 0;
        }
        if (res + k21[k - 1] == x && i * 2 < n && j * 2 < m) {
            cout << "C";
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i - 1; ii++) cout << "S";
            cout << "\n";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j - 1; ii++) cout << "S";
            cout << "A";
            return 0;
        }
        if (res + k22[k - 1] + k12[k - 1] + k21[k - 1] == x && i * 2 < n - 1 && j * 2 < m - 1) {
            cout << "C";
            for (int ii = 0; ii < i; ii++) cout << "AC";
            for (int ii = 0; ii < n - i - i - 2; ii++) cout << "S";
            cout << "A";
            cout << "\n";
            cout << "C";
            for (int ii = 0; ii < j; ii++) cout << "AC";
            for (int ii = 0; ii < m - j - j - 2; ii++) cout << "S";
            cout << "A";
            return 0;
        }

    }

    cout << "Happy new year!";

    return 0;
}