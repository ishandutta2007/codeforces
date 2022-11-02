#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll a, b, mn, mx;
        cin >> a >> b;
        if ((a + b) % 2 == 0) {
            ll k = (a + b) / 2;
            mn = max(a, b) - k;
            mx = 3 * k - max(a, b);
        }
        else {
            ll k = (a + b) / 2 + 1;
            mn = max(a, b) - k;
            mx = 3 * k - max(a, b) - 1;
        }
        vector<ll> s;
        for (ll i = mn; i <= mx; i += 2)
            s.push_back(i);

        for (ll i = mx; i >= mn; i -= 2)
            s.push_back(i);
        sort(all(s));
        s.erase(unique(all(s)), s.end());

        cout << s.size() << "\n";
        for (auto i : s)
            cout << i << " ";

        cout << "\n";
    }
    return 0;
}