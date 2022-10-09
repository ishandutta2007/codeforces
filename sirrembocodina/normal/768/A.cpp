#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
int a[100100];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int mn = 2000000000, mx = -2000000000;
    forn (i, n) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int ans = 0;
    forn (i, n) {
        ans += a[i] != mn && a[i] != mx;
    }
    cout << ans << endl;
}