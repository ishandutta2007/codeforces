#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();
    vector<ll> res1, res2;
    ll a, b;
    cin >> a >> b;
    ll i = 1;
    vector<ll> n;
    ll c = a + b;
    ll j = 1;
    while (c >= j) {
        n.push_back(j);
        c -= j;
        ++j;
    }
    if (a < b) {
        i = ll(n.size()) - 1;
        while (i >= 0) {
            if (n[i] <= a) {
                res1.push_back(n[i]);
                a -= n[i];
            }
            --i;
        }
        reverse(res1.begin(), res1.end());
        for (auto i : n) {
            if (b < i) {
                break;
            }
            ll left = 0;
            ll right = res1.size();
            while (right - left > 1) {
                ll mid = (left + right) / 2;
                if (res1[mid] > i) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            if (!res1.empty() && res1[left] == i) {
                continue;
            }
            res2.push_back(i);
            b -= i;
        }
    }
    else {
        i = ll(n.size()) - 1;
        while (i >= 0) {
            if (n[i] <= b) {
                res2.push_back(n[i]);
                b -= n[i];
            }
            --i;
        }
        reverse(res2.begin(), res2.end());
        for (auto i : n) {
            if (a < i) {
                break;
            }
            ll left = 0;
            ll right = res2.size();
            while (right - left > 1) {
                ll mid = (left + right) / 2;
                if (res2[mid] > i) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            if (!res2.empty() && res2[left] == i) {
                continue;
            }
            res1.push_back(i);
            a -= i;
        }
    }
    cout << res1.size() << endl;
    for (auto i : res1) {
        cout << i << " ";
    }
    cout << endl << res2.size() << endl;
    for (auto i : res2) {
        cout << i << " ";
    }
    return 0;
}