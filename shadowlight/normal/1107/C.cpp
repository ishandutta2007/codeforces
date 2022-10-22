#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
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
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    multiset <ll> q;
    ll res = 0;
    q.insert(a[0]);
    for (ll i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            ll d = q.size();
            for (ll j = 0; j < min(k, d); j++) {
                res += *q.rbegin();
                q.erase(q.find(*q.rbegin()));
            }
            //cout << res << "\n";
            q.clear();
        }
        q.insert(a[i]);
    }
    ll d = q.size();
    for (ll j = 0; j < min(k, d); j++) {
        res += *q.rbegin();
        q.erase(q.find(*q.rbegin()));
    }
    cout << res;
}