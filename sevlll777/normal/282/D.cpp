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
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    int xex = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        xex ^= A[i];
    }
    if (n % 2) {
        if (xex) {
            cout << "BitLGM\n";
        } else {
            cout << "BitAryo\n";
        }
    } else {
        int a = A[0], b = A[1];
        int win[601][601];
        win[0][0] = 2;
        for (int s = 1; s <= a + b; s++) {
            for (int i = 0; i <= min(s, a); i++) {
                int j = s - i;
                win[i][j] = 2;
                for (int i_ = 1; i_ <= min(i, j); i_++) {
                    if (win[i - i_][j - i_] == 2) win[i][j] = 1;
                }
                for (int i_ = 1; i_ <= i; i_++) {
                    if (win[i - i_][j] == 2) win[i][j] = 1;
                }
                for (int j_ = 1; j_ <= j; j_++) {
                    if (win[i][j - j_] == 2) win[i][j] = 1;
                }
            }
        }
        if (win[a][b] == 1) {
            cout << "BitLGM\n";
        } else {
            cout << "BitAryo\n";
        }
    }
}