#include <bits/stdc++.h>

using namespace std;

struct internet {
    int al, ar;
    int rsum, minpsum;
    internet *left, *right;
    internet(int i, int j) : al(i), ar(j), rsum(0), minpsum(0), left(nullptr), right(nullptr) {
        if (i != j) {
            int k = (i + j) / 2;
            left = new internet(i, k);
            right = new internet(k + 1, j);
        }
    }
    void combine() {
        rsum = left->rsum + right->rsum;
        minpsum = min(left->minpsum, right->minpsum + left->rsum);
    }
    void change(int i, int d) {
        if (i < al || ar < i) return;
        else if (al == ar) {
            rsum += d;
            minpsum += d;
        } else {
            left->change(i, d); right->change(i, d); combine();
        }
    }
};

int solve() {
    int n; scanf("%d", &n);
    vector<bool> isInB(2 * n);
    vector<int> b, notb;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x); --x;
        b.push_back(x);
        isInB[x] = true;
    }
    for (int i = 2*n - 1; i >= 0; --i) if (!isInB[i]) notb.push_back(i);
    internet person10(0, 2*n-1);
    internet bryceorz(0, 2*n-1);
    for (int i = 0; i < 2*n; ++i) person10.change(i, isInB[i] ? -1 : 1);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (person10.minpsum >= 0 && bryceorz.minpsum >= 0) ++ans;
        if (i == n) break;
        person10.change(b[i], 1);
        person10.change(notb[i], -1);
        bryceorz.change(b[i], 1);
        bryceorz.change(notb[i], -1);
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}