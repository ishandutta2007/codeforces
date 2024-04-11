#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXS = 200;
int arr[MAXS][MAXS];

bool ok = false;
int s;

void print(int ord) {
    char one = 'A', two = 'B', thr = 'C';
    switch(ord) {
    case 2:
        swap(two, thr);
        break;
    case 3:
        one = 'B', two = 'A', thr = 'C';
        break;
    case 4:
        one = 'B', two = 'C', thr = 'A';
        break;
    case 5:
        one = 'C', two = 'A', thr = 'B';
        break;
    case 6:
        one = 'C', two = 'B', thr = 'A';
        break;
    }
    cout << s << '\n';
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            if (arr[i][j] == 1) cout << one;
            if (arr[i][j] == 2) cout << two;
            if (arr[i][j] == 3) cout << thr;
        }
        cout << '\n';
    }
}
int x = 0;
void check(int ax, int ay, int bx, int by, int cx, int cy, bool a, bool b, bool c, int ord) {
    if (a) swap(ax, ay);
    if (b) swap(bx, by);
    if (c) swap(cx, cy);
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < s; ++j)
            arr[i][j] = 0;
    for (int i = 0; i < ax; ++i)
        for (int j = 0; j < ay; ++j)
            arr[i][j] = 1;
    ////////
    if (ax + bx == s && by + cy == s && bx == cx && ay == s) {
        for (int i = ax; i < s; ++i)
            for (int j = 0; j < by; ++j)
                arr[i][j] = 2;
        for (int i = ax; i < s; ++i)
            for (int j = by; j < s; ++j)
                arr[i][j] = 3;
        print(ord);
        ok = true;
        return;
    }
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < s; ++j)
            arr[i][j] = 0;
    for (int i = 0; i < ax; ++i)
        for (int j = 0; j < ay; ++j)
            arr[i][j] = 1;
    if (ay + by + cy == s && ax == bx && bx == cx && cx == s) {
        for (int i = 0; i < s; ++i)
            for (int j = ay; j < ay + by; ++j)
                arr[i][j] = 2;
        for (int i = 0; i < s; ++i)
            for (int j = ay + by; j < s; ++j)
                arr[i][j] = 3;
        print(ord);
        ok = true;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
        
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    s = sqrt(ax*ay+bx*by+cx*cy);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                check(ax, ay, bx, by, cx, cy, i, j, k, 1);
                if (ok) return 0;
                check(ax, ay, cx, cy, bx, by, i, j, k, 2);
                if (ok) return 0;
                check(bx, by, ax, ay, cx, cy, i, j, k, 3);
                if (ok) return 0;
                check(bx, by, cx, cy, ax, ay, i, j, k, 4);
                if (ok) return 0;
                check(cx, cy, ax, ay, bx, by, i, j, k, 5);
                if (ok) return 0;
                check(cx, cy, bx, by, ax, ay, i, j, k, 6);
                if (ok) return 0;
            }
        }
    }
    cout << -1;
    return 0;
}