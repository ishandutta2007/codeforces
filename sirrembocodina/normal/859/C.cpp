#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef int ll;

int mod = 1000000007;

int n;
long long a[100], d[100][2][2];

int main() {
    cin >> n;
    forn (i, n) {
        cin >> a[i];
    }
    d[n][0][0] = 0;
    d[n][0][1] = 0;
    d[n][1][0] = 0;
    d[n][1][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        forn (j, 2) {
            long long x = a[i] + d[i + 1][1 - j][j], y = d[i + 1][j][j];
            if (x > y) {
                d[i][j][j] = x;
                d[i][j][1 - j] = d[i + 1][1 - j][1 - j];
            } else {
                d[i][j][j] = y;
                d[i][j][1 - j] = a[i] + d[i + 1][j][1 - j];
            }
        }
    }
    cout << d[0][1][0] << " " << d[0][1][1] << endl;
    return 0;
}