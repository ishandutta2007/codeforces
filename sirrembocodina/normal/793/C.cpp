#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pt;

pair<int, int> a[100100], v[100100];
int x1, y1, x2, y2;
ld l = 0, r = 1e100;

void handle(int a, int v, int x1, int x2) {
    if (
        a <= x1 && v <= 0 ||
        a >= x2 && v >= 0
    ) {
        cout << -1 << endl;
        exit(0);
    }
    if (x1 <= a && a <= x2) {
        if (v > 0) {
            r = min(r, ld(x2 - a) / ld(v));
        } else if (v < 0) {
            r = min(r, ld(a - x1) / ld(-v));
        }
        return;
    }
    if (a <= x1) {
        l = max(l, ld(x1 - a) / ld(v));
        r = min(r, ld(x2 - a) / ld(v));
    } else {
        l = max(l, ld(a - x2) / ld(-v));
        r = min(r, ld(a - x1) / ld(-v));
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    forn (i, n) {
        cin >> a[i].fs >> a[i].sc;
        cin >> v[i].fs >> v[i].sc;
        handle(a[i].fs, v[i].fs, x1, x2);
//        cerr << double(l) << " " << double(r) << endl;
        handle(a[i].sc, v[i].sc, y1, y2);
//        cerr << double(l) << " " << double(r) << endl;
    }
    if (r - l > 1e-12) {
        cout.precision(10);
        cout << fixed << double(l) << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}