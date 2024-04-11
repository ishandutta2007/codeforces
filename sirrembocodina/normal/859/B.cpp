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

typedef long long ll;

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 2000000000;
    for (int i = 1; i <= n; ++i) {
        int j = n / i + bool(n % i);
        ans = min(ans, 2 * (i + j));
    }
    cout << ans << endl;
    return 0;
}