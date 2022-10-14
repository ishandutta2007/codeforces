#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> Q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x; Q.pb(x);
        }
        vector<int> P;
        int m = 0;
        int v = 1;
        vector<int> used(n + 11, 0);
        bool f = true;
        for (auto x : Q) {
            if (m < x) {
                P.pb(x);
                m = x;
                used[x] = 1;
            } else {
                while (v < m && used[v] == 1) {
                    v++;
                }
                if (v == m) {
                    f = false; break;
                } else {
                    P.pb(v);
                    used[v]=1;
                    v++;
                }
            }
        }
        if (f) {
            for (auto g : P) {
                cout << g << ' ';
            }
        } else {
            cout << "-1";
        }
        cout << '\n';
    }

}