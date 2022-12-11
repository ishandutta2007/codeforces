#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;

bool cmp(pll a, pll b) {
    return (a.first - a.second) > (b.first - b.second);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<pll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += c[i].second;
    }
    sort(c.begin(), c.end(), cmp);
    for (int i = 0; i < min(n, b - 1); ++i) {
        if (c[i].first < c[i].second) {
            break;
        }
        result -= c[i].second;
        result += c[i].first;
    }
    ll sum = result;
    if (b == 0) {
        cout << sum << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        ll res = sum;
        if (c[i].first > c[i].second && i < b - 1) {
            res -= c[i].first;
            res += (c[i].first * (1 << a));
            if (b - 1 < n && c[b - 1].first > c[b - 1].second) {
                res -= c[b - 1].second;
                res += c[b - 1].first;
            }
        }
        else {
            res -= c[i].second;
            res += (c[i].first * (1 << a));
        }
        result = max(res, result);
    }
    cout << result << endl;
    return 0;
}