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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> b;
    rep(i, n) {
        cin >> a[i];
        a[i] -= i;
        while (1) {
            if (b.size() > 1 && (b[b.size() - 2].first - b.back().first) * b.back().second + b[b.size() - 2].first <= a[i]) {
                b[b.size() - 2].second += b.back().second;
                a[i] -= (b[b.size() - 2].first - b.back().first) * b.back().second;
                b.pop_back();
            }
            else if (!b.empty() && b.back().first <= a[i]) {
                ll d = (a[i] - b.back().first) / (b.back().second + 1);
                b.back().first += d;
                a[i] -= d * b.back().second;
                ll q = a[i] - b.back().first;
                if (q > 0) {
                    pair<ll, ll> pp {b.back().first, b.back().second - q + 1};
                    b.back().first++;
                    b.back().second = q;
                    if (b.size() > 1 && b[b.size() - 2].first == b.back().first) {
                        b[b.size() - 2].second += b.back().second;
                        b.pop_back();
                    }
                    b.push_back(pp);
                }
                else
                    b.back().second++;
                break;
            }
            else {
                b.push_back({a[i], 1});
                break;
            }
        }
    }
    ll cx = 0;
    for (auto &pp : b)
        rep(i, pp.second)
            cout << cx++ + pp.first << ' ';
}