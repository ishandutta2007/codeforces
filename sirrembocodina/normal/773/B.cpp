#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

const int mod = 1000000007;

int a[5];
int b[5];
int cnt[5];
int n;

bool can(int m) {
    int A = 0, B = 0;
    forn (i, 5) {
        int j = 0, x = cnt[i] + (a[i] < b[i] && a[i]) * m;
        if (a[i] == 0 && b[i] == 0) {
            continue;
        }
        while (x <= n + m && j < 6) {
            ++j;
            x *= 2;
        }
        A += j * a[i];
        B += j * b[i];
    }
    return A > B;
}

int main() {
    cin >> n;
    forn (i, 5) {
        cin >> a[i];
        if (a[i] != -1) {
            a[i] = 250 - a[i];
            ++cnt[i];
        } else {
            a[i] = 0;
        }
    }
    forn (i, 5) {
        cin >> b[i];
        if (b[i] != -1) {
            b[i] = 250 - b[i];
            ++cnt[i];
        } else {
            b[i] = 0;
        }
    }
    forn (i, n - 2) {
        forn (i, 5) {
            int x;
            cin >> x;
            if (x != -1) {
                ++cnt[i];
            }
        }
    }
    forn (i, 1000000) {
        if (can(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}