#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 18;

struct TNode {
    int L, R;
    TNode *left, *right;
    int min;
};

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, INF});
}

int safe_min(TNode *root) {
    if (!root) {
        return INF;
    }
    return root->min;
}

void relax(TNode *root) {
    if (!root) return;
    root->min = min(safe_min(root->left), safe_min(root->right));
}

TNode *build_tree(int L, int R, vector <int> &a) {
    TNode *root = new_node(L, R);
    if (R - L == 1) {
        root->min = a[L];
    } else {
        int M = (L + R) / 2;
        root->left = build_tree(L, M, a);
        root->right = build_tree(M, R, a);
        relax(root);
    }
    return root;
}

int get_min(TNode *root, int L, int R) {
    if (L >= root->R || root->L >= R) {
        return INF;
    }
    if (L <= root->L && root->R <= R) {
        return root->min;
    }
    return min(get_min(root->left, L, R), get_min(root->right, L, R));
}

int n, s;
vector <int> a;
vector <vector <int> > gr;
vector <vector <int> > lvls;
vector <vector <int> > mas;
vector <vector <TNode*> > data;
vector <int> pos;
vector <int> height;
vector <int> tin, tout;
int timer = 0;

void init() {
    a.resize(n);
    gr.resize(n);
    pos.resize(n, 0);
    height.resize(n);
    data.resize(LOGN);
    tin.resize(n, 0);
    tout.resize(n, 0);
}

void dfs(int v, int p, int h) {
    if (lvls.size() == h) {
        lvls.push_back({});
        mas.push_back({});
    }
    lvls[h].push_back(a[v]);
    mas[h].push_back(v);
    height[v] = h;
    tin[v] = ++timer;
    pos[v] = lvls[h].size() - 1;
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
    }
    tout[v] = ++timer;
}

int find_left(int v, int h) {
    if (h >= mas.size()) {
        return -INF;
    }
    //cout << "YAHOO!\n";
    int l = -1, r = mas[h].size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (tin[mas[h][mid]] < tin[v]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    //cout << "YAHOO2!\n";
    return r;
}

int find_right(int v, int h) {
    if (h >= mas.size()) {
        return -INF;
    }
    int l = -1, r = mas[h].size();
    //cout << "YAHOO!\n";
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (tout[mas[h][mid]] > tout[v]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << "YAHOO2!\n";
    return l;
}

int get_ans(int v, int k) {
    int left = pos[v], right = pos[v];
    int h = height[v];
    int ans = INF;
    for (int i = LOGN - 1; i >= 0; i--) {
        if ((1 << i) > k) continue;
        k -= (1 << i);
        if (left <= right && h < (int) lvls.size()) {
            ans = min(ans, get_min(data[i][h], left, right + 1));
        }
        h += (1 << i);
        left = find_left(v, h);
        right = find_right(v, h);
    }
//    if (left != -1 && right != -1 && h < lvls.size()) {
//        ans = min(ans, data[0][h].getMin(pos[left], pos[right]));
//    }
    return ans;
}

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
    cin >> n >> s;
    s--;
    init();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(s, -1, 0);
    for (int i = 0; i < (int) lvls.size(); i++) {
        data[0].push_back(build_tree(0, lvls[i].size(), lvls[i]));
    }
    for (int i = 1; i < LOGN; i++) {
        for (int h = 0; h < (int) lvls.size(); h++) {
            vector <int> lvl;
            int h1 = h + (1 << (i - 1));
            for (int v : mas[h]) {
                int lv = find_left(v, h1), rv = find_right(v, h1);
                //cout << lv << " " << rv << "\n";
                int now = get_min(data[i - 1][h], pos[v], pos[v] + 1);
                if (lv <= rv && h1 < (int) lvls.size()) {
                    now = min(now, get_min(data[i - 1][h1], lv, rv + 1));
                }
                lvl.push_back(now);
            }
            data[i].push_back(build_tree(0, lvl.size(), lvl));
        }
    }
    int last = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        int v = (p + last) % n + 1, k = (q + last) % n;
        v--;
        k++;
        last = get_ans(v, k);
        cout << last << "\n";
    }
}