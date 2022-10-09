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

char s[110][110];
bool a[110][110];

int main() {
    int n;
    cin >> n;
    forn (i, n) {
        cin >> s[i];
    }
    forn (i, 2 * n - 1) {
        forn (j, 2 * n - 1) {
            a[i][j] = true;
        }
    }
    forn (i, n) {
        forn (j, n) {
            if (s[i][j] != 'o') {
                continue;
            }
            forn (x, n) {
                forn (y, n) {
                    if (s[x][y] != '.') {
                        continue;
                    }
                    a[n - 1 + x - i][n - 1 + y - j] = false;
                }
            }
        }
    }
    forn (x, n) {
        forn (y, n) {
            if (s[x][y] != 'x') {
                continue;
            }
            bool was = false;
            forn (i, n) {
                forn (j, n) {
                    if (s[i][j] == 'o' && a[n - 1 + x - i][n - 1 + y - j]) {
                        was = true;
                        break;
                    }
                }
            }
            if (!was) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    forn (i, 2 * n - 1) {
        forn (j, 2 * n - 1) {
            if (i == n - 1 && j == n - 1) {
                cout << "o";
            } else if (a[i][j]) {
                cout << "x";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}