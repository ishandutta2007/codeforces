#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = -1, y = -1;
    forn (i, n / a + 1) {
        if ((n - i * a) % b) {
            continue;
        }
        x = i;
        y = (n - i * a) / b;
    }
    if (x == -1) {
        cout << -1 << endl;
    }
    int cnt = 0;
    forn (i, x) {
        forn (j, a) {
            cout << (cnt++ + a * (j == 0)) << " ";
        }
    }
    forn (i, y) {
        forn (j, b) {
            cout << (cnt++ + b * (j == 0)) << " ";
        }
    }
    return 0;
}