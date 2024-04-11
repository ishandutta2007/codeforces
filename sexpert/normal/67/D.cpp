#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e6 + 10;
const int INF = 1e9 + 7;
int to[MAXN], a[MAXN], dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        to[x] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = to[a[i]];
    }
    //for(int i = 1; i <= n; i++)
    //    cout << a[i] << " ";
    fill(dp, dp + n + 2, -INF);
    dp[0] = INF;

    for(int i = 1; i <= n; i++) {
        int x = a[i];
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(dp[mi] > x)
                lo = mi;
            else
                hi = mi - 1;
        }
        dp[lo + 1] = max(dp[lo + 1], x);
    }
    for(int i = n; i >= 0; i--)
        if(dp[i] != -INF) {
            cout << i << '\n';
            return 0;
        }
}