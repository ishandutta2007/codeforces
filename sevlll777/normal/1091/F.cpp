#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
// #define int short
#define str string
#define pb push_back
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> L(n);
    for (int i = 0; i < n; i++) cin >> L[i];
    string T; cin >> T;
    bool water = false;
    int time = 0, energy = 0, grass = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] == 'L') {
            time += L[i];
            energy -= L[i];
            if (energy < 0) {
                if (water) {
                    time -= energy * 3;
                } else {
                    time -= energy * 5;
                }
                energy = 0;
            }
        } else if (T[i] == 'W') {
            water = true;
            energy += L[i];
            time += 3 * L[i];
        } else {
            energy += L[i];
            time += 5 * L[i];
            grass += 2 * L[i];
        }
        grass = min(grass, energy);
    }
    if (energy > 0) {
        time -= 2 * grass;
        time -= (energy - grass);
    }
    cout << time;
}