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
    int x;
    cin >> x;
    int a[100], n = 0, m = 0;
    while (x) {
        a[n++] = x % 10;
        m = max(m, x % 10);
        x /= 10;
    }
    cout << m << endl;
    forn (i, m) {
        int cur = 0, p = 1;
        forn (j, n) {
            if (i < a[j]) {
                cur += p;
            }
            p *= 10;
        }
        cout << cur << " ";
    }
    return 0;
}