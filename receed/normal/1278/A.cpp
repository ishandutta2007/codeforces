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
	int t;
    cin >> t;
    rep(z, t) {
        string p, h;
        cin >> p >> h;
        vector<int> pc(26), hc(26);
        for (char c : p)
            pc[c - 'a']++;
        if (h.size() < p.size()) {
            cout << "NO\n";
            continue;
        }
        rep(i, p.size())
            hc[h[i] - 'a']++;
        int f = 0;
        if (hc == pc)
            f = 1;
        rep(i, h.size() - p.size()) {
            hc[h[i] - 'a']--;
            hc[h[i + p.size()] - 'a']++;
            if (hc == pc)
                f = 1;
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}