#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t;
long double a, b, c, p, res;

void dp(long double a, long double b, long double c, long double all, int dem) {
    ++dem;
    if (a > 0) {
        long double tile = a / (a+b+c) * all;
        long double lose = min(a, p);
        if (b) dp(a - lose, b + lose/2, c + lose/2, tile, dem);
        else dp(a - lose, b, c + lose, tile, dem);
    }
    if (b > 0) {
        long double tile = b / (a+b+c) * all;
        long double lose = min(b, p);
        if (a) dp(a + lose/2, b - lose, c + lose/2, tile, dem);
        else dp(a, b - lose, c + lose, tile, dem);
    }
    if (c > 0) {
        long double tile = c / (a+b+c) * all * dem;
        res += tile;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    cout << setprecision(12) << fixed;
    long long W = 1e10;
    while (t--) {
        res = 0;
        cin >> a >> b >> c >> p;
        a *= W; b *= W; c *= W; p *= W;
        dp(a, b, c, 1, 0);
        cout << res << '\n';
    }
}