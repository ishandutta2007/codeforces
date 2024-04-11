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
    int t;
    cin >> t;
    string s;
    rep(z, t) {
        cin >> s;
        vector<int> a;
        int k = 0;
        for (char c : s) {
            if (c == '1')
                k++;
            else if (k) {
                a.push_back(k);
                k = 0;
            }
        }
        if (k)
            a.push_back(k);
        sort(rall(a));
        int ans = 0;
        for (int i = 0; i < a.size(); i += 2)
            ans += a[i];
        cout << ans << '\n';
    }
}