#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
// #define int short
#define str string
#define pb push_back
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while (q--) {
        int a, m;
        cin >> a >> m;
        int g = gcd(a, m);
        int num = m / g;
        map<int, int> fact;
        while (num % 2 == 0) {
            num /= 2;
            fact[2]++;
        }
        for (int p = 3; p * p <= num; p+=2) {
            while (num % p == 0) {
                num /= p;
                fact[p]++;
            }
        }
        if (num > 1) {
            fact[num]++;
        }
        int ans = 1;
        for (auto p : fact) {
            ans *= (p.first - 1) * pow(p.first, p.second - 1);
        }
        cout << ans << '\n';
    }
}