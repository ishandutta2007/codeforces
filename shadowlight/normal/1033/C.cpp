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
    ll n;
    cin >> n;
    vector <int> win(n, -1);
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n ;i++) {
        int pos = a[i].second;
        bool can = false;
        while (pos - a[i].first >= 0) {
            pos -= a[i].first;
            if (!win[pos]) {
                can = true;
                break;
            }
        }
        pos = a[i].second;
        while (pos + a[i].first < n) {
            pos += a[i].first;
            if (!win[pos]) {
                can = true;
                break;
            }
        }
        if (can) {
            win[a[i].second] = 1;
        } else {
            win[a[i].second] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (win[i] ? "A" : "B");
    }
}