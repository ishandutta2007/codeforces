#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;

const long long BIT = 64;
const double INF = 1e9;
const double EPS = 1e-9;
const int MSIZE = 200000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#')
                b[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            for (int k = 0; k < m; k++)
                for (int l = 0; l < k; l++) {
                    int s = b[i][k] + b[i][l] + b[j][k] + b[j][l];
                    if (s == 3) {
                        cout << "No";
                        return 0;
                    }
                }
    cout << "Yes";
    return 0;
}