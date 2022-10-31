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
        ll u, v;
        cin >> u >> v;
        cout << - (u * u) << " " << v * v << "\n";
    }
    return 0;
}