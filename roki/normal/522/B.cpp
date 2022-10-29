#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef long double ld;

typedef pair<int, int> pt;
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9 + 6;
const li INF64 = 1e18;
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;

const int N = 200 * 1000 + 50;

int a[N], b[N], c[N];

bool read() {

    scanf("%d", &n);
    forn (i, n) {
        scanf("%d%d", &a[i], &b[i]);
        c[i] = b[i];
    }

    return true;
}

void solve() {
    sort(c, c + n);
    
    int sum = 0;
    
    forn (i, n)
        sum += a[i];


    forn (i, n) {
        int h = c[n - 1];
        if (b[i] == h)
            h = c[n - 2];
        printf("%d ", h * (sum - a[i]));
    }
}

int main() {
    
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}