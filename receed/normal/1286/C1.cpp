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


vector<string> q(int l, int r) {
    if (l == r)
        return {};
    int d = r - l;
    cout << "? " << l + 1 << ' ' << r << endl;
    vector<string> ans(d * (d + 1) / 2);
    rep(i, d * (d + 1) / 2) {
        cin >> ans[i];
        sort(all(ans[i]));
    }
    return ans;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
	int n;
    cin >> n;
    vector<string> a = q(0, n), b = q(1, n);
    multiset<string> ss;
    for (string i : a)
        ss.insert(i);
    for (string i : b)
        ss.erase(ss.find(i));
    vector<string> d(n + 1);
    for (string i : ss)
        d[i.size()] = i;
    cout << "! ";
    rep(i, n) {
        multiset<char> ms;
        for (char c : d[i + 1])
            ms.insert(c);
        for (char c : d[i])
            ms.erase(ms.find(c));
        cout << *ms.begin();
    }
    cout << endl;
}