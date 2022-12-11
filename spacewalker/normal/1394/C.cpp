#include <bits/stdc++.h>

using namespace std;
constexpr int LMAX = 500010;
constexpr int INF = 1000000000;

pair<int, int> readBN() {
    static char s[LMAX];
    scanf("%s", s);
    pair<int, int> ans;
    for (int i = 0; s[i]; ++i) (s[i] == 'B' ? ans.first : ans.second)++;
//    printf("READ %d %d\n", ans.first, ans.second);
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = readBN();
    int lo = 0, hi = LMAX;
    auto checkForIntersect = [&] (int r) {
        int minx = -INF, maxx = INF, miny = -INF, maxy = INF;
        int mind = -INF, maxd = INF;
        for (auto [x, y] : arr) {
            minx = max(minx, x - r);
            maxx = min(maxx, x + r);
            miny = max(miny, y - r);
            maxy = min(maxy, y + r);
            mind = max(mind, y - x - r);
            maxd = min(maxd, y - x + r);
        }
        if (minx > maxx || miny > maxy || mind > maxd) return make_pair(-1, -1);
        if (maxy - minx < mind || maxd < miny - maxx) return make_pair(-1, -1);
        pair<int, int> ans{maxx, miny};
        while (ans.second - ans.first < mind) {
            if (ans.second < maxy) ++ans.second;
            else --ans.first;
        }
        return ans;
    };
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (checkForIntersect(mid).first != -1) hi = mid;
        else lo = mid + 1;
    }
    auto [x, y] = checkForIntersect(lo);
    printf("%d\n", lo);
    for (int i = 0; i < x; ++i) printf("B");
    for (int i = 0; i < y; ++i) printf("N");
    printf("\n");
}