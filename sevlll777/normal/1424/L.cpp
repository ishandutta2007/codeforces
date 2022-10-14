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
int ans;

void ask(int i, int j) {
    cout << '?' << ' ' << i + 1 << ' ' << j + 1 << endl;
    cin >> ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> kek(m);
    int mem = 1e18;
    for (int j = 0; j < m; j++) {
        ask(n - 1, j);
        kek[j] = ans;
        mem = min(mem, ans);
    }
    for (int j = 0; j < m; j++) {
        if (kek[j] == mem) {
            int ANS = 1e18;
            for (int i = 0; i < n; i++) {
                ask(i, j);
                ANS = min(ANS, ans);
            }
            cout << "! " << ANS << endl;
            exit(0);
        }
    }

}