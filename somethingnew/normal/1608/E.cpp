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

bool solve1(vector<array<int, 3>> crd, int k) {
    int trgnum = 0, trgcnt = k;
    for (int i = 0; i < crd.size(); ++i) {
        if (crd[i][2] == trgnum) {
            trgcnt--;
            if (trgcnt <= 0) {
                if (trgnum == 2)
                    return 1;
                trgnum++;
                trgcnt = k;
                while (i + 1 < crd.size() and crd[i + 1][0] == crd[i][0])
                    i++;
            }
        }
    }
    return 0;
}
bool solve2(vector<array<int, 3>> crd, int k, int DEBUG_ = 0) {
    int trgcnt = k;
    int i;
    if (DEBUG_)
        cout << ' ' << trgcnt << endl;
    for (i = 0; i < crd.size(); ++i) {
        if (crd[i][2] == 0) {
            trgcnt--;
            if (trgcnt == 0) {
                while (i + 1 < crd.size() and crd[i + 1][0] == crd[i][0])
                    i++;
                break;
            }
        }
    }
    if (DEBUG_)
        cout << i << ' ' << trgcnt << endl;
    //cout << i << endl;
    if (trgcnt > 0)
        return 0;
    vector<array<int, 3>> crd2;
    for (; i < crd.size(); ++i) {
        if (crd[i][2] != 0) {
            //cout << crd[i][0] << ' ' << crd[i][1] << '\n';
            crd2.push_back({crd[i][1], crd[i][0], crd[i][2]});
        }
    }
    sort(all(crd2));
    crd = crd2;
    int trgnum = 1;
    trgcnt = k;
    i = 0;
    for (; i < crd.size(); ++i) {
        if (DEBUG_)
            cout << crd[i][2] << ' ';
        if (crd[i][2] == trgnum) {
            trgcnt--;
            if (trgcnt <= 0) {
                if (trgnum == 2)
                    return 1;
                trgnum++;
                trgcnt = k;
                while (i + 1 < crd.size() and crd[i + 1][0] == crd[i][0])
                    i++;
            }
        }
    }
    if (DEBUG_)
        cout << '\n';
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int res = 0;
    vector<array<int, 3>> crd(n);
    for (int i = 0; i < n; ++i) {
        cin >> crd[i][0] >> crd[i][1] >> crd[i][2];
        crd[i][2]--;
    }
    for (int xumn = -1; xumn <= 1; xumn += 2) {
        for (int yumn = 1; yumn <= 1; yumn += 2) {
            for (int swp = 0; swp < 2; ++swp) {
                vector<int> a = {0, 1, 2};
                do {
                    vector<array<int, 3>> crd2 = crd;
                    for (auto &[x, y, c] : crd2) {
                        if (swp)
                            swap(x, y);
                        x *= xumn;y *= yumn;
                        c = a[c];
                    }
                    sort(all(crd2));
                    int l = 0, r = n / 3 + 1;
                    while (l + 1 < r) {
                        int m = l + r >> 1;
                        if (solve1(crd2, m) or solve2(crd2, m)) {
                            l = m;
                        } else
                            r = m;
                    }
                    //cout << res << endl;
                    //exit(0);
                    res = max(l, res);
                } while (next_permutation(all(a)));
            }
        }
    }
    cout << res * 3;
}
/*
6
1 1 1
2 1 1
2 2 3
1 2 2
1 3 2
2 3 3
 */