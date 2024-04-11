#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

void condense(vvi &g, vb &c, vi &inx, auto &res, vi &w, vi &d, int loc, int anc) {
    w[loc] += !c[loc];
    d[loc]++;
    if (inx[loc] != -1 && anc != -1) {
        res[inx[anc]].push_back({inx[loc],
                w[loc] - w[anc] - !c[loc], d[loc] - d[anc] - 1});
    }
    for (int nbr : g[loc]) {
        w[nbr] = w[loc];
        d[nbr] = d[loc];
        condense(g, c, inx, res, w, d, nbr, inx[loc] != -1 ? loc : anc);
    }
}

void mark_black(auto &cg, vi &in, vb &c, vb &mw, vi &mb, int loc) {
    mb[loc]++;
    bool eats = !c[in[loc]] || mw[loc];
    for (auto e : cg[loc])
        if (mb[loc] > e[1 + mw[loc]] + eats)
            mark_black(cg, in, c, mw, mb, e[0]);
}

void mark_white(auto &cg, vb &mw, vi &mb, int loc) {
    mw[loc] = true, mb[loc] = 0;
    for (auto e : cg[loc])
        mark_white(cg, mw, mb, e[0]);
}

void recolor(auto &g, vb &c, vi &inx, vb &mw, vi &mb,
        bool pmw, int pmb, int loc) {
    if (inx[loc] != -1) {
        pmw = mw[inx[loc]];
        pmb = mb[inx[loc]];
    }
    if (pmw) c[loc] = false;
    if (pmb && !c[loc]) {
        pmb--;
        c[loc] = true;
    }
    for (int nbr : g[loc]) {
        recolor(g, c, inx, mw, mb, pmw, pmb, nbr);
    }
}

void solve(int N, vvi &g, vb &c, vb &a, vi t, vi v) {
    vi in = v, w(N), d(N), inv(N, -1);
    sort(all(in));
    in.erase(unique(all(in)), in.end());
    for (int i = 0; i < in.size(); i++)
        inv[in[i]] = i;

    int CN = in.size();
    vector<vector<array<int, 3>>> cg(CN);
    condense(g, c, inv, cg, w, d, 0, -1);

    vb mw(CN);
    vi mb(CN);
    for (int q = 0; q < t.size(); q++) {
        switch(t[q]) {
            case 1:
                mark_black(cg, in, c, mw, mb, inv[v[q]]);
                break;
            case 2:
                mark_white(cg, mw, mb, inv[v[q]]);
                break;
            case 3:
                a.push_back(mb[inv[v[q]]] || (c[v[q]] && !mw[inv[v[q]]]));
                break;
            default:
                assert(false);
        }
    }

    recolor(g, c, inv, mw, mb, false, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    vvi g(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        g[p-1].push_back(i);
    }

    vb c(N), a;
    vi t, v;

    const int BLOCK = 700;
    for (int i = 0; i < Q; i++) {
        int _t, _v;
        cin >> _t >> _v;
        t.push_back(_t);
        v.push_back(_v - 1);

        if (t.size() == BLOCK || (i + 1) == Q) {
            solve(N, g, c, a, t, v);
            t.clear();
            v.clear();
        }
    }

    for (bool r : a)
        cout << (r ? "black" : "white") << "\n";
    return 0;
}