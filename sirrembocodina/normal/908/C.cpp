#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef double ld;

int mod = 1000000007;

int x[100100];
ld y[100100];
ld r;

int main() {
    ios::sync_with_stdio(false);
    int n, R;
    cin >> n >> R;
    r = R;
    cout.precision(10);
    forn (i, n) {
        cin >> x[i];
        y[i] = r;
        forn (j, i) {
            if (abs(x[i] - x[j]) > 2 * R) {
                continue;
            }
            y[i] = max(y[i], y[j] + sqrt(4 * R * R - (x[i] - x[j]) * (x[i] - x[j])));
        }
        cout << fixed << y[i] << " ";
    }
    return 0;
}