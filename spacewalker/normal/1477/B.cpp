#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 300000;

struct NezzarTree {
    int al, ar;
    int zc, lazy; // lazy = -1 if set zero, 0 if nothing, 1 if set one
    NezzarTree *left, *right;
    void combine() {
        zc = left->zc + right->zc;
    }
    void propagate() {
//        if (lazy != 0) printf("lazy was set to %d in %d %d\n", lazy, al, ar);
        if (lazy == 1) {
            zc = 0;
            if (left != nullptr) left->lazy = right->lazy = 1;
        }
        if (lazy == -1) {
            zc = ar - al + 1;
            if (left != nullptr) left->lazy = right->lazy = -1;
        }
        lazy = 0;
    }
    NezzarTree(int i, int j, const char *s) :
        al(i), ar(j), zc(0), lazy(0), left(nullptr), right(nullptr) {
        if (i == j) {
            zc = (s[i] == '0' ? 1 : 0);
        } else {
            int k = (i + j) / 2;
            left = new NezzarTree(i, k, s);
            right = new NezzarTree(k + 1, j, s);
            combine();
        }
    }
    int countZeroes(int i, int j) {
        propagate();
        if (i <= al && ar <= j) return zc;
        else if (ar < i || j < al) return 0;
        else return left->countZeroes(i, j) + right->countZeroes(i, j);
    }
    void setTo(int i, int j, int v) {
        propagate();
        if (i <= al && ar <= j) {
            lazy = (v == 1 ? 1 : -1);
            propagate();
        } else if (ar < i || j < al) return;
        else {
            left->setTo(i, j, v); right->setTo(i, j, v);
            combine();
        }
    }
    bool checkIfEqual(const char *s) {
        propagate();
        if (al == ar) return (zc == 1) == (s[al] == '0');
        else return left->checkIfEqual(s) && right->checkIfEqual(s);
    }
    void debug() {
        propagate();
        if (al == ar) printf("%d", 1 - zc);
        else {
            left->debug();
            right->debug();
        }
    }
};

bool solve() {
    static char s[NMAX], t[NMAX];
    int n, q; scanf("%d %d", &n, &q);
    scanf("%s", s);
    scanf("%s", t);
    vector<pair<int, int>> insp(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &insp[i].first, &insp[i].second);
        --insp[i].first; --insp[i].second;
    }
    NezzarTree chk(0, n-1, t);
    reverse(begin(insp), end(insp));
    for (auto [a, b] : insp) {
        int zc = chk.countZeroes(a, b);
        int oc = b - a + 1 - zc;
//        printf("%d-%d balance in %d %d\n", zc, oc, a, b);
        if (oc == zc) return false;
        if (oc > zc) chk.setTo(a, b, 1);
        else chk.setTo(a, b, 0);
//        chk.debug();
//        printf("\n");
    }
//    printf("making final check:\n");
    return chk.checkIfEqual(s);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}