#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e8 + 7;
const ll SQ = 1e4 + 7;
const double EPS = 1e-8;
const ll Q = 1e8 + 19;
const ll P = 1e9 + 7;

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
    vector <vector <ll> > ha(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll h = 0;
        vector <ll> fact;
        if (!x) {
            ha[i].push_back(-2);
            continue;
        }
        if (x < 0) {
            fact.push_back(-1);
            x = -x;
        }
        for (int i = 2; i < SQ; i++) {
            while (x % i == 0) {
                if (fact.size() && fact.back() == i) {
                    fact.pop_back();
                } else {
                    fact.push_back(i);
                }
                x /= i;
            }
        }
        if (x != 1) {
            fact.push_back(x);
        }
        ha[i] = fact;
        //cout << h << "\n";
    }
    auto sha = ha;
    vector <ll> a(n);
    sort(sha.begin(), sha.end());
    for (ll i = 0; i < n; i++) {
        a[i] = lower_bound(sha.begin(), sha.end(), ha[i]) - sha.begin();
        //cout << a[i] << " ";
    }
    //cout << "\n";
    vector <ll> res(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        vector <bool> used(n, false);
        ll cnt = 0;
        ll zero = 0;
        for (ll j = i; j < n; j++) {
            ll x = a[j];
            if (ha[j].size() && ha[j][0] == -2) {
                zero = 1;
            } else if (!used[x]) {
                cnt++;
                used[x] = true;
            }
            //cout << i << " " << j << " " << zero << " " << cnt << "\n";
            res[max(zero, cnt)]++;
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}