#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

struct TNode {
    int L, R;
    TNode *left, *right;
    int sum;
};

TNode *new_node(int l, int r) {
    return new TNode({l, r, nullptr, nullptr, 0});
}

int safe_sum(TNode *root) {
    if (!root) {
        return 0;
    }
    return root->sum;
}

void relax(TNode *root) {
    if (!root) return;
    root->sum = safe_sum(root->left) + safe_sum(root->right);
}

TNode *build_tree(int L, int R) {
    TNode *root = new_node(L, R);
    if (R - L > 1) {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    } else {
        root->sum = 1;
    }
    return root;
}

void change(TNode *root, int p) {
    if (root->L > p || root->R <= p) {
        return;
    }
    if (root->R - root->L == 1) {
        root->sum = 0;
        return;
    }
    change(root->left, p);
    change(root->right, p);
    relax(root);
}

int get_sum(TNode *root, int L, int R) {
    if (root->L >= R || L >= root->R) {
        return 0;
    }
    if (L <= root->L && root->R <= R) {
        return root->sum;
    }
    return get_sum(root->left, L, R) + get_sum(root->right, L, R);
}

int force(TNode *root, int p, int sum) {
    if (root->R - root->L == 1) {
        return root->L;
    }
    if (sum + safe_sum(root->left) > p) {
        return force(root->left, p, sum);
    } else {
        return force(root->right, p, sum + safe_sum(root->left));
    }
}

int n, m;


int get(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if (c >= 'A' && c <= 'Z') {
        return Q + c - 'A';
    }
    return 2 * Q + c - '0';
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
    cin >> n >> m;
    TNode *root = build_tree(0, n);
    vector <set <int> > a(3 * Q);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[get(s[i])].insert(i);
    }
    set <int> exist;
    for (int i = 0; i < n; i++) {
        exist.insert(i);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        l--, r--;
        l = force(root, l, 0), r = force(root, r, 0);
        //cout << l << " " << r << "\n";
        int k = get(c);
        auto it = a[k].lower_bound(l);
        vector <int> erased;
        while (it != a[k].end() && *it <= r) {
            erased.push_back(*it);
            it++;
        }
        for (int x : erased) {
            exist.erase(x);
            a[k].erase(x);
            change(root, x);
        }
    }
    string s1 = "";
    for (int x : exist) {
        s1 += s[x];
    }
    cout << s1;
}