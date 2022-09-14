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
	string s;
    cin >> s;
    int n = s.size(), l = 0, r = n - 1;
    vector<int> a, b;
    while (l < r) {
        while (l < r && s[l] == ')')
            l++;
        while (l < r && s[r] == '(')
            r--;
        if (l < r) {
            a.push_back(l);
            b.push_back(r);
        }
        l++; r--;
    }
    reverse(all(b));
    if (a.empty()) {
        cout << 0;
        return 0;
    }
    cout << "1\n" << a.size() * 2 << '\n';
    for (int i : a)
        cout << i + 1 << ' ';
    for (int i : b)
        cout << i + 1 << ' ';
}