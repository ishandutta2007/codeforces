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
#define str string
using namespace std;
const int M = 1000000007;
int p = 1;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= a;
            ans %= p;
        }
        a *= a;
        a %= p;
        x /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int u, v;
    cin >> u >> v >> p;
    vector<vector<int>> paths1 = {{}}, paths2 = {{}};
    int s = 100000;
    map<int, int> lol1, lol2;
    for (int i = 0; i < s; i++) {
        vector<int> path;
        int x = u;
        for (int j = 0; j < 100; j++) {
            int w = rand() % 3;
            if (w == 0) {
                x++; x %= p;
            } else if (w == 1) {
                x+=p-1;x%=p;
            } else {
                x=binpow(x,p-2);
            }
            path.pb(w+1);
        }
        paths1.pb(path);
        lol1[x] = i + 1;
    }
    for (int i = 0; i < s; i++) {
        vector<int> path;
        int x = v;
        for (int j = 0; j < 100; j++) {
            int w = (rand() + j + 1) % 3;
            if (w == 0) {
                x+=p-1; x %= p;
            } else if (w == 1) {
                x+=1;x%=p;
            } else {
                x=binpow(x,p-2);
            }
            path.pb(w+1);
        }
        paths2.pb(path);
        lol2[x] = i + 1;
    }
    for (auto g : lol2) {
        if (lol1[g.first] != 0) {
            cout << "200 \n";
            for (int z = 0; z < 100; z++) {
                int w = paths1[lol1[g.first]][z];
                cout << w << ' ';
            }
            for (int z = 99; z >= 0; z--) {
                int w = paths2[lol2[g.first]][z];
                cout << w << ' ';
            }
            return 0;
        }
    }
}