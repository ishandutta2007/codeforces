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


bool ok(vector<int>& a, vector<int>& b) {
    sort(all(a));
    sort(all(b));
    int n = a.size();
    while (!a.empty()) {
        int x = a.back();
        int y = b.back();
        a.pop_back();
        b.pop_back();
        if (!(x == y || x + 1 == y)) {
            return false;
        }
    }
    return true;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> a;
        vector<int> b;
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        if (ok(a, b)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}