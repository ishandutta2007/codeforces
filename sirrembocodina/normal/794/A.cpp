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
    int n, a, b, c;
    cin >> a >> b >> c >> n;
    int ans = 0;
    forn (i, n) {
        int x;
        cin >> x;
        ans += b < x && x < c;
    }
    cout << ans << endl;
    return 0;
}