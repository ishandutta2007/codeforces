#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }


int n, m, k;
VV<int> g, rg;
V<int> a, lw, hi;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    g = VV<int>(n);
    rg = VV<int>(n);

    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    {
        //lower bound
        V<int> deg = V<int>(n);
        queue<int> q;

        lw = V<int>(n, 1);
        for (int i = 0; i < n; i++) {
            deg[i] = int(g[i].size());
            if (!deg[i]) {
                q.push(i);
            }
        }
        int c = 0;
        while (q.size()) {
            c++;
            int i = q.front(); q.pop();
            if (a[i] != 0) {
                if (a[i] < lw[i]) {
                    cout << -1 << endl;
                    return 0;
                }
                lw[i] = a[i];
            }
            for (int j: rg[i]) {
                lw[j] = max(lw[j], lw[i]+1);
                deg[j]--;
                if (!deg[j]) {
                    q.push(j);
                }
            }
        }
        if (c != n) {
            cout << -1 << endl;
            return 0;
        }
    }

    {
        //upper bound
        V<int> deg = V<int>(n);
        queue<int> q;

        hi = V<int>(n, k);
        for (int i = 0; i < n; i++) {
            deg[i] = int(rg[i].size());
            if (!deg[i]) {
                q.push(i);
            }
        }

        while (q.size()) {
            int i = q.front(); q.pop();
            if (a[i] != 0) {
                if (hi[i] < a[i]) {
                    cout << -1 << endl;
                    return 0;
                }                
                hi[i] = a[i];
            }
            for (int j: g[i]) {
                hi[j] = min(hi[j], hi[i]-1);
                deg[j]--;
                if (!deg[j]) {
                    q.push(j);
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
//        cout << lw[i] << ", " << hi[i] << endl;
        if (hi[i] < lw[i]) {
            cout << -1 << endl;
            return 0;
        }
    }   

    VV<int> ev(k+1);
    for (int i = 0; i < n; i++) {
        ev[lw[i]].push_back(i);
    }

    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    V<int> res(n);
    for (int h = 1; h <= k; h++) {
        for (int i: ev[h]) {
            pq.push(P(hi[i], i));
        }
        if (pq.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        res[pq.top().second] = h; pq.pop();
        while (pq.size()) {
            auto p = pq.top();
            if (h < p.first) break;
            res[p.second] = h; pq.pop();
        }
    }

    for (int d: res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}