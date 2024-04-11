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
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> M(n), A;
    for (int i = 0; i < n; i++) {
        cin >> M[i].second >> M[i].first;
        A.pb({-M[i].second + M[i].first, i});
    }
    sort(A.begin(), A.end());
    b = min(b, n);
    int ans = 0;
    int sum_at = 0;
    int kek = 1;
    while (a--) kek *= 2;
     for (int g = 0; g < n; g++) {
        if (g < b) {
            sum_at += max(M[A[g].second].first, M[A[g].second].second);
        } else {
            sum_at += M[A[g].second].first;
        }
    }
    ans = sum_at;
    for (int g = 0; g < n; g++) {
        if (g < b) {
            int sus = sum_at - max(M[A[g].second].first, M[A[g].second].second);
            sus += max(M[A[g].second].first, kek * M[A[g].second].second);
            ans = max(ans, sus);
        } else {
            int sus = sum_at - M[A[g].second].first;
            if (b) {
                if (M[A[b - 1].second].second > M[A[b - 1].second].first) {
                    sus += M[A[b - 1].second].first - M[A[b - 1].second].second;
                }
                sus += max(M[A[g].second].first, kek * M[A[g].second].second);
            }
            ans = max(ans, sus);
        }
    }
    cout << ans << '\n';

}