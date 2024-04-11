#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "array"

using namespace std;

#define int long long

int bebra = 1 << 9;
array<int, 4> bebracount(vector<int> &b) {
    int mxval = 0;
    int mxpref = 0;
    int sum = 0;
    int mnpref = 0;
    for (int i = 0; i < b.size(); ++i) {
        sum += b[i];
        mnpref = min(sum, mnpref);
        mxpref = max(sum, mxpref);
        mxval = max(sum - mnpref, mxval);
    }
    return {mxval, mxpref, mnpref, sum};
}
int getval(vector<array<int, 4>> &b) {
    int sum = 0;
    int mnpref = 0;
    int res = 0;
    for (int i = 0; i < b.size(); ++i) {
        res = max(res, b[i][0]);
        res = max(res, sum + b[i][1] - mnpref);
        mnpref = min(b[i][2] + sum, mnpref);
        sum += b[i][3];
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    n = 1 << n;
    bebra = min(bebra, n);
    vector<int> a(n);
    vector<vector<int>> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % bebra == 0)
            b.push_back({});
        b.back().push_back({a[i]});
    }
    vector<vector<int>> bebriks(b.size(), vector<int>(bebra));
    vector<int> c(bebra, 0);
    vector<vector<array<int, 4>>> numnums(bebra);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < bebriks[i].size(); ++j) {
            for (int k = 0; k < c.size(); ++k) {
                c[k] = b[i][k ^ j];
            }
            numnums[j].push_back(bebracount(c));
        }
    }
    vector<int> ansiki(n);
    vector<array<int, 4>> bebrenka(numnums[0].size());
    for (int i = 0; i < n; ++i) {
        int fk = i % bebra, sk = i / bebra;
        for (int j = 0; j < numnums[fk].size(); ++j) {
            bebrenka[j] = numnums[fk][j ^ sk];
        }
        //cout << i << ' ' << getval(bebrenka) << '\n';
        ansiki[i] = getval(bebrenka);
    }
    int x = 0;
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        x ^= (1 << t);
        cout << ansiki[x] << '\n';
    }
}