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
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> f1(11+n);
    vector<int> f2(11+n);
    vector<int> f3(11+n);
    vector<int> heh(2 * n + 107, 1);
    int cnt = 0;
    while (q--) {
        int r, c;
        cin >> r >> c;
        if (heh[(n + 4) * (r - 1) + c - 1] == 0) {
            if (r == 1) {
                if (f1[c] == 2) cnt--;
                if (f2[c - 1] == 2) cnt--;
                if (f3[c] == 2) cnt--;
                f1[c]--;
                f2[c - 1]--;
                f3[c]--;
            } else {
                if (f1[c - 1] == 2) cnt--;
                if (f2[c] == 2) cnt--;
                if (f3[c] == 2) cnt--;
                f1[c - 1]--;
                f2[c]--;
                f3[c]--;
            }
        } else {
            if (r == 1) {
                f1[c]++;
                f2[c - 1]++;
                f3[c]++;
                if (f1[c] == 2) cnt++;
                if (f2[c - 1] == 2) cnt++;
                if (f3[c] == 2) cnt++;
            } else {
                f1[c - 1]++;
                f2[c]++;
                f3[c]++;
                if (f1[c - 1] == 2) cnt++;
                if (f2[c] == 2) cnt++;
                if (f3[c] == 2) cnt++;
            }
        }
        if (heh[(n + 4) * (r - 1) + (c - 1)] == 0) {
            heh[(n + 4) * (r - 1) + (c - 1)] = 1;
        } else {
            heh[(n + 4) * (r - 1) + (c - 1)] = 0;
        }
        if (cnt == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}