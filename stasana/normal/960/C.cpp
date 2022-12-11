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

typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

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
            cout << endl;
        }
    }

    end();
    return 0;
}

istream& operator>> (istream& in, vi& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        in >> a[i];
    }
    return in;
}

ostream& operator<< (ostream& out, vi& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        out << a[i] << " ";
    }
    return out;
}

istream& operator>> (istream& in, vll& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        in >> a[i];
    }
    return in;
}

ostream& operator<< (ostream& out, vll& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        out << a[i] << " ";
    }
    return out;
}

void solve(int testId) {
    ll x, d;
    cin >> x >> d;
    vll a;
    ll two = 0;
    while ((1 << two) - 1 <= x) {
        a.push_back((2 << two) - 1);
        ++two;
    }
    vll res;
    ll back = 1;
    while (x > 0) {
        int id = 0;
        while (a[id + 1] <= x) {
            ++id;
        }
        x -= a[id];
        for (int i = 0; i <= id; ++i) {
            res.push_back(back);
        }
        back += d + 1;
    }
    cout << res.size() << endl;
    cout << res;
}