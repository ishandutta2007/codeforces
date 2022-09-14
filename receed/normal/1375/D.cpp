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
    int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n), r, c(n + 1);
        rep(i, n) {
            cin >> a[i];
            a[i] = min(a[i], n);
            c[a[i]]++;
        }
        while (1) {
            int f = 0;
            rep(i, n) {
                if (c[i] == 0) {
                    c[a[i]]--;
                    c[i]++;
                    a[i] = i;
                    r.push_back(i);
                    f = 1;
                    break;
                }
            }
            if (f)
                continue;
            rep(i, n) {
                if (a[i] == i)
                    continue;
                rep(j, n)
                    if (a[j] == i) {
                        int p = 0;
                        while (c[p])
                            p++;
                        r.push_back(j);
                        a[j] = p;
                        c[i]--;
                        c[p]++;
                    }
                c[a[i]]--;
                c[i]++;
                a[i] = i;
                r.push_back(i);
                f = 1;
                break;
            }
            if (!f)
                break;
        }
        cout << r.size() << '\n';
        for (int i : r)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}