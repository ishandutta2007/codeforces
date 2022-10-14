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

#define int long long
#define pb push_back
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> H(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> H[i];
        s += H[i];
    }
    s -= (n * (n - 1) / 2);
    int k = s % n - 1;
    s = (s + n - 1) / n;
    for (int i = 0; i < n; i++) {
        cout << s << ' ';
        if (k != i) s++;
    }
    cout << '\n';
}