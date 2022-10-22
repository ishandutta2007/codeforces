#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-6;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n;
    cin >> n;
    ll l, r;
    cin >> l >> r;
    vector <vector <ll> > d(n + 1, vector <ll> (3, 0));
    d[0][0] = 1;
    vector <ll> cnt(3, 0);
    while (l <= r && l % 3) {
        cnt[l % 3]++;
        l++;
    }
    while (r >= l && r % 3 != 2) {
        cnt[r % 3]++;
        r--;
    }
    for (ll i = 0; i < 3; i++) {
        cnt[i] += (r - l + 1) / 3;
    }
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 3; a++) {
            for (int p = 0; p < 3; p++) {
                d[i + 1][(a + p) % 3] += d[i][a] * cnt[p];
                d[i + 1][(a + p) % 3] %= INF;
            }
        }
    }
    cout << d[n][0];
}