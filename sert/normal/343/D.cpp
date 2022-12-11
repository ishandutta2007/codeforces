#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 rnd(rd());

struct ST {
    vector<bool> isEmpty;
    vector<bool> cancelEmpty;
    int sz;
    explicit ST(int sz = 0) {
        isEmpty = cancelEmpty = vector<bool>(sz * 4, false);
        this->sz = sz;
        build();
    }
    void build(int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        isEmpty[v] = true;
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
    }
    void push(int v) {
        if (!cancelEmpty[v]) return;
        if (v * 2 + 1 < sz * 4) { cancelEmpty[v * 2 + 1] = true; isEmpty[v * 2 + 1] = false; }
        if (v * 2 + 2 < sz * 4) { cancelEmpty[v * 2 + 2] = true; isEmpty[v * 2 + 2] = false; }
        cancelEmpty[v] = false;
    }
    void setSeg(int L, int R, bool empty, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (L >= r || l >= R) return;
        if (L <= l && r <= R) {
            isEmpty[v] = empty;
            cancelEmpty[v] = !empty;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        setSeg(L, R, empty, v * 2 + 1, l, m);
        setSeg(L, R, empty, v * 2 + 2, m, r);
        isEmpty[v] = isEmpty[v * 2 + 1] || isEmpty[v * 2 + 2];
    }
    bool hasSegEmpty(int L, int R, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (L >= r || l >= R) return false;
        if (L <= l && r <= R) return isEmpty[v];
        push(v);
        int m = (l + r) / 2;
        return hasSegEmpty(L, R, v * 2 + 1, l, m) || hasSegEmpty(L, R, v * 2 + 2, m, r);
    }
};

void dfs(int v, int pr, vector<vector<int>> &es, vector<int> &tin, vector<int> &tout, int &tme, vector<int> &parent) {
    tin[v] = tme++;
    parent[v] = pr;
    for (int w : es[v]) {
        if (w == pr) continue;
        dfs(w, v, es, tin, tout, tme, parent);
    }
    tout[v] = tme;
}

vector<pair<int, int>> E, Q;
vector<bool> solve() {
    int n, v1, v2, tme = 0;
    if (E.empty()) cin >> n;
    else n = E.size() + 1;
    vector<bool> ans;
    vector<vector<int>> es(n);
    vector<int> tin(n), tout(n);
    for (int i = 0; i < n - 1; i++) {
        if (E.empty()) {
            cin >> v1 >> v2;
            v1--;
            v2--;
        } else {
            v1 = E[i].first;
            v2 = E[i].second;
        }
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    vector<int> parent(n, -1);
    dfs(0, -1, es, tin, tout, tme, parent);
    int q, t, v;
    if (E.empty()) cin >> q;
    else q = Q.size();
    ST st(n);
    for (int i = 0; i < q; i++) {
        if (E.empty()) {
            cin >> t >> v;
            v--;
        } else {
            t = Q[i].first;
            v = Q[i].second;
        }
        if (t == 1) {
            if (st.hasSegEmpty(tin[v], tout[v]) && v != 0)
                st.setSeg(tin[parent[v]], tin[parent[v]] + 1, true);
            st.setSeg(tin[v], tout[v], false);
        }
        if (t == 2) st.setSeg(tin[v], tin[v] + 1, true);
        if (t == 3) {
            ans.push_back(!st.hasSegEmpty(tin[v], tout[v]));
            if (E.empty()) cout << (int)ans.back() << "\n";
        }
    }
    return ans;
}

void fillChildren(int v, int pr, vector<vector<int>> &es, vector<bool> &isFilled) {
    isFilled[v] = true;
    for (int w : es[v]) {
        if (w == pr) continue;
        fillChildren(w, v, es, isFilled);
    }
}

void initStress(int v, int pr, vector<vector<int>> &es, vector<int> &par) {
    par[v] = pr;
    for (int w : es[v]) {
        if (w == pr) continue;
        initStress(w, v, es, par);
    }
}

void emptyParents(int v, vector<int> &par, vector<bool> &isFilled) {
    while (v != -1) {
        isFilled[v] = false;
        v = par[v];
    }
}

vector<bool> stress() {
    int n = (int)E.size() + 1;
    vector<vector<int>> es(n);
    vector<int> par(n, -1);
    vector<bool> isFilled(n, false);
    for (const auto &[v1, v2] : E) {
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    initStress(0, -1, es, par);
    vector<bool> ans;
    for (const auto &[t, v] : Q) {
        if (t == 1) fillChildren(v, par[v], es, isFilled);
        if (t == 2) emptyParents(v, par, isFilled);
        if (t == 3) ans.push_back(isFilled[v]);
    }
    return ans;
}

void genTest(int n, int q) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;
    shuffle(perm.begin(), perm.end(), rnd);
    E.clear();
    for (int i = 1; i < n; i++) {
        E.emplace_back(perm[i], perm[rnd() % i]);
        if (rnd() % 2) swap(E.back().first, E.back().second);
    }
    shuffle(E.begin(), E.end(), rnd);

    Q.clear();
    for (int i = 0; i < q; i++)
        Q.emplace_back(rnd() % 2 + 1, rnd() % n);
    for (int i = 0; i < n; i++)
        Q.emplace_back(3, i);
}

template <typename T1, typename T2>
ostream& operator << (ostream &fo, pair<T1, T2> p) {
    fo << "(" << p.first << "," << p.second << ")";
    return fo;
}

template <typename T>
ostream& operator << (ostream &fo, vector<T> v) {
    fo << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) fo << " ";
        fo << v[i];
    }
    fo << "]";
    return fo;
}

void test(int n, int q) {
    int it = 0;
    while (clock() < CLOCKS_PER_SEC * 2.3) {
        it++;
        //cout << it << endl;
        genTest(n, q);
        auto a1 = stress();
        //cout << E << " " << Q << " " << a1 << endl;
        auto a2 = solve();
        if (a1 != a2) {
            cout << "fail at test # " << it << "\n";
            cout << E << "\n";
            cout << vector<pair<int, int>>(Q.begin(), Q.end() - n) << "\n";
            cout << "nid: " << a1 << "\n";
            cout << "hav: " << a2 << "\n";
            return;
        }
    }
    cout << it << " tests are ok\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 1;
    //test(10, 5);
    //return 0;
#endif
    while (t--) {
        solve();
    }
}