#include <bits/stdc++.h>
using namespace std;

//int BIT[200001] = {};
//
//int getMax(int index) {
//    int ret = 0;
//    while (index > 0) {
//        ret = max(ret, BIT[index]);
//        index -= index & (-index);
//    }
//    return ret;
//}
//
//void update(int index, int val) {
//    while (index <= 200000) {
//        BIT[index] = max(BIT[index], val);
//        index += index & (-index);
//    }
//}
//
//int BIT2[200001];
//
//int getMin(int index) {
//    int ret = 1e9;
//    while (index > 0) {
//        ret = min(ret, BIT2[index]);
//        index -= index & (-index);
//    }
//    return ret;
//}
//
//void update2(int index, int val) {
//    while (index <= 200000) {
//        BIT2[index] = min(BIT2[index], val);
//        index += index & (-index);
//    }
//}

struct Trap {
    int l, r, d;

    bool operator < (const Trap &other) const {
        if (l == other.l)
            return r < other.r;
        return l < other.l;
    }
};

int a[200000];
Trap traps[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //memset(BIT2, 127, sizeof(BIT2));

    int m, n, k, t;
    cin >> m >> n >> k >> t;
    for (int i=0; i<m; i++)
        cin >> a[i];
    for (int i=0; i<k; i++)
        cin >> traps[i].l >> traps[i].r >> traps[i].d;

    sort(a, a + m, greater<int>());
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2;

        vector<Trap> v;
        for (int i=0; i<k; i++)
            if (traps[i].d > a[mid])
                v.push_back(traps[i]);

        sort(v.begin(), v.end());
        int single = 0, R = 0;
        for (Trap tp : v) {
            if (tp.l <= R) {
                single += max(0, tp.r - R);
                R = max(tp.r, R);
            } else {
                single += tp.r - tp.l + 1;
                R = tp.r;
            }
        }

        int timeConsumed = n + 1 + 2 * single;

        if (timeConsumed > t)
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << "\n";

    return 0;
}