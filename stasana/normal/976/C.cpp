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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<pii, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i < n; ++i) {
        if (a[i - 1].first.second >= a[i].first.second) {
            cout << a[i].second << " " << a[i - 1].second << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1;
    return 0;
}