#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, k;

struct Component {
    int sz;
    int maxp[11];
    int minp[11];
    bool operator<(const Component &v) const {
        for (int j = 0; j < k; j++) {
            if (maxp[j] > v.minp[j]) return false;
        }
        return true;
    }
};

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
    cin >> n >> k;
    set <Component> q;
    for (int i = 0; i < n; i++) {
        Component v;
        v.sz = 1;
        for (int j = 0; j < k; j++) {
            cin >> v.maxp[j];
            v.minp[j] = v.maxp[j];
        }
        auto x = q.lower_bound(v);
        //cout << x->maxp.size() << "\n";
        auto y = q.upper_bound(v);
        while (x != y) {
            v.sz += x->sz;
            //cout << x->minp.size() << " " << x->maxp.size() << "\n";
            for (int j = 0; j < k; j++) {
                v.minp[j] = min(v.minp[j], x->minp[j]);
                v.maxp[j] = max(v.maxp[j], x->maxp[j]);
            }
            q.erase(x++);
        }
        q.insert(v);
        cout << q.rbegin()->sz << "\n";
    }
}