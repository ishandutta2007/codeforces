#include <bits/stdc++.h>

using namespace std;
#define int long long


struct segment_tree{
    vector<int> tree;
    vector<int> pos;
    int n;

    segment_tree() {
        tree = {};
        pos = {};
        n = 0;
    }

    void build(int v, int l, int r) {
        if (l == r - 1) {
            pos[l] = v;
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m, r);
    }

    segment_tree(int sz) {
        tree.assign(sz * 4, 0);
        pos.assign(sz, 0);
        n = sz;
        build(1, 0, n);
    }

    void upd(int p, int val) {
        int v = pos[p];
        tree[v] = val;
        v /= 2;
        while (v) {
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
            v /= 2;
        }
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return 0;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r + 1);
    }
};

int n;
vector<pair <int, int> > a;
vector<int> help;
int v;
void read() {
    cin >> n;
    cin >> v;
    a.resize(n);
    // for (auto &i : a)
    //     cin >> i.first >> i.second;
    // cin >> v;
    
    for (auto& i : a) {
        cin >> i.second;
    }
    for (auto& i : a) {
        cin >> i.first;
    }
}

int get_ans1(vector<int> a, int ind) {
    set<int> help;
    for (auto i : a)
        help.insert(i);
    help.insert(0);

    int cnt = 0;
    map <int, int> help2;
    for (auto i : help)
        help2[i] = cnt++;
    for (int i = 0; i < a.size(); i++)
        a[i] = help2[a[i]];

    /*cout << "ind = " << ind << endl;
    cout << "a = ";
    for (auto i : a)
        cout << i << " ";
    cout << endl;*/

    segment_tree tree(cnt);

    for (int i = 0; i < a.size(); i++) {
        int help = tree.get(0, a[i]);
        if (help > 0 || i == ind)
        tree.upd(a[i], help + 1);
    }

    return tree.tree[1];
}

int get_ans2(vector<int> a) {
    set<int> help;
    for (auto i : a)
        help.insert(i);
    int cnt = 0;
    map <int, int> help2;
    for (auto i : help)
        help2[i] = cnt++;   

    for (int i = 0; i < a.size(); i++)
        a[i] = help2[a[i]];

    segment_tree tree(cnt);

    for (int i = 0; i < a.size(); i++) {
        int help = tree.get(0, a[i]);
        tree.upd(a[i], help + 1);
    }

    return tree.tree[1];
}

bool check(pair <int, int> a, pair <int, int> b) {
    return abs(a.second - b.second) * v >= abs(a.first - b.first); 
}

int ans1, ans2;

void run() {
    bool flag = false;
    for (auto i : a) {
        flag |= (i == make_pair(0LL, 0LL));
    }

    auto b = a;
    if (!flag)
        a.push_back({0LL, 0LL});

    vector<pair <int, int> > c;
    for (auto i : a) {
        if (check(i, {0LL, 0LL}))
            c.push_back(i);
    }

    a.clear();
    for (int i = 0; i < c.size(); i++) {
        int x = c[i].first;
        int t = c[i].second;
        int p = -x + t * v;
        int q = x + t * v;
        a.push_back({p, q});
    }

    sort(a.begin(), a.end());

    int ind = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == make_pair(0LL, 0LL))
            ind = i;

    vector<int> help;
    for (auto i : a)
        help.push_back(i.second);


    ans1 = get_ans1(help, ind);
    if (!flag)
        ans1--;

    a.clear();
    for (int i = 0; i < n; i++) {
        int x = b[i].first;
        int t = b[i].second;
        int p = -x + t * v;
        int q = x + t * v;
        a.push_back({p, q});
    }

    sort(a.begin(), a.end());

    help.clear();

    for (auto i : a)
        help.push_back(i.second);

    ans2 = get_ans2(help);
}

void write() {
    // cout << ans1 << " " << ans2 << endl;
    cout << ans1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}