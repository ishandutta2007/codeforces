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
        if (ans[i][0] == '-')
            exit(0);
        sort(all(ans[i]));
    }
    return ans;
}

string solve(int n) {
    if (n < 1)
        return "";
    vector<string> a = q(0, n), b = q(1, n);
    multiset<string> ss;
    for (string i : a)
        ss.insert(i);
    for (string i : b)
        ss.erase(ss.find(i));
    vector<string> d(n + 1);
    for (string i : ss)
        d[i.size()] = i;
    string ans(n, ' ');
    rep(i, n) {
        multiset<char> ms;
        for (char c : d[i + 1])
            ms.insert(c);
        for (char c : d[i])
            ms.erase(ms.find(c));
        ans[i] = *ms.begin();
    }
    return ans;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
	int n;
    cin >> n;
    string ans = solve((n + 1) / 2) + string(n / 2, ' ');
    vector<string> aa = q(0, n);
    vector<multiset<string>> a(n + 1);
    for (string i : aa)
        a[i.size()].insert(i);
    multiset<char> ms, cs;
    for (char c : *a[n].begin())
        ms.insert(c);
    for (int i = n - 1; i >= (n + 1) / 2; i--) {
        cs = ms;
        rep(j, (n + 1) / 2 + 1) {
            string ws;
            for (char c : cs)
                ws.push_back(c);
            a[ws.size()].erase(a[ws.size()].find(ws));
            if (j < (n + 1) / 2)
                cs.erase(cs.find(ans[j]));
        }
        cs = ms;
        for (char c : *a[i].begin())
            cs.erase(cs.find(c));
        ans[i] = *cs.begin();
        ms.erase(ms.find(ans[i]));
    }
    cout << "! " << ans;
    cout << endl;
}