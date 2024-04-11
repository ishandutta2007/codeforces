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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1;
        return 0;
    } else {
        int ans = 0;
        vector<int> fact = {1};
        for (int i = 1; i <= n + 2; i++) {
            fact.pb((fact.back() * i) % m);
        }
        for (int i = 1; i < n; i++) {
            ans += (n - i) * (n - i) % m * fact[n - i - 1] % m * fact[i + 1] % m;
            ans %= m;
        }
        ans %= m;
        ans += (n * fact[n]) % m;
        ans %= m;
        cout << ans;
    }


}