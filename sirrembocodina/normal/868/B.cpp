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
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h %= 12;
    h *= 5;
    t1 %= 12;
    t1 *= 5;
    t2 %= 12;
    t2 *= 5;
    if (t1 > t2) {
        swap(t1, t2);
    }
    bool ok = true;
    for (int i = t1; i < t2; ++i) {
        if (i == h || i == s || i == m) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES\n";
        return 0;
    }
    ok = true;
    for (int i = 0; i < t1; ++i) {
        if (i == h || i == s || i == m) {
            ok = false;
        }
    }
    for (int i = t2; i < 60; ++i) {
        if (i == h || i == s || i == m) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}