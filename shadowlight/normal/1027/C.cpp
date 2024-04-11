#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void solve() {
    int n;
    cin >> n;
    map <int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector <pair <int, int> > a;
    for (auto p : cnt) {
        if (p.second >= 4) {
            for (int i = 0; i < 4; i++) {
                cout << p.first << " ";
            }
            return;
        }
        if (p.second < 2) continue;
        a.push_back(p);
    }
    ll top = INF, bot = 1;
    ll xa = -1, ya = -1;
    for (int i = 0; i < (int) a.size() - 1; i++) {
        ll x = a[i].first, y = a[i + 1].first;
        //cout << (double) top / bot << " " << (double) (x + y) / (double) (x * y) << "\n";
        if (xa == -1 || top * x * y > bot * (x + y) * (x + y)) {
            top = (x + y) * (x + y);
            bot = x * y;
            xa = x;
            ya = y;
        }
    }
    for (int i = 0; i < 2; i++) {
        cout << xa << " " << ya << " ";
    }
}

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
    cout.precision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << "\n";
    }
}