#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

int a[100010], n;

bool canWe(int x) {
    int j = 0;
    forn (i, n) {
        while (j < n - 1 && a[j] - a[i] < x) {
            ++j;
        }
        if (a[j] - a[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, y, l;
    scanf("%d %d", &n, &l);
    scanf("%d %d", &x, &y);
    forn (i, n) {
        scanf("%d", &a[i]);
    }
    bool cx = canWe(x), cy = canWe(y);
    if (cx && cy) {
        printf("0\n");
        return 0;
    }
    if (cx || cy) {
        if (cx) {
            x = y;
        }
        printf("1\n%d", x);
        return 0;
    }
    int j;
    j = 0;
    forn (i, n) {
        while (j < n - 1 && a[j] - a[i] < y - x) {
            ++j;
        }
        if (a[j] - a[i] == y - x) {
            if (a[i] >= x) {
                printf("1\n%d", a[i] - x);
                return 0;
            }
            if (a[i] <= l - y) {
                printf("1\n%d", a[i] + y);
                return 0;
            }
        }
    }
    j = 0;
    forn (i, n) {
        while (j < n - 1 && a[j] - a[i] < y + x) {
            ++j;
        }
        if (a[j] - a[i] == y + x) {
            printf("1\n%d", a[i] + y);
            return 0;
        }
    }
    printf("2\n%d %d", x, y);
    return 0;
}