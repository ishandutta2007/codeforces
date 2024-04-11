#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n;
vector<int> a;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
    }
}

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick() {}
    
    void upd(int pos, int val) {
        if (pos < 0 || pos >= n) return;
        for (; pos < n; pos |= pos + 1)
            tree[pos] += val;
    }

    Fenwick(const vector<int> & a) {
        n = a.size();

        tree.assign(n, 0);
        for (int i = 0; i < n; i++) {
            upd(i, a[i]);
            if (i + 1 < n) {
                upd(i + 1, -a[i]);
            }
        }
    }
    
    void upd(int l, int r, int x) {
        upd(l, x);
        upd(r + 1, -x);
    }
    int get(int pos) {
        int ans = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            ans += tree[pos];
        }
        return ans;
    }
};

int sum;
Fenwick tree;

void relax(int pos, int flag) {
    if (pos < 0 || pos + 1 >= n) return;
    int a = tree.get(pos);
    int b = tree.get(pos + 1);
    if (a >= b) return;
    sum += flag * (b - a);
}

void build() {
    sum = 0;
    tree = Fenwick(a);
    for (int i = 0; i + 1 < n; i++) {
        relax(i, 1);
    }
}

void upd(int l, int r, int x) {
    relax(l - 1, -1);
    relax(r, -1);
    tree.upd(l, r, x);
    relax(l - 1, 1);
    relax(r, 1);
}

int myDiv(int x) {
    if (x >= 0) {
        return (x + 1) / 2;
    } else {
        return x / 2;
    }
}

int getB(int l) {
    return myDiv(l + sum);
}

int getAns() {
    return getB(tree.get(0));
} 

void run() {
    build();
    int q;
    cin >> q;
    cout << getAns() << "\n";
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        upd(l, r, x);
        cout << getAns() << "\n";
    }
}

void write() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}