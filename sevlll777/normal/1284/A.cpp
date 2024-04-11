#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
#define str string
#define pb push_back
#define pii pair<int, int>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<str> S(n);
    vector<str> T(m);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> T[i];
    }
    vector<str> year;
    for (int dif = 0; dif < n * m; dif++) {
        str s1 = S[dif % n];
        str t1 = T[dif % m];
        year.pb(s1 + t1);
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << year[(x - 1) % (n * m)] << '\n';
    }

}