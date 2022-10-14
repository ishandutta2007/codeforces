#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>


#define pb push_back
#define vec vector
#define pii pair<int, int>
using namespace std;
const int M = 998244853;
const int maxi = 5e6 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vec<int> lcd;
    for (int i = 0; i <= maxi; i++) {
        lcd.pb(0);
    }
    vec<int> simp;
    for (int x = 2; x <= maxi; x++) {
        if (lcd[x] == 0) {
            simp.pb(x);
            lcd[x] = x;
        }
        for (int i = 0; i < simp.size(); i++) {
            int p = simp[i];
            if (p * x <= maxi) {
                lcd[p * x] = p;
            } else {
                break;
            }
        }
    }
    vec<int> G;
    G.pb(0);
    G.pb(0);
    for (int t = 2; t <= maxi; t++) {
        int c = 0;
        int t2 = t;
        while (lcd[t2] != 0) {
            c++;
            t2 /= lcd[t2];
        }
        G.pb(G.back() + c);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << G[a] - G[b] << " ";
    }
}