//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

int a[N];
int cnt[N];
int dp[N];
int c[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];

        for(int j = 0; j < N; j++)
            c[j] = 0;
        c[a[i]]++;

        int x = 0;
        if(cnt[a[i]] != 1)
            x++;

        int cur = a[i];
        for(int j = i - 1; j >= 0; j--) {
            if(x == 0) {
                dp[i + 1] = max(dp[i + 1], dp[j + 1] + cur);
            }

//            if(i == 4)cout << i << ' ' << j << ' ' << x << ' ' << cur << endl;

            c[a[j]]++;
            if(c[a[j]] == cnt[a[j]])
                x--;
            if(c[a[j]] == 1) {
                x++;
                cur ^= a[j];
            }

//            if(i == 4)cout << i << ' ' << j << ' ' << x << ' ' << cur << endl;
        }

        if(x == 0)
            dp[i + 1] = max(dp[i + 1], cur);

//        cout << i << ' ' << dp[i + 1] << endl;
    }

    cout << dp[n] << endl;
}