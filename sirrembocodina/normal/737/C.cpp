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

int cnt[200100];

int main() {
    int n, s;
    cin >> n >> s;
    s--;
    int err = 0;
    forn (i, n) {
        int x;
        cin >> x;
        if (x == 0 && i == s) {
            cnt[x]++;
            continue;
        }
        if (i == s || x == 0) {
            err++;
            continue;
        }
        err++;
        cnt[x]++;
    }
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    int ans = n;
    int l = cnt[0] == 0, pos_err = 0;
    for (int i = 1; i < n; ++i) {
        err -= cnt[i];
        l += cnt[i] == 0;
        if (cnt[i]) {
            pos_err += cnt[i] - 1;
        }
//        cerr << l << " " << err << " " << pos_err << endl;
        if (l <= err + pos_err) {
            ans = min(ans, err + max(0, l - err));
        }
    }
    cout << ans << endl;
    return 0;
}