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
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool znak = true;
        if (a % 2) znak = !(znak);
        if (b % 2) znak = !(znak);
        if (znak) {
            cout << "Tidak Tidak ";
            if (b || c) {
                cout << "Ya ";
            } else {
                cout << "Tidak ";
            }
            if (a || d) {
                cout << "Ya ";
            } else {
                cout << "Tidak ";
            }
        } else {
            if (a || d) {
                cout << "Ya ";
            } else {
                cout << "Tidak ";
            }
            if (b || c) {
                cout << "Ya ";
            } else {
                cout << "Tidak ";
            }
            cout << "Tidak Tidak ";
        }
        cout << '\n';
    }
}