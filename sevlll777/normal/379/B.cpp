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
    vector<int> A(1 + n);
    for (int i = 1; i <= n; i++) cin >> A[i];
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) cnt0 += (A[i] == 0);
    int now = 1;
    bool kek = true;
    string ans = "";
    while (cnt0 != n) {
        if (kek) {
            ans += 'R';
            if (A[now + 1]) {
                ans += 'P';
                A[now + 1]--;
                cnt0 += (A[now + 1] == 0);
            }
            now++;
        } else {
            ans += 'L';
            if (A[now - 1]) {
                ans += 'P';
                A[now - 1]--;
                cnt0 += (A[now - 1] == 0);
            }
            now--;
        }
        if (now == 1) {
            kek = true;
        }
        if (now == n) {
            kek = false;
        }
    }
    cout << ans << '\n';
}