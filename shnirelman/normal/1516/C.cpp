#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;
const int W = 1e5 + 13;

/*

*/

mt19937 rnd(3666);

bool dp[W];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        s += a[i];

        int x = a[i];
        int deg = 0;
        while(x % 2 == 0) {
            deg++;
            x /= 2;
        }

        mp[deg] = i;
    }

    if(s % 2 != 0) {
        cout << 0 << endl << endl;
        return;
    }

    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = W - 1 - a[i]; j >= 0; j--) {
            dp[j + a[i]] |= dp[j];
        }
    }

    if(!dp[s / 2]) {
        cout << 0 << endl << endl;
        return;
    }

    cout << 1 << endl << mp.begin()->s + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}