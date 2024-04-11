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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    vector<int> B(n);
    sort(A.begin(), A.end());
    int now = -1;
    for (int i = 0; i < n; i++) {
        if (now < A[i].first) {
            now = A[i].first;
            B[A[i].second] = now;
        } else {
            A[i].first = now + 1;
            now = A[i].first;
            B[A[i].second] = now;
        }
    }
    for (auto x : B) cout << x << ' ';
    cout << '\n';

}