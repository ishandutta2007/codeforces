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

char s[1010][1010];
bool is[1010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    forn (i, n) {
        scanf("%s", s[i]);
    }
    int ans = 0;
    forn (j, m) {
        bool ok = true;
        forn (i, n - 1) {
            if (is[i]) {
                continue;
            }
            if (s[i][j] <= s[i + 1][j]) {
                continue;
            }
            ok = false;
        }
        if (!ok) {
            ++ans;
            continue;
        }
        forn (i, n - 1) {
            if (s[i][j] < s[i + 1][j]) {
                is[i] = true;
            }
        }
    }
    cout << ans;
    return 0;
}