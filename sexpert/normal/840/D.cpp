#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct wnode {
    int lo, hi;
    wnode *left, *right;
    vi cleft;

    wnode(int lo, int hi, int* st, int* en) : lo(lo), hi(hi) {
        if(lo == hi || st == en) return;
        int mi = (lo + hi)/2;
        auto f = [mi](int x) { return x <= mi; };
        cleft.push_back(0);
        for(auto it = st; it != en; ++it) cleft.push_back(cleft.back() + f(*it));
        auto it = stable_partition(st, en, f);
        left = new wnode(lo, mi, st, it);
        right = new wnode(mi + 1, hi, it, en);
    }

    int maj(int L, int R, int bnd) {
        if(R - L + 1 <= bnd)
            return -1;
        if(lo == hi)
            return lo;
        int izq = cleft[L - 1], der = cleft[R];
        int lans = left->maj(izq + 1, der, bnd);
        if(lans != -1) return lans;
        return right->maj(L - izq, R - der, bnd);
    }
};

const int MAXN = 3e5 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    wnode wtree(1, n, a, a + n);
    while(q--) { 
        int l, r, k;
        cin >> l >> r >> k;
        cout << wtree.maj(l, r, (r - l + 1)/k) << '\n';
    }
}