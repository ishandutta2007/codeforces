#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    long long res = 1;
    int n, m;
    cin >> n >> m;
    long long mod = 998244353;
    for (int i = 0; i < n + m; ++i) {
        res *= 2;
        res %= mod;
    }
    cout << res;
}