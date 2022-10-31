#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <array>
#include <random>
#include <ctime>
#include <deque>
#include <set>
#include <map>


using namespace std;


#define int long long
#define ll long long
#define ld long double
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll x = (n * m) % 3;
        ll res = 0;
        if (x == 0) {
            res = (n * m) / 3;
        } else if (x == 2) {
            res = (n * m - 2) / 3 + 1;
        } else if (x == 1) {
            res = (n * m - 4) / 3 + 2;
        }
        cout << res << "\n";
    }
    return 0;
}