#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

tuple<int, int, int, int> classify(
        array<int, 3> &a, array<int, 3> &b, array<int, 3> &v) {
    int out = 0, od = -1, id = -1, m = 0;
    for (int j = 0; j < 3; j++) {
        if (v[j] < a[j] || v[j] > b[j]) {
            out++;
            od = j;
        } else {
            id = j;
        }
        m |= (v[j] > b[j]) << j;
    }
    return { out, od, id, m };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int D[3], N, M, K;
    cin >> D[0] >> D[1] >> D[2] >> N >> M >> K;

    array<int, 3> a = { D[0]+1, D[1]+1, D[2]+1 },
                  b = { 0, 0, 0 };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int v;
            cin >> v;
            a[j] = min(a[j], v);
            b[j] = max(b[j], v);
        }
    }

    int out, od, id, m;
    vector<pair<array<int, 3>, int>> pts[8];

    int l[3] = { 0, 0, 0 },
        r[3] = { D[0]+1, D[1]+1, D[2]+1 };
    for (int i = 0; i < M; i++) {
        array<int, 3> v;
        cin >> v[0] >> v[1] >> v[2];
        tie(out, od, id, m) = classify(a, b, v);

        if (out == 0) {
            cout << "INCORRECT\n";
            return 0;
        }
        else if (out == 1) {
            if (v[od] < a[od])
                l[od] = max(l[od], v[od]);
            else
                r[od] = min(r[od], v[od]);
        } else if (out == 2) {
                v[id] = D[id]+1;
                pts[m].emplace_back(v, -1);
                v[id] = 0;
                pts[m | (1 << id)].emplace_back(v, -1);
        } else {
            pts[m].emplace_back(v, -1);
        }
    }

    vector<array<int, 3>> que(K);
    vi ans(K); // 0=unknown, 1=open, 2=closed

    for (int i = 0; i < K; i++) {
        array<int, 3> v;
        cin >> v[0] >> v[1] >> v[2];
        tie(out, od, id, m) = classify(a, b, v);

        for (int j = 0; j < 3; j++) {
            if (v[j] <= l[j] || v[j] >= r[j])
                ans[i] = 2;
        }
        if (out == 0) {
            ans[i] = 1;
        }
        if (ans[i] || (out == 1)) continue;

        if (out == 2) {
            v[id] = D[id]+1;
        }
        pts[m].emplace_back(v, i);
    }

    for (int m = 0; m < 8; m++) {
        for (auto &e : pts[m]) {
            for (int j = 0; j < 3; j++)
                if ((m>>j)&1)
                    e.first[j] = D[j]+1 - e.first[j];
        }
        sort(all(pts[m]), [&](auto &x, auto &y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        map<int, int> pf;
        pf[0] = D[2]+1;
        pf[D[1]+1] = 0;
        for (auto e : pts[m]) {
            int y = e.first[1], z = e.first[2];
            if (e.second == -1) {
                auto it = pf.lower_bound(y);
                if (it->second >= z) continue;
                set<int> del;
                while (it != pf.begin()) {
                    it = prev(it);
                    if (it->second <= z) del.insert(it->first);
                }
                for (int k : del) pf.erase(k);
                pf[y] = z;
            } else {
                auto it = pf.lower_bound(y);
                if (it != pf.end() && it->second >= z)
                    ans[e.second] = 2;
            }
        }
    }

    cout << "CORRECT\n";
    for (int i = 0; i < K; i++) {
        if (ans[i] == 0) cout << "UNKNOWN\n";
        else if (ans[i] == 1) cout << "OPEN\n";
        else cout << "CLOSED\n";
    }
    return 0;
}