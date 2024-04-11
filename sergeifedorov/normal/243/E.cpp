#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()

const int nmax = 600;

void no() {
    puts("NO");
    exit(0);
}

struct tree {
    vector<int> h, res, us, ord;
    vector<tree*> g;
    tree *lft, *rgt, *p;
    vector<vector<pair<int, tree*> > > e;

    void init() {
        e.resize(g.size());
        us.resize(g.size());
        lft = rgt = 0;
        forn(i, g.size())
            g[i]->init();
    }

    tree () {};

    tree(int n) {
        p = 0;
        forn(i, n) h.pb(i);
        forn(i, n) g.pb(new tree(i, this));
    }

    tree(int n, tree *pr) : p(pr) {
        h.pb(n);
    }

    tree(const vector<tree*> & e, tree *p) : g(e), p(p) {
        forn(i, g.size()) {
            g[i]->p = this;
            forn(j, g[i]->h.size())
                h.pb(g[i]->h[j]);
        }
    }

    int getNum(tree *v) {
        forn(i, g.size())
            if (g[i] == v) return i;
        return -1;  
    }

    void paintR(tree *v, tree *pv) {
        while (v != pv) {
            if (v->p->rgt != 0) return;
            v->p->rgt = v;
            v = v->p;
        }
    }

    void paintL(tree *v, tree *pv) {
        while (v != pv) {
            if (v->p->lft != 0) return;
            v->p->lft = v;
            v = v->p;
        }
    }

    void add(tree *pv, tree *pu, tree *v, tree *u) {
        e[getNum(pv)].pb(mp(getNum(pu), u));    
        e[getNum(pu)].pb(mp(getNum(pv), v));    
    }

    void dfs(int v, vector<int> &st) {
        if (us[v]) return;
        st.pb(v);
        us[v] = 1;
        forn(i, e[v].size())
            dfs(e[v][i].fs, st);
    }

    vector<int> getOrder() {
        vector<int> st, en;
        if (getNum(lft) != -1) dfs(getNum(lft), st);
        if (getNum(rgt) != -1) dfs(getNum(rgt), en);
        forn(i, g.size()) {
            bool done = 1;
            forn(j, e[i].size() - 1)
                if (e[i][j].fs != e[i][j+1].fs) done = 0;
            if (done)
                dfs(i, st);
        }
        forn(i, g.size())
            dfs(i, st);
        ford(i, en.size())
            st.pb(en[i]);
        return st;
    }

    void solve() {
        if (g.size() == 0) {
            res = h;
            return;
        }
        ord = getOrder();
        forn(i, ord.size() - 1) {
            int v = ord[i], u = ord[i+1];
            forn(j, e[v].size())
                if (e[v][j].fs == u) 
                    paintL(e[v][j].sc, this);
            forn(j, e[u].size())
                if (e[u][j].fs == v) 
                    paintR(e[u][j].sc, this);
        }
        forn(i, ord.size()) {
            g[ord[i]]->solve();
            forn(j, g[ord[i]]->res.size())
                res.pb(g[ord[i]]->res[j]);
        }
    }
};

typedef tree* ptree;

int n;
char a[nmax][nmax], b[nmax][nmax];
ptree root;

void calcF(ptree v, int idx, bool &f1, bool &f2) {
    f1 = f2 = 1;
    forn(i, v->h.size()) {
        if (a[idx][v->h[i]] == '1') 
            f1 = 0;
        else
            f2 = 0;
        if (!f1 && !f2) return;
    }
}

bool update(ptree v, int idx) {
    bool f1, f2;
    calcF(v, idx, f1, f2);
    if (f1) return 0;
    if (f2) return 1;
    vector<ptree> ng;
    bool done = 1;
    forn(i, v->g.size()) 
        if (update(v->g[i], idx)) 
            ng.pb(v->g[i]);
        else 
            done = 0;
    if (done) return 1;
    if (ng.size() <= 1) return 0;
    int m = 0, j = 0;
    forn(i, v->g.size()) {
        while (j < ng.size() && v->g[i] == ng[j]) j ++, i ++;
        if (i < v->g.size()) v->g[m++] = v->g[i];
    }
    v->g.resize(m);
    v->g.pb(new tree(ng, v));
    return 0;
}

ptree process (ptree v, int idx) {
    bool f1, f2;
    calcF(v, idx, f1, f2);
    if (f1) return 0;
    if (f2) return v;
    vector<pair<ptree, ptree> > tc;
    forn(i, v->g.size()) {
        ptree buf = process (v->g[i], idx);
        if (buf != 0)
            tc.pb(mp(buf, v->g[i]));
    }
    if (tc.size() == 1) return tc[0].fs;
    if (tc.size() >= 4) no();
    if (tc.size() == 3) {
        forn(i, 2)
            if (tc[1+i].fs == tc[1+i].sc) swap(tc[0], tc[1+i]);
        if (tc[0].fs != tc[0].sc) no();
    }
    for (int i = 1; i < (int)tc.size(); i ++)
        v->add(tc[0].sc, tc[i].sc, tc[0].fs, tc[i].fs);
    forn(i, tc.size())
        if (tc[i].fs == tc[i].sc) return tc[i].fs;
    return 0;
}

bool check() {
    forn(i, n) {
        int cnt = b[i][0] - '0';
        forn(j, n - 1)
            if (b[i][j] == '0' && b[i][j+1] == '1')
                cnt ++;
        if (cnt > 1) return 0;
    }
    return 1;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    scanf("%d\n", &n);
    root = new tree(n);
    forn(i, n) {
        gets(a[i]);
        update(root, i);
    }
    root->init();
    forn(i, n) 
        process(root, i);
    root->solve();

    vector<int> res = root->res;
    forn(i, n)
        forn(j, n)
            b[i][j] = a[i][res[j]];
    if (!check()) no();
    puts("YES");
    forn(i, n) 
        puts(b[i]);
    return 0;
}