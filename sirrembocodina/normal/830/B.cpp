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

int a[100100];
vector<int> c[100100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        c[a[i]].pb(i);
    }
    long long ans = 0;
    int last = n;
    forn (i, 100100) {
        if (c[i].size() == 0) {
            continue;
        }
        if (last > c[i][0]) {
            while (c[i].back() > last) {
                c[i].pop_back();
                n--;
            }
            ans += n;
        }
        last = c[i].back();
        n -= c[i].size();
    }
    cout << ans << endl;
    return 0;
}