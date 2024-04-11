#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n)
        cin >> x[i] >> y[i];
    if (n % 2) {
        cout << "NO";
        return 0;
    }
    rep(i, n / 2 - 1)
        if (x[i] + x[i + n / 2] != x[i + 1] + x[i + n / 2 + 1] || y[i] + y[i + n / 2] != y[i + 1] + y[i + n / 2 + 1]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
}