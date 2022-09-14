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
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n);
        rep(i, n)
            cin >> a[i];
        int p = -1;
        rep(i, n - 1) 
            if (abs(a[i] - a[i + 1]) > 1)
                p = i;
        if (p == -1)
            cout << "NO\n";
        else
            cout << "YES\n" << p + 1 << ' ' << p + 2 << '\n';
    }
}