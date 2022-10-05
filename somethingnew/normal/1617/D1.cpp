#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#define all(a) (a).begin(), (a).end()
using namespace std;
vector<int> numsiki = {1, 0, 0, 1, 1, 0, 1, 0, 1};
int zpr(int a, int b, int c) {
    a++;b++;c++;
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int x;
    cin >> x;
    return x;
}
int zpr(vector<int> a) {
    return zpr(a[0], a[1], a[2]);
}
vector<int> solve3(vector<int> a, int val, int zero, int one) {
    vector<int> res(3);
    if (val == 1) {
        int vl = zpr(zero, a[0], a[1]);
        if (vl == 0) {
            res[2] = 1;
            res[1] = zpr(zero, one, a[1]);
            res[0] = 1 - res[1];
        } else {
            res[0] = 1;
            res[1] = 1;
            res[2] = zpr(zero, one, a[2]);
        }
    } else {
        int vl = zpr(one, a[0], a[1]);
        if (vl == 1) {
            res[2] = 0;
            res[1] = zpr(zero, one, a[1]);
            res[0] = 1 - res[1];
        } else {
            res[0] = 0;
            res[1] = 0;
            res[2] = zpr(zero, one, a[2]);
        }
    }
    return res;
}
pair<int, int> get_zeone(vector<int> a, vector<int> b) {
    if (zpr(a[1], a[2], b[0])) {
        return {a[0], b[0]};
    }
    if (zpr(a[2], b[0], b[1])) {
        return {a[1], b[1]};
    }
    return {a[2], b[2]};
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n/3);
    vector<int> val(n/3);
    vector<vector<int>> resik(n/3, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        nums[i/3].push_back(i);
    }
    int fz = -1, fo = -1;
    for (int i = 0; i < n/3; ++i) {
        val[i] = zpr(nums[i]);
        if (val[i] == 0)
            fz = i;
        else
            fo = i;
    }
    auto [zero, one] = get_zeone(nums[fz], nums[fo]);
    resik[one/3][one%3] = 1;
    for (int i = 0; i < n / 3; ++i) {
        if (i == fz or i == fo) {
            for (int j = 0; j < 3; ++j) {
                int pos = i * 3 + j;
                if (pos != zero and pos != one) {
                    resik[i][j] = zpr(zero, one, pos);
                }
            }
        } else {
            resik[i] = solve3(nums[i], val[i], zero, one);
        }
    }
    vector<int> res;
    for (int i = 0; i < n / 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (resik[i][j] == 0)
                res.push_back(i*3+j+1);
        }
    }
    cout << "! ";
    cout << res.size() << ' ';
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}
/*
1 2
RL
DU
LR
10
v 1 1
v 1 2
v 1 3
v 2 1
v 2 2
v 2 3
h 1 1
h 2 1
h 3 1
h 4 1

 */