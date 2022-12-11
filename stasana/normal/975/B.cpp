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

void main$(int testId);
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
        main$(i);
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

ll f(vector<ll> a, int id) {
    ll add = a[id] / 14;
    ll count = a[id] % 14;
    a[id] = 0;
    for (int i = 0; i < 14; ++i) {
        a[i] += add;
    }
    for (id = (id + 1) % 14; count > 0; id = (id + 1) % 14) {
        ++a[id];
        --count;
    }
    ll res = 0;
    for (int i = 0; i < 14; ++i) {
        res += (a[i] % 2 == 0) * a[i];
    }
    return res;
}

void main$(int testId) {
    vector<ll> a(14);
    for (int i = 0; i < 14; ++i) {
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 0; i < 14; ++i) {
        res = max(res, f(a, i));
    }
    cout << res;
}