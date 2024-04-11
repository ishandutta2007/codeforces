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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q, n;
    cin >> q;
    rep(z, q) {
        string s, t;
        cin >> n >> s >> t;
        vector<int> a(n), b(n);
        rep(i, n) {
            a[i] = s[i] - '0';
            b[i] = t[i] - '0';
        }
        int l = 0, r = n - 1, rev = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if ((a[r] ^ rev) == b[i]) {
                if (l < r) r--;
                else r++;
                continue;
            }
            if (a[l] != a[r]) {
                ans.push_back(1);
                if (i == 0)
                    continue;
            }
            ans.push_back(abs(r - l) + 1);
            rev ^= 1;
            swap(l, r);
            if (l < r) r--;
            else r++;
        }
        cout << ans.size() << ' ';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}