#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef int ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;
const ld eps = 1e-10;
const ll C = 3;

int n, m, t;
ll k1, kol, k2, c[1111][1111];
long double cur, p;
vector <int> ch;
vector <int> zn;

void go() {
    if (ch.size() == 0 && zn.size() == 0) return;
    if (ch.size() == 0 || (zn.size() != 0 && cur > 2)) {
        cur /= zn.back();
        zn.pop_back();
        return;
    }
    cur *= ch.back();
    ch.pop_back();
}

int main()
{
    //freopen("a.in", "r", stdin);

    cin >> n >> m;
    kol = m * n;

    c[0][0] = 1;
    for (int i = 1; i < 1100; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    for (int i = 1; i <= min(n, m); i++) {
        k1 = m - 1;
        k2 = kol - 1 - k1;
        cur = 1;
        ch.clear();
        zn.clear();
        t = min(i - 1, (n - 1) - (i - 1));
        //cerr << n - 1 << " " << i - 1 << " cnk\n";
        for (int j = 1; j <= t; j++) {
            ch.push_back(n - t + j - 1);
            //cerr << ch.back() << " ";
            zn.push_back(j);
            //cerr << zn.back() << " | ";
        }
        //cerr << "\n";
        //cur = 1;
       //cerr << cur << " ";
        for (int j = kol - 1; j > kol - i; j--) {
            cur *= (0.0 + k1--) / (j + 0.0);
            go();
        }
        for (int j = kol - i; j > kol - n; j--) {
            cur *= (0.0 + k2--) / (j + 0.0);
            go();
        }
        while (ch.size() != 0 || zn.size() != 0)
            go();
        //cerr << cur << "\n";
        p += cur * (i + 0.0) / (n + 0.0);
    }

    cout.precision(15);
    cout << fixed << p << "\n";

    return 0;
}