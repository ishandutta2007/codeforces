#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 5001;
ll d[N], x[N], y[N];

ll di(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p = 0;
    cin >> n;
    rep(i, n)
        cin >> x[i] >> y[i];
    rep(i, n) {
        d[p] = 1;
        cout << p + 1 << ' ';
        ll nx = -1, cd = 0, nd;
        rep(j, n) {
            if (d[j])
                continue;
            nd = di(p, j);
            if (nd > cd) {
                cd = nd;
                nx = j;
            }
        }
        p = nx;
    }
}