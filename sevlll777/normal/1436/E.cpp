#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
int tree[2000009];
int C = 131072;

void change(int v, int l, int r, int pos, int x) {
    if (l > pos || r <= pos) return;
    if (l == pos && r - l == 1) {
        tree[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (pos < m) {
        change(2 * v + 1, l, m, pos, x);
    } else {
        change(2 * v + 2, m, r, pos, x);
    }
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

int elem(int v, int l, int r, int pos) {
    if (l == pos && r - l == 1) return tree[v];
    int m = (l + r) / 2;
    if (pos < m) {
        return elem(2 * v + 1, l, m, pos);
    } else {
        return elem(2 * v + 2, m, r, pos);
    }
}

int mini(int v, int l, int r, int lq, int rq) {
    if (rq <= l || lq >= r || r <= l) return 1000000000;
    if (l >= lq && rq >= r) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return min(mini(2 * v + 1, l, m, lq, rq), mini(2 * v + 2, m, r, lq, rq));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n+1);
    bool huh = true;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] != 1) huh = false;
    }
    if (huh) {
        cout << "1\n";
        exit(0);
    }
    for (int i = 0; i < 1000000; i++) tree[i] = -1;
    vector<bool> CANI(n + 3, false);
    for (int i = 1; i <= n; i++) {
        change(0, 0, C, A[i], i);
        if (i != n) {
            int x = A[i + 1];
            int mem = mini(0, 0, C, 1, x);
            int el = elem(0, 0, C, x);
            if (el < mem) {
                CANI[x] = true;
            }
        } else {
            for (int x = 1; x <= n+1; x++) {
                int mem = mini(0, 0, C, 1, x);
                int el = elem(0, 0, C, x);
                if (el < mem) {
                    CANI[x] = true;
                }
            }
        }
    }
    for (int i = 2; i <= n+2; i++) {
        if (!CANI[i]) {
            cout << i << '\n';
            exit(0);
        }
    }

}