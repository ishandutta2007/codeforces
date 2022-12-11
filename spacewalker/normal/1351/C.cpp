#include <bits/stdc++.h>

using namespace std;

char field[1000000];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", field);
        int n = strlen(field);
        set<pair<pair<int, int>, pair<int, int>>> visited;
        int cx = 0, cy = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int nx = cx, ny = cy;
            if (field[i] == 'S') --ny;
            if (field[i] == 'N') ++ny;
            if (field[i] == 'E') ++nx;
            if (field[i] == 'W') --nx;
            pair<pair<int, int>, pair<int, int>> setup = make_pair(make_pair(cx, cy), make_pair(nx, ny));
            if (setup.first > setup.second) swap(setup.first, setup.second);
            if (visited.count(setup) == 0) {
                ans += 4;
            }
            ++ans;
            visited.insert(setup);
            cx = nx, cy = ny;
        
        }
        printf("%d\n", ans);
    }
    return 0;
}