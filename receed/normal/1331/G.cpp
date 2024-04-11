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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(2);
	vector<int> a;
    int x;
    while (cin >> x)
        a.push_back(x);
    reverse(all(a));
    for (int i : a) {
        cout << "f(" << i << ") = ";
        ld r = sqrt(abs(i)) + pow(i, 3) * 5;
        if (r < 400)
            cout << r << '\n';
        else
            cout << "MAGNA NIMIS!\n";
    }
}