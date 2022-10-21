#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> P;
typedef vector<int> vi;
const int N = (int)5e5 + 50, INF = (int)1e9;

struct edge {
    int a, b, w, id;
};

int n, m, w;
vector<edge> es, ps;
int f[N];

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
bool same(int u, int v) {return find(u) == find(v);}
bool unite(int u, int v) {
    if(same(u, v)) return false;
    f[find(u)] = find(v);
    return true;
}

pll solve(int off) {
    int pt = 0;
    int cnt = 0;
    ll sum = 0;
    iota(f, f + n, 0);
    for(auto &e : es) {
        while(pt < sz(ps) && ps[pt].w - off <= e.w) {
            if(!same(ps[pt].a, ps[pt].b)) {
//                cout << "try " << ps[pt].a << " " << ps[pt].b << endl;
                unite(ps[pt].a, ps[pt].b);
                sum += ps[pt].w - off;
                cnt++;
            }
            pt++;
        }
        if(!same(e.a, e.b)) {
            unite(e.a, e.b);
            sum += e.w;
        }
    }
    while(pt < sz(ps)) {
        if(!same(ps[pt].a, ps[pt].b)) {
            unite(ps[pt].a, ps[pt].b);
            sum += ps[pt].w - off;
            cnt++;
        }
        pt++;
    }
    rep(i, 0, n) {
        if(find(i) != find(0)) {
            cout << -1 << endl;
            exit(0);
        }
    }
    return {sum, cnt};
}

vi getbound(int off, int up) {
    iota(f, f + n, 0);
    int pi = 0, ei = 0;
    vi res;
    while(pi < sz(ps) || ei < sz(es)) {
//        cout << pi << ' ' << ei << endl;
        int cwt = min((pi < sz(ps) ? ps[pi].w - off : 2 * INF), (ei < sz(es) ? es[ei].w : 2 * INF));
        int pnxt = pi, enxt = ei;
        while(pnxt < sz(ps) && ps[pnxt].w - off == cwt) pnxt++;
        while(enxt < sz(es) && es[enxt].w == cwt) enxt++;
        int cnt = 0;

        rep(md, 0, 2) {
            if(md != up) rep(j, pi, pnxt) cnt += unite(ps[j].a, ps[j].b);
            else rep(j, ei, enxt) unite(es[j].a, es[j].b);
        }
        res.push_back(cnt);
        pi = pnxt;
        ei = enxt;
    }
//    for(int x : res) cout << x << " ";
//    cout << endl;
    return res;
}

vi construct(int off, vi &need) {
    iota(f, f + n, 0);
    int pi = 0, ei = 0, ni = 0;
    vi res;
    int tot = 0;
    while(pi < sz(ps) || ei < sz(es)) {
        int cwt = min((pi < sz(ps) ? ps[pi].w - off : 2 * INF), (ei < sz(es) ? es[ei].w : 2 * INF));
        int pnxt = pi, enxt = ei;
        while(pnxt < sz(ps) && ps[pnxt].w - off == cwt) pnxt++;
        while(enxt < sz(es) && es[enxt].w == cwt) enxt++;
        int cnt = 0;
        rep(j, pi, pnxt) {
            if(cnt < need[ni] && !same(ps[j].a, ps[j].b)) {
                cnt += unite(ps[j].a, ps[j].b);
                res.push_back(ps[j].id);
            }
        }
        rep(j, ei, enxt) {
            if(unite(es[j].a, es[j].b)) res.push_back(es[j].id);
        }
        pi = pnxt;
        ei = enxt;
        ni++;
        tot += cnt;
    }
//    cout << tot << endl;
    return res;
}

int getsum(vi &v) {
    int sum = 0;
    for(int nxt : v) sum += nxt;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> w;
    rep(i, 0, m) {
        int u, v, wt; cin >> u >> v >> wt; u--, v--;
        if(u == 0 || v == 0) ps.push_back({u, v, wt, i});
        else es.push_back({u, v, wt, i});
    }
    sort(all(ps), [](const edge &e1, const edge &e2) {
        return e1.w < e2.w;
    });
    sort(all(es), [](const edge &e1, const edge &e2) {
        return e1.w < e2.w;
    });

    ll l = -INF, r = INF, mid;
//    int off;
//    while(cin >> off) {
//        cout << solve(off).second << endl;
//    }
//    cout << l << endl;

    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(solve(mid).second >= w) r = mid;
        else l = mid;
    }

    auto p = solve(r);
    if(p.second < w || solve(l).second > w) {
        cout << -1 << '\n';
        return 0;
    }

    vi lb = getbound(r, 0), rb = getbound(r, 1);
    assert(getsum(lb) <= w);
    assert(getsum(rb) >= w);

    vi need = lb;
    int sum = getsum(lb);
    rep(i, 0, sz(need)) {
        while(sum < w && need[i] < rb[i]) need[i]++, sum++;
    }

    cout << n - 1 << '\n';
    for(int id : construct(r, need)) cout << id + 1 << " ";
    cout << endl;

//    cout <<  p.first + w * r << '\n';

}