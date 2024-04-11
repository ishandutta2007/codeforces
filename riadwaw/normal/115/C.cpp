#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 *
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    solve();
    return 0;
}

void solve() {
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > v(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        bool var[2];
        var[0] = var[1] = false;
        for (int j = 0; j <= m; ++j) {

            if (v[i][j] == '3' || v[i][j] == '4' || v[i][j + 1] == '2' || v[i][j + 1] == '1') {
                //cout << "after " << j << " in " << i << endl;
                var[j % 2] = 1;
            }

        }
        ans *= 2 - var[0] - var[1];
        ans %= 1000003;
    }

    for (int j = 1; j <= m; ++j) {
        bool var[2];
        var[0] = var[1] = false;
        for (int i = 0; i <= n; ++i) {

            if (v[i][j] == '2' || v[i][j] == '3' || v[i + 1][j] == '1' || v[i + 1][j] == '4')
                var[i % 2] = 1;

        }
        ans *= 2 - var[0] - var[1];
        ans %= 1000003;
    }

    cout << ans;
}