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
    int n;
    cin >> n;
    vector<pair<int, int>> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i].first;
        X[i].second = i;
    }
    int k;
    cin >> k;
    sort(X.begin(), X.end());
    int answ = 0;
    int justxsum = 0;
    for (int i = 0; i < k; i++) {
        justxsum += X[i].first;
        answ += X[i].first * (2 * i - k + 1);
    }
    int suum = answ;
    int ind = 0;
    for (int i = 0; i < n - k; i++) {
        suum -= X[i].first * (-k + 1);
        justxsum -= X[i].first;
        suum -= justxsum * 2;
        suum += X[i + k].first * (k - 1);
        justxsum += X[i + k].first;
        if (suum < answ) {
            answ = suum;
            ind = i+1;
        }
    }
    for (int i = ind; i < ind + k; i++) {
        cout << X[i].second + 1 << ' ';
    }
}