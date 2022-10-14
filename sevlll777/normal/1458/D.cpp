#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int N = 2048 * 2048;
int tree[N], tree2[N];


void update(int v, int l, int r, int j, int x) {
    if (l >= r) return;
    int m = (l + r) / 2;
    if (l + 1 == r && l == j) {
        tree[v] += x;
        tree2[v] += x;
        return;
    } else if (m > j) {
        update(2 * v + 1, l, m, j, x);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        tree2[v] = tree2[2 * v + 1] + tree2[2 * v + 2];
    } else {
        update(2 * v + 2, m, r, j, x);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        tree2[v] = tree2[2 * v + 1] + tree2[2 * v + 2];
    }
}

void obnulyay(int v, int l, int r) {
    int m = (l + r) / 2;
    if (l >= r) return;
    tree[v] = 0;
    tree2[v] = 0;
    if (l + 1 == r) {
        return;
    }
    obnulyay(2 * v + 1, l, m);
    obnulyay(2 * v + 2, m, r);
}

int mini(int v, int tl, int tr, int l, int r) {
    if (l >= r || l >= tr || r <= tl) {
        return 1e9;
    } else if (l + 1 == r) {
        return tree[v];
    } else if (tl <= l && r <= tr) {
        return tree[v];
    } else {
        int m = (l + r) / 2;
        return min(mini(2 * v + 1, tl, tr, l, m), mini(2 * v + 2, tl, tr, m, r));
    }
}

int sus(int v, int tl, int tr, int l, int r) {
    if (l >= r || l >= tr || r <= tl) {
        return 0;
    } else if (l + 1 == r) {
        return tree2[v];
    } else if (tl <= l && r <= tr) {
        return tree2[v];
    } else {
        int m = (l + r) / 2;
        return (sus(2 * v + 1, tl, tr, l, m) + sus(2 * v + 2, tl, tr, m, r));
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        int NN = (int) (pow(2, ceil(log2(4 * n + 16))));
        vector<int> cnt(2 * n + 1);
        obnulyay(0, 0, NN);
        int b = 0;
        update(0, 0, NN, b + n, 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                b--;
            } else {
                b++;
            }
            update(0, 0, NN, b + n, 1);
            cnt[b + n - (s[i] - '0')]++;
        }
        int start = n;
        string ans = "";
        for (int i = 0; i < n; i++) {
            update(0, 0, NN, start, -1);
            int mem = 1;
            if (start > 0) {
                int cc = cnt[start - 1];
                if ((cc == 0) || ((cc == 1) && (sus(0, start, NN, 0, NN) > 0))) {
                    mem = 0;
                } else {
                    mem = 1;
                }
            } else {
                mem = 0;
            }
            if (mem == 1) {
                ans += '0';
                start--;
                cnt[start]--;
            } else {
                ans += '1';
                cnt[start]--;
                start++;
            }
        }
        cout << min(s, ans) << '\n';
    }
}