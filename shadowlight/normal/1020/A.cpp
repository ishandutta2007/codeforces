#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int a, b;

pair <int, int> get(int d) {
    if (d > b) {
        return {d - b, b};
    }
    if (d < a) {
        return {a - d, a};
    }
    return {0, d};
}

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
    int n, h, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        auto p = get(fa);
        if (ta == tb) {
            cout << abs(fa - fb) << "\n";
            continue;
        }
        cout << abs(ta - tb) + p.first + abs(p.second - fb) << "\n";
    }
}