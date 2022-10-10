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

int main() {
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    forn (i, k - 1) {
        if ((i & 1) == 0) {
            printf("%d ", l++);
        } else {
            printf("%d ", r--);
        }
    }
    if (k & 1) {
        forn (i, n - k + 1) {
            printf("%d ", l++);
        }
    } else {
        forn (i, n - k + 1) {
            printf("%d ", r--);
        }
    }
}