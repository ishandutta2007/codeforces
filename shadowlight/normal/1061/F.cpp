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

bool ask(int x, int y, int z) {
    cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
    //return (x == y || y == z || (x != z && x + z == 2));
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    srand(time(0));
    int n, k;
    cin >> n >> k;
    int depth = 0;
    int now = 1, sum = 1;
    while (sum < n) {
        now *= k;
        sum += now;
        depth++;
    }
    int v, u;
    vector <int> all;
    while (true) {
        v = rand() % n, u = rand() % n;
        all = {v, u};
        for (int i = 0; i < n; i++) {
            if (v == i || u == i) continue;
            if (ask(v, i, u)) {
                all.push_back(i);
            }
        }
        if (all.size() == 2 * depth + 1) break;
    }
    int l = 0, r = 2 * depth + 1;
    while (r - l > 1) {
        int p = all[rand() % (int) all.size()];
        if (!ask(v, p, u)) continue;
        int cnt = 0;
        for (int x : all) {
            cnt += ask(v, x, p);
        }
        if (cnt + l <= depth + 1) {
            v = p;
            l += cnt - 1;
        } else {
            r = cnt + l - 1;
            u = p;
        }
    }
    cout << "! " << v + 1 << "\n";
}