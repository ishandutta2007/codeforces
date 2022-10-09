#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
//    if (d % t == 0) {
        cout << ((d / t + 1) * k >= n ? "NO" : "YES") << endl;
        return 0;
//    }
//    cout >> (t1 > t2 ? "NO" : "YES") << endl;
    return 0;
}