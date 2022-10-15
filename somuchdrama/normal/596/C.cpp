#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5;
int w[MAXN];
pii on[MAXN + MAXN + 1];

bool operator <(const pii & a, const pii & b) {
    return (a.ss <= b.ss && a.ff <= b.ff);
}

set<pii> from, all;
set<int> ww;

pii ans[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        all.insert({a, b});
    }

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        w[i] += MAXN;
    }

    from.insert({0,0});
    ww.insert(MAXN);
    on[0] = {0,0};

    int pos = 0;

    while (!from.empty()) {
        if (ww.count(w[pos])) {
            ww.erase(w[pos]);
            ans[pos] = on[w[pos]];
            from.erase(on[w[pos]]);
            pii to = {on[w[pos]].ff + 1, on[w[pos]].ss};
            if (all.count(to)) {
                from.insert(to);
                ww.insert(w[pos] - 1);
                on[w[pos] - 1] = to;
            }
            to = {on[w[pos]].ff, on[w[pos]].ss + 1};
            if (all.count(to)) {
                from.insert(to);
                ww.insert(w[pos] + 1);
                on[w[pos] + 1] = to;
            }
        } else {
            cout << "NO\n";
            return 0;
        }
        ++pos;
    }

    if (pos != n) {
        cout << "NO\n";
        return 0;        
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i].ff << ' ' << ans[i].ss << '\n';

    return 0;
}