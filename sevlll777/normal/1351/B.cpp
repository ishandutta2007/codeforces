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
    int n;
    cin >> n;
    while (n--) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if (b1 < a1) swap(a1, b1);
        if (b2 < a2) swap(a2, b2);
        if ((a1 == a2 && b1 + b2 == a1) || (a1 == b2 && a2 + b1 == a1) || (b1 == a2 && a1 + b2 == a2) ||
            (b1 == b2 && a1 + a2 == b1)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}