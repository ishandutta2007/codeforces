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

int main() {
    int n, k;
    cin >> n >> k;
    printf("%d\n", (6 * n - 1) * k);
    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d %d\n", (6 * i - 1) * k, (6 * i - 3) * k, (6 * i - 5) * k, (6 * i - 4) * k);
    }
}