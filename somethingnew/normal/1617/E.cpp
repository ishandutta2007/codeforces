#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "unordered_map"
#define all(a) (a).begin(), (a).end()
using namespace std;
unordered_map<int, int> dept;
unordered_map<int, int> num, ex;
unordered_map<int, vector<int>> gobr;
void add(int x, int nm, int dep) {
    if (dept[x] < dep or (dept[x] == dep and dep == 0)) {
        dept[x] = dep;
        num[x] = nm;
    } else {
        return;
    }
    if (x == 0)
        return;
    int t = 1;
    while (t < x)
        t *= 2;
    gobr[t-x].push_back(x);
    add(t-x, nm, dep + 1);
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    reverse(all(a));
    for (int i = 0; i < n; ++i) {
        ex[a[i].first] = a[i].second + 1;
        add(a[i].first, a[i].second, 0);
    }
    int x=0,y=0,val=0;
    for (auto [i, go] : gobr) {
        sort(all(go));
        go.erase(unique(all(go)), go.end());
        if (ex[i]) {
            for (auto j : go) {
                if (val < dept[j] + 1) {
                    val = dept[j] + 1;
                    x = ex[i] - 1;
                    y = num[j];
                }
            }
        }
        int mx = -1, mxnum=-1, secmx=-1, secmxnum = -1;
        for (auto j : go) {
            if (dept[j] > mx) {
                if (mx > secmx) {
                    secmx = mx;
                    secmxnum = mxnum;
                }
                mx = dept[j];
                mxnum = num[j];
            } else if (dept[j] > secmx) {
                secmx = dept[j];
                secmxnum = num[j];
            }
        }
        if (secmx != -1) {
            if (mx + secmx + 2 > val) {
                //cout << mxnum << ' ' << secmxnum << ' ' << mx << ' ' << secmx << endl;
                val = mx + secmx + 2;
                x = mxnum;
                y = secmxnum;
            }
        }
    }
    cout << x + 1 << ' ' << y + 1 << ' ' << val << '\n';
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