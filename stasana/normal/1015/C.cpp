#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    ll sumHigh = 0, sumLow = 0;
    for (int i = 0; i < n; ++i) {
        a[i].first  = input<ll>();
        a[i].second = input<ll>();
        sumHigh += a[i].first;
        sumLow  += a[i].second;
    }

    if (sumLow > m) {
        cout << -1;
        return 0;
    }

    sort(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b) {return a.first - a.second > b.first - b.second; });

    int ptr = 0;
    while (sumHigh > m) {
        sumHigh -= a[ptr].first;
        sumHigh += a[ptr].second;
        ++ptr;
    }

    cout << ptr;
    return 0;
}