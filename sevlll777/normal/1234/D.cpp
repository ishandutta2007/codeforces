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
#define fir first
#define sec second
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
using namespace std;
int a, b, n, m, t, k, x, r, l, q, p;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<char> s;
    string st;
    cin >> st;
    for (auto ch : st) {
        s.pb(ch);
    }
    n = s.size();
    int SQ = floor(sqrt(n)) + 1;
    vector<vector<int>> X;
    vector<int> uq(26);
    for (int i = 0; i < n; i++) {
        if (i % SQ == 0 && i != 0) {
            X.pb(uq);
            fill(uq.begin(), uq.end(), 0);
        }
        uq[s[i] - 'a']++;
    }
    X.pb(uq);
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        cin >> t >> p;
        p--;
        if (t == 2) {
            int c;
            cin >> c;
            l = p;
            r = c - 1;
            fill(uq.begin(), uq.end(), 0);
            for (int i = l; i < min(r + 1, (l / SQ) * SQ + SQ); i++) {
                uq[s[i] - 'a']++;
            }
            for (int i = max(l, r - r % SQ); i <= r; i++) {
                uq[s[i] - 'a']++;
            }
            int lsq = l / SQ + 1;
            int rsq = r / SQ;
            for (int y = lsq; y < rsq; y++) {
                for (int i = 0; i < 26; i++) {
                    uq[i] += X[y][i];
                }
            }
            int c0 = 0;
            for (int i = 0; i < 26; i++) {
                if (uq[i] == 0) {
                    c0++;
                }
            }
            cout << 26 - c0 << '\n';
        } else {
            char c;
            cin >> c;
            k = p / SQ;
            X[k][s[p] - 'a']--;
            X[k][c - 'a']++;
            s[p] = c;
        }
    }
    return 0;
}