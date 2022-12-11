#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN];
int odp[MAXN];

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int r, g;
	cin >> r >> g;
	clr(dp);
	clr(odp);
	odp[0] = 1;
	int l = 1;
	int sum = 1;
    while (true) {
        l++;
        sum += l;
        if (sum > r + g)
            break;
    }
    sum = 0;
    for (int h = l - 1; h >= 1; --h) {
        sum += h;
//        for (int i = max(0, sum - g); i < r + 1 - l; ++i) {
        FOR(i, r + 1 - h) {
            dp[i + h] += odp[i];
        }
        for (int i = max(0, sum - g); i < r + 1; ++i) {
            dp[i] += odp[i];
        }
        FOR(i, r + 1) {
            odp[i] = dp[i];
            if (odp[i] > MOD)
                odp[i] -= MOD;
        }
        clr(dp);
    }
    sum = 0;
    FOR(i, r + 1) {
        sum = (sum + odp[i]) % MOD;
    }
    cout << sum << '\n';
	return 0;
}