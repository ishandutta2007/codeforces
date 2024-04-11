#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <map <ll, ll> > exist;
vector <vector <pair <ll, ll> > > gr;

void add(ll v, ll u, ll w) {
    gr[v].push_back({u, w});
    exist[v][u] = 1;
    exist[u][v] = 1;
}

bool isP(ll x) {
    ll k = sqrt(x);
    for (ll i = 2; i <= k; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
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
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    exist.resize(n);
    if (n == 2) {
        cout << "2 2" << "\n";
        cout << "1 2 2\n";
        return 0;
    }
    add(0, 1, 1);
    add(1, n - 1, 1);
    m -= n - 1;
    for (ll v = n - 2; v >= 3; v--) {
        add(v, v + 1, 1);
    }
    ll now = n - 1;
    while (!isP(now)) {
        now++;
    }
    if (n > 3) {
        add(2, 3, now - n + 2);
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            if (i == j) continue;
            if (exist[i][j]) continue;
            if (!m) break;
            add(i, j, 1e9);
            m--;
        }
        if (!m) break;
    }
    cout << 2 << " " << now << "\n";
    for (int i = 0; i < n; i++) {
        for (auto p : gr[i]) {
            cout << i + 1 << " " << p.first + 1 << " " << p.second << "\n";
        }
    }
}