#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> p, r;

ll get(ll v) {
    if (v == p[v]) return v;
    return p[v] = get(p[v]);
}

bool uni(ll v, ll u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
    if (r[v] == r[u]) r[u]++;
    if (r[v] > r[u]) {
        swap(v, u);
    }
    p[v] = u;
    return true;
}

const int Q = 31;

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
    p.resize(Q, 0);
    r.resize(Q, 0);
    for (int i = 0; i < Q; i++) {
        p[i] = i;
    }
    string s, t;
    cin >> s >> t;
    vector <pair <int, int> > a;
    for (int i = 0; i < n; i++) {
        int v = s[i] - 'a', u = t[i] - 'a';
        if (uni(v, u)) {
            a.push_back({v, u});
        }
    }
    cout << a.size() << "\n";
    for (auto p : a) {
        cout << (char) (p.first + 'a') << " " << (char) (p.second + 'a') << "\n";
    }
}