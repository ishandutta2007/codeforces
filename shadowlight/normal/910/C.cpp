#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n;
    cin >> n;
    vector <string> a(n);
    vector <bool> first(10, false);
    vector <ll> sum(10, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        first[s[0] - 'a'] = true;
        ll now = 1;
        for (ll j = (int) s.size() - 1; j >= 0; j--) {
            sum[s[j] - 'a'] += now;
            now *= 10;
        }
    }
    vector <pair <ll, ll> > b(10);
    for (ll i = 0; i < 10; i++) {
        b[i] = {sum[i], i};
        //cout << i << " " << sum[i] << "\n";
    }
    sort(b.rbegin(), b.rend());
    bool fl = 0;
    ll res = 0;
    ll last = 1;
    for (ll i = 0; i < 10; i++) {
        if (!fl && !first[b[i].second]) {
            fl = 1;
            continue;
        }
        //cout << last << " " << b[i].first << "\n";
        res += last * b[i].first;
        last++;
    }
    cout << res;
}