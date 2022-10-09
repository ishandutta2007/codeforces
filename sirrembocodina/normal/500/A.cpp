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

int a[30100];

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    --t;
    forn (i, n - 1) {
        scanf("%d", &a[i]);
        if (i > t) {
            a[i] = 0;
        }
    }
    a[t] = 1;
    ford (i, t) {
        a[i] = a[i + a[i]];
    }
    if (a[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}