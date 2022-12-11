#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

const long long N = 1e6 + 34;
const long long inf = 1e9 + 34;

long long n, x, y, mxx, mxy, mnx, mny;
long long a[100][100];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) a[i][0] = a[0][i] = 1;
    for (int i = 1; i < n; i++) for (int j = 1; j < n; j++) a[i][j] = a[i-1][j] + a[i][j-1];
    cout << a[n-1][n-1];
}