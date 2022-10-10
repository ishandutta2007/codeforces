#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ps(2*n + 1);
    vector<int> p(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> p[i];
        ps[p[i]] = i;
    }
    vector<int> cnt(2*n + 1, 1);
    int sz = 2 * n, mx = 2 * n;
    vector<int> ugh;
    while(sz) {
        while(cnt[mx] == 0)
            mx--;
        int pos = ps[mx];
        for(int i = pos; i < sz; i++)
            cnt[p[i]]--;
        ugh.push_back(sz - pos);
        sz = pos;
    }
    map<int, int> owo;
    for(auto x : ugh)
        owo[x]++;
    vector<ii> pas;
    for(auto p : owo)
        pas.push_back(p);
    vector<int> dp(n + 1, INF), tmp(n + 1);
    dp[0] = 0;
    for(auto p : pas) {
        int x = p.first, lim = p.second;
        for(int w = 0; w <= n; w++) {
            tmp[w] = INF;
            if(dp[w] < INF) {
                tmp[w] = 0;
                continue;
            }
            if(w >= x && tmp[w - x] < lim)
                tmp[w] = tmp[w - x] + 1;
        }
        dp = tmp;
    }
    cout << (dp[n] < INF ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}