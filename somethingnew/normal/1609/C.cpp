#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
vector<int> prime;
int solve2(vector<int> a) {
    int n = a.size();
    vector<int> nextp(n, n);
    for (int i = n - 2; i >= 0; --i) {
        if (prime[a[i + 1]])
            nextp[i] = i + 1;
        else
            nextp[i] = nextp[i + 1];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int fp;
        if (prime[a[i]])
            fp = i;
        else
            fp = nextp[i];
        if (fp == n)
            continue;
        res += nextp[fp] - fp - (fp == i);
    }
    return res;
}
int solve3(vector<int> a) {
    vector<int> c;
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 1 or prime[a[i]])
            c.push_back(a[i]);
        else {
            res += solve2(c);
            c.clear();
        }
    }
    res += solve2(c);
    return res;
}
void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> a(min(n, e));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i % e].push_back(x);
    }
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += solve3(a[i]);
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    prime.assign(1e6 + 10, 1);
    prime[0] = prime[1] = 0;
    for (int i = 0; i < prime.size(); ++i) {
        if (prime[i]) {
            for (int j = i * 2; j < prime.size(); j += i) {
                prime[j] = 0;
            }
        }
    }
    int n = 1;
    cin >> n;
    while (n--)
        solve();
}