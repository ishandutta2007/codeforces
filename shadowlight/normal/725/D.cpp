#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 7;

struct TNode {
    long long L, R;
    TNode *left, *right;
    pair <long long, long long>  mink;
};

TNode *new_node (long long L, long long R) {
    return new TNode({L, R, (TNode*) NULL, (TNode*) NULL, {0, -1}});
}

vector <pair <long long, long long> > a;

pair <long long, long long> safe_min(TNode *root) {
    if (!root) return {INF, -1};
    return root->mink;
}

void relax(TNode *root) {
    if (!root) return;
    root->mink = min(safe_min(root->left), safe_min(root->right));
}

TNode *build_tree(long long L, long long R) {
    TNode *node = new_node(L, R);
    if (R - L == 1) {
        node->mink = a[L];
    } else {
        long long M = (L + R) / 2;
        node->left = build_tree(L, M);
        node->right = build_tree(M, R);
        relax(node);
    }
    return node;
}

pair <long long, long long> get_min(TNode *root, long long L, long long R) {
    if (L >= root->R || R <= root->L) {
        return {INF, -1};
    }
    if (L <= root->L && root->R <= R) {
        return root->mink;
    }
    return min(get_min(root->left, L, R), get_min(root->right, L, R));
}

void change_elem(TNode *root, long long x) {
    if (!root) return;
    if (root->L > x || root->R <= x) {
        return;
    }
    if (root->R - root->L == 1) {
        root->mink = {INF, -1};
        return;
    }
    change_elem(root->left, x);
    change_elem(root->right, x);
    relax(root);
}
int main() {
    long long n;
    cin >> n;
    vector <pair <long long, long long> > data;
    long long now, w;
    cin >> now >> w;
    for (long long i = 0; i < n - 1; i++) {
        long long l, r;
        cin >> l >> r;
        data.push_back({l, r});
    }
    sort(data.begin(), data.end());
    vector <long long> b;
    for (long long i = 0; i < n - 1; i++) {
        b.push_back(data[i].first);
        a.push_back({data[i].second - data[i].first + 1, i});
    }
    TNode *root = build_tree(0, n - 1);
    long long best_place = INF;
    long long ud = 0;
    while (now >= 0) {
        long long k = upper_bound(b.begin(), b.end(), now) - b.begin();
        //cout << k << endl;
        best_place = max((long long) 1, min(best_place, n - k - ud));
        ud++;
        //cout << best_place << endl;
        /*for (long long i = k; i < n - 1; i++) {
            cout << a[i].first  << " " << a[i].second << endl;
        }*/
        //cout << endl;
        pair <long long, long long> p = get_min(root, k, n - 1);
        //cout << p.first << " " << p.second << endl;
        now -= p.first;
        //cout << now << endl;
        change_elem(root, p.second);
    }
    cout << best_place;
}