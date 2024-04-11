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
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int x = n.size();
        for (auto  p : n) x -= (p == '0');
        cout << x << '\n';
        for (int i = 0; i < n.size(); i++) {
            if (n[i] != '0') {
                cout << n[i];
                for (int _ = 0; _ < n.size() - i - 1; _++) cout << 0;
                cout << '\n';
            }
        }
    }

}