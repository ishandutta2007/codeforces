#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;

int d[N];

/*
1
5 0
411743 411743 411743 411743 411743
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        map<int, int> mp;
        while(a[i] > 1) {
            mp[d[a[i]]]++;
            a[i] /= d[a[i]];
        }

        for(auto p : mp)
            if(p.s % 2 == 1)
                a[i] *= p.f;
    }



    vector<int> dp(n + 1, 1);
    map<int, int> lst;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if(lst.count(a[i]))
            dp[i + 1] = max(dp[i + 1], dp[lst[a[i]] + 1] + 1);
        lst[a[i]] = i;
//        cout << dp[i + 1] << ' ' << lst[a[i]] << endl;
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}