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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

vector<int> heh(22, -1);
unordered_map<int, int> par;
vector<vector<int>> up(1e6+10000, heh);
vector<int> depth(1e6+10000, -1);


int lca(int v1, int v2) {
    if (depth[v2] > depth[v1]) {
        swap(v1, v2);
    }
    int x = depth[v1] - depth[v2];
    for (int j = 21; j >= 1; j--) {
        if (x >= (1 << (j - 1))) {
            v1 = up[v1][j];
            x -= (1 << (j - 1));
        }
    }
    for (int j = 21; j >= 1; j--) {
        if (up[v1][j] != up[v2][j]) {
            v1 = up[v1][j];
            v2 = up[v2][j];
        }
    }
    return up[v1][1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i <= 3+2*q; i++) {
        up[i][0] = i;
    }
    for (int j = 0; j < 22; j++) {
        up[0][j] = 0;
    }
    depth[0] = 0;
    par[0] = -1;
    int y1 = 0, y2 = 0;
    int now_ans = 0;
    for (int i = 1; i <= 3; i++) {
        int p = 0;
        par[i] = p;
        depth[i] = depth[p] + 1;
        up[i][0] = i;
        up[i][1] = p;
        for (int j = 2; j < 22; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
        int num1 = depth[y1] + depth[i] - 2 * depth[lca(y1, i)];
        int num2 = depth[y2] + depth[i] - 2 * depth[lca(y2, i)];
        if (now_ans < num1) {
            now_ans = num1;
            y2 = i;
        } else if (now_ans < num2) {
            now_ans = num2;
            y1 = i;
        }
    }
    for (int i = 4; i <= 3+2*q; i+=2) {
        int p; cin >> p; p--;
        par[i] = p;
        depth[i] = depth[p] + 1;
        up[i][0] = i;
        up[i][1] = p;
        for (int j = 2; j < 22; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
        int num1 = depth[y1] + depth[i] - 2 * depth[lca(y1, i)];
        int num2 = depth[y2] + depth[i] - 2 * depth[lca(y2, i)];
        if (now_ans < num1) {
            now_ans = num1;
            y2 = i;
        } else if (now_ans < num2) {
            now_ans = num2;
            y1 = i;
        }
        par[i+1] = p;
        depth[i+1] = depth[p] + 1;
        up[i+1][0] = i+1;
        up[i+1][1] = p;
        for (int j = 2; j < 22; j++) {
            up[i+1][j] = up[up[i+1][j - 1]][j - 1];
        }
        num1 = depth[y1] + depth[i+1] - 2 * depth[lca(y1, i+1)];
        num2 = depth[y2] + depth[1+i] - 2 * depth[lca(y2, i+1)];
        if (now_ans < num1) {
            now_ans = num1;
            y2 = i+1;
        } else if (now_ans < num2) {
            now_ans = num2;
            y1 = i+1;
        }
        cout << now_ans << ' ';
    }
}