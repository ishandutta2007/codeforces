#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e5 + 34;
const int DEF = 0;

struct Node {
    int mx;
    Node *l, *r;

    Node(int x = DEF) {
        mx = x;
        l = r = nullptr;
    }

    void make_childs() {
        l = new Node();
        r = new Node();
    }
};

void add(Node *v, int l, int r, int p, int x) {
    if (l + 1 == r) {
        v->mx = max(v->mx, x);
        return;
    }
    int m = (l + r) / 2;
    if (v->l == nullptr) v->make_childs();
    if (p < m) add(v->l, l, m, p, x);
    else add(v->r, m, r, p, x);
    v->mx = max(v->l->mx, v->r->mx);
}

int getMax(Node *v, int l, int r, int L, int R) {
    if (v == nullptr || L >= r || l >= R) return DEF;
    if (L <= l && r <= R) return v->mx;
    int m = (l + r) / 2;
    return max(getMax(v->l, l, m, L, R), getMax(v->r, m, r, L, R));
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Node*> st;
    for (int i = 0; i < n; i++) st.push_back(new Node());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        a--;
        b--;
        int ma = getMax(st[a], 0, N, 0, x);
        ///int mb = getMax(st[b], 0, N, 0, x);
        int val = ma + 1;
        //cerr << a << " " << b << " " << x << "\n";
        //cerr << ma << " " << val << " " << st[3]->mx << "\n\n";
        ans = max(ans, val);
        ///add(st[a], 0, N, x, val);
        add(st[b], 0, N, x, val);
    }
    printf("%d\n", ans);
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}