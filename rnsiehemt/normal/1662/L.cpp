#include <bits/stdc++.h>
using namespace std;

struct RT {
    static constexpr long long Max = 1e18;
    struct Node {
        int v;
        int lc, rc;
    };
    vector<Node> nodes;

    RT() {
        nodes.push_back({(int)-1e9, 0, 0});
    }

    int create() {
        nodes.push_back({(int)-1e9, 0, 0});
        return (int) nodes.size() - 1;
    }

    void add(long long qi, int qv, int n = 0, long long nl = -Max, long long nr = Max) {
        //cout << qi << " " << qv << " " << n << " " << nl << " " << nr << endl;
        assert(nl <= qi && qi < nr);
        nodes[n].v = max(nodes[n].v, qv);
        if (nl+1 < nr) {
            long long m = (nl+nr)/2;
            if (qi < m) {
                if (!nodes[n].lc) {
                    nodes[n].lc = create();
                }
                add(qi, qv, nodes[n].lc, nl, m);
            } else {
                if (!nodes[n].rc) {
                    nodes[n].rc = create();
                }
                add(qi, qv, nodes[n].rc, m, nr);
            }
        }
    }
    int query(long long ql, long long qr, int n = 0, long long nl = -Max, long long nr = Max) {
        if (ql <= nl && nr <= qr) {
            return nodes[n].v;
        } else {
            int res = -1e9;
            long long m = (nl+nr)/2;
            if (ql < m && nodes[n].lc) {
                res = max(res, query(ql, qr, nodes[n].lc, nl, m));
            }
            if (m < qr && nodes[n].rc) {
                res = max(res, query(ql, qr, nodes[n].rc, m, nr));
            }
            return res;
        }
    }
} rt;

int main() {
    int N;
    long long V;
    cin >> N >> V;
    vector<long long> t(N);
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<pair<long long, long long>> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = {a[i] + V*t[i], -(a[i] - V*t[i])};
    }
    p.emplace_back(0ll, 0ll);
    sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < (int) p.size(); i++) {
        if (p[i].first == 0ll && p[i].second == 0ll) {
            rt.add(0, 0);
            //cout << "zero" << endl;
        } else {
            int cur = rt.query(-RT::Max, p[i].second + 1);
            //cout << p[i].first << " " << p[i].second << " " << cur << endl;
            ans = max(ans, cur+1);
            rt.add(p[i].second, cur+1);
        }
    }
    cout << ans << endl;
}