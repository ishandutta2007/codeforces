#define _CRT_SECURE_NO_WARNINGS

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
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;

#define all(x) (x).begin(), (x).end()

void solve(int testId);
bool isSystemTesting;
int testCount;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    isSystemTesting = true;
    if (strlen(__FILE__) > 41) {
        if (32[__FILE__] == 'b' &&
            33[__FILE__] == 'o' &&
            34[__FILE__] == 'k' &&
            35[__FILE__] == 'u' &&
            36[__FILE__] == 'n' &&
            37[__FILE__] == 'o' &&
            38[__FILE__] == 'p' &&
            39[__FILE__] == 'i' &&
            40[__FILE__] == 'c' &&
            41[__FILE__] == 'o') {
            isSystemTesting = false;
        }
    }

    testCount = 1;
    if (!isSystemTesting) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> testCount;
    }
}

void end() {
    if (!isSystemTesting) {
        fclose(stdin);
        fclose(stdout);
    }
}

int main() {
    start();

    for (int i = 0; i < testCount; ++i) {
        solve(i);
        if (!isSystemTesting) {
            cout << endl << "----------" << endl;
        }
    }

    end();
    return 0;
}

template<class T>
T input(istream& in = cin) {
    T result;
    in >> result;
    return result;
}

ll lower(vll& a, ll id) {
    if (a.empty() || a[0] > id) {
        return -1e17;
    }
    int left = 0;
    int right = a.size();
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] > id) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return a[left];
}

ll upper(vll& a, ll id) {
    if (a.empty() || a.back() < id) {
        return 1e17;
    }
    int left = -1;
    int right = a.size();
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] > id) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return a[right];
}

void solve(int testId) {
    ll n, m;
    cin >> n >> m;
    ll cl, ce;
    ll v;
    cin >> cl >> ce >> v;
    vll l(cl);
    for (ll i = 0; i < cl; ++i) {
        cin >> l[i];
    }
    vll e(ce);
    for (ll i = 0; i < ce; ++i) {
        cin >> e[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << endl;
            continue;
        }
        ll l1 = lower(l, y1), l2 = upper(l, y1), e1 = lower(e, y1), e2 = upper(e, y1);
        ll res = abs(y1 - l1) + abs(y2 - l1) + abs(x1 - x2);
        res = min(res, abs(y1 - l2) + abs(y2 - l2) + abs(x1 - x2));
        res = min(res, abs(y1 - e1) + abs(y2 - e1) + (abs(x1 - x2) - 1) / v + 1);
        res = min(res, abs(y1 - e2) + abs(y2 - e2) + (abs(x1 - x2) - 1) / v + 1);
        cout << res << endl;
    }
}