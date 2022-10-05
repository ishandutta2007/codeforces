#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int sqw(int x) {
    return x * x;
}
int gt(int x, int cnt) {
    cnt++;
    int d1 = x % cnt, d2 = cnt - d1;
    return sqw(x/cnt+1) * d1 + sqw(x/cnt) * d2;
}
int save(int x, int cnt) {
    return gt(x, cnt-1) - gt(x, cnt);
}
int globsave(int x, int cnt) {
    return sqw(x) - gt(x, cnt);
}
int trg;
int getbatik(int vg, int x) {
    int l = 0, r = x;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (save(x, m) >= vg) {
            l = m;
        } else {
            r = m;
        }
    }
    return globsave(x, l);
}
bool solve(int x, vector<int> &elems) {
    int valik = 0;
    for (auto i : elems) {
        valik += getbatik(x, i);
    }
    return (valik >= trg);
}
int ans;
int getbatikans(int vg, int x) {
    int l = 0, r = x;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (save(x, m) >= vg) {
            l = m;
        } else {
            r = m;
        }
    }
    ans += l;
    return globsave(x, l);
}
int getans(int x, vector<int> &elems) {
    ans = 0;
    int valik = 0;
    for (auto i : elems) {
        valik += getbatikans(x, i);
    }
    return valik;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int lst = 0;
    int res = 0;
    vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += sqw(x - lst);
        elems[i] = x - lst;
        lst = x;
        //cout << save({x - lst, 1}) << endl;
    }
   // return 0;
    int m;
    cin >> m;
    trg = res - m;
    int l = 0, r = 1e18;
    while (l + 1 < r) {
        int mm = l + r >> 1;
        if (solve(mm, elems)) {
            l = mm;
        } else {
            r = mm;
        }
    }
    int vl = trg - getans(r, elems);
    //cout << ans << endl << vl << endl;
    //cout << r << endl;
    ans += (vl + r - 2) / (r - 1);
    cout << ans << '\n';
}
/*
12
100101011101
110110010110
010001011101
1
9 9
 */