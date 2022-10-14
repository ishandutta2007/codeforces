#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> p >> n;
    vector<bool> used(p, false);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x %= p;
        if (used[x]) {
            cout << i << '\n';
            exit(0);
        }
        used[x] = true;
    }
    cout << "-1\n";
}