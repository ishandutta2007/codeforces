#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e3 + 34;
const ll md = 1e9 + 7;

int a[N][N][2];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
    int n, k, d;
    cin >> n >> k >> d;
    a[0][0][0] = 1;
    for (int len = 1; len <= n; len++)
        for (int sum = 0; sum <= n; sum++) {
            for (int pr = sum - 1; pr > max(sum - d, -1); pr--)
                a[sum][len][0] = (a[sum][len][0] + a[pr][len - 1][0]) % md;
            for (int pr = sum - d; pr >= max(sum - k, 0); pr--)
                a[sum][len][1] = (a[sum][len][1] + a[pr][len - 1][0]) % md;
            for (int pr = sum - 1; pr >= max(sum - k, 0); pr--) 
                a[sum][len][1] = (a[sum][len][1] + a[pr][len - 1][1]) % md;
            // cout << sum << " " << len << " " << a[sum][len][0] << " " << a[sum][len][1] << "\n";
        }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + a[n][i][1]) % md;
    }
    cout << ans;
    //return 0;
}