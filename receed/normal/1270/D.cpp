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
	int n, k, p, x;
    cin >> n >> k;
    map<int, int> cc;
    rep(i, k + 1) {
        cout << "?";
        rep(j, k + 1)
            if (i != j)
                cout << ' ' << j + 1;
        cout << endl;
        cin >> p >> x;
        cc[x]++;
    }
    cout << "! " << (*--cc.end()).second << endl;
}