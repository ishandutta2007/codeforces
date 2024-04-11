// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
const int N = (int) 256, mod = (int) 0;
double adj[N], res[N], c[N];
void mul(double a[N], double b[N]) {
    for (int i = 0; i < N; ++i)
        c[i] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            c[i ^ j] += a[i] * b[j];
    for (int i = 0; i < N; ++i)
        res[i] = c[i];
}
void pw(int n) {
    if (n == 1) {
        return;
    }
    pw(n >> 1);
    mul(res, res);
    if (n & 1)
        mul(res, adj);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <= x; ++i)
        cin >> adj[i];
    for (int i = 0; i < N; ++i)
        res[i] = adj[i];
    pw(n);
    cout << setprecision(10) << fixed << 1 - res[0] << endl;



}