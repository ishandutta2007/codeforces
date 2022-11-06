#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector<long long> V(N);

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    vector<long long> T(N);

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    multiset<long long> snow;
    snow.insert(V[0]);
    long long prev_water = 0;
    long long water = 0;
    long long sugrobs = 1;

    for (int i = 1; i <= N; i++) {
        long long ans = sugrobs * T[i - 1];

        prev_water = water;
        water += T[i - 1];

        auto pt = snow.lower_bound(water);
        while (pt != snow.begin() && (pt == snow.end() || *pt >= prev_water)) {
            pt--;
            if (*pt >= prev_water) {
                ans -= max(0ll, water - *pt);
                sugrobs--;
            }
        }

        cout << ans << ' ';
        if (i < N) {
            snow.insert(water + V[i]);
            sugrobs++;
        }
    }

    cout << endl;

    return 0;
}