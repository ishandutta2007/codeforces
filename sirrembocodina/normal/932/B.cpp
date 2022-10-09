#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn2(i, n) for (i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int g[1000100];
int s[1000100][10];

int main() {
    ios::sync_with_stdio(false);
    forn (i, 10) {
        g[i] = i;
    }
    forn (i, 1000100) {
        int a = i;
        int x = 1;
        while (a) {
            if (a % 10) {
                x *= a % 10;
            }
            a /= 10;
        }
        g[i] = g[x];
    }
    forn (i, 1000010) {
        forn (j, 10) {
            s[i + 1][j] = s[i][j] + (g[i] == j);
        }
    }
    int n;
    cin >> n;
    forn (i, n) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << s[r + 1][x] - s[l][x] << endl;
    }
    return 0;
}