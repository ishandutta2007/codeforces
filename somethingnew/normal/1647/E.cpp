#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()

vector<int> mult(vector<int> p1, vector<int> p2) {
    for (int i = 0; i < p1.size(); ++i) {
        p1[i] = p2[p1[i]];
    }
    return p1;
}
vector<int> pow(vector<int> a, int b) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); ++i) {
        res[i] = i;
    }
    while (b) {
        if (b & 1)
            res = mult(res, a);
        b /= 2;
        a = mult(a, a);
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        cnt[p[i]]++;
    }
    int killp = 0;
    for (int i = 0; i < n; ++i) {
        killp += max(cnt[i] - 1, 0);
    }
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int turn = (mx - n) / killp;
    p = pow(p, turn);
    vector<int> ex(n);
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        nums.insert(i+1);
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (ex[p[i]] == 0) {
            ex[p[i]] = 1;
            b[i] = a[p[i]];
            //cout << i << ' ' << b[i] << endl;
            nums.erase(b[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            int vl = a[p[i]];
            int q = *nums.upper_bound(vl);
            b[i] = q;
            nums.erase(q);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
}