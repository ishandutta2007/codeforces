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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vi a(n), b(n);
    cin >> a >> b;
    priority_queue<int> c;
    for (int i = 0; i < n; ++i) {
        c.push(abs(a[i] - b[i]));
    }
    for (int i = 0; i < k1 + k2; ++i) {
        int top = c.top();
        top -= 1;
        c.pop();
        c.push(abs(top));
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll top = c.top();
        res += top * top;
        c.pop();
    }
    cout << res;
}