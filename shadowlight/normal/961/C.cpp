#include <bits/stdc++.h>
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
    vector <vector <int> > d(4, vector <int> (2, 0));
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c - '0' == (i + j) % 2) {
                    d[t][0]++;
                } else {
                    d[t][1]++;
                }
            }
        }
    }
    int res = INF;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            if (a == b) continue;
            for (int c = 0; c < 4; c++) {
                if (a == c || b == c) continue;
                int de = 6 - a - b - c;
                res = min(res, d[a][0] + d[b][1] + d[c][0] + d[de][1]);
            }
        }
    }
    cout << res;
}