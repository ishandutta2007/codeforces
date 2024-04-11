#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include "unordered_set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
vector<long long> primes;
vector<long long> divi(long long x) {
    if (x <= 0)
        return {};
    vector<long long> res;
    for (auto i : primes) {
        if (i * i > x)
            break;
        if (x % i == 0) {
            res.push_back(i);
        }
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        res.push_back(x);
    return res;
}
int rnd() {
    return rand() << 16 ^ rand();
}
int slv(long long x, vector<long long> &nums) {
    long long res = 0;
    for (auto i : nums) {
        if (x > i) {
            res += x - i;
        } else {
            long long t = i % x;
            res += min(t, x - t);
        }
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    for (int i = 2; i < 1e6; ++i) {
        int pr = 1;
        for (auto j : primes) {
            if (j * j > i)
                break;
            if (i % j == 0) {
                pr = 0;
                break;
            }
        }
        if (pr)
            primes.push_back(i);
    }
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    rand();
    //cout << rnd() << '\n';    cout << rnd() << '\n';    cout << rnd() << '\n';    cout << rnd() << '\n';    cout << rnd() << '\n';
    map<int, int> mp;
    for (int i = 0; i < 30; ++i) {
        int p = rnd() % n;
        for (auto j : divi(a[p]))
            mp[j]++;
        for (auto j : divi(a[p] - 1))
            mp[j]++;
        for (auto j : divi(a[p] + 1))
            mp[j]++;
    }
    int ans = n;
    for (auto [key, val] : mp) {
        ans = min(ans, slv(key, a));
    }
    cout << ans;
}