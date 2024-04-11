#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <pair <int, int> > p;
    int x = n;
    for (int i = 2; i <= n; i++) {
        if (x % i == 0) {
            p.push_back({i, 0});
            while (x % i == 0) {
                x /= i;
                p.back().second++;
            }
        }
    }
    int st = 1;
    int cnt = 0;
    int res = 1;
    for (auto t : p) {
        res *= t.first;
        while (st < t.second) {
            st *= 2;
            cnt++;
        }
    }
    bool fl = true;
    for (auto t : p) {
        if (t.second != st) {
            fl = false;
            break;
        }
    }
    if (fl) {
        cout << res << " " << cnt << "\n";
        return 0;
    }
    cout << res << " " << (cnt ? cnt + 1 : 0) << "\n";
}