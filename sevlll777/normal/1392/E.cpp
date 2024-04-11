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
    vector<vector<int>> A(n, vector<int> (n));
    vector<int> po2(55);
    po2[0] = 1;
    for (int i = 1; i < 55; i++) po2[i] = 2 * po2[i - 1];
    for (int s = 0; s <= 2*n - 2; s++) {
        for (int i = max(0LL, s - n + 1); i < min(n, s+1); i++) {
            int j = s - i;
            if (i % 2) {
                A[i][j] = po2[s];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int x = 0, y = 0;
        cout << "1 1" << endl;
        for (int i = 1; i <= 2*n - 2; i++) {
            if ((k >> i) % 2) {
                if (x % 2 == 0) {
                    x++;
                } else {
                    y++;
                }
            } else {
                if (x % 2) {
                    x++;
                } else {
                    y++;
                }
            }
            cout << x+1 << ' ' << y+1 << endl;
        }
    }
}