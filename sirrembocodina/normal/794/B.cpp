#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    double h;
    cin >> n >> h;
    cout.precision(10);
    forn (i, n - 1) {
        cout << fixed << h * sqrt((i + 1) * 1.0 / n) << " ";
    }
    return 0;
}