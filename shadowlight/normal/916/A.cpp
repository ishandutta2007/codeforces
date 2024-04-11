#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

bool good(int h, int m) {
    return h % 10 == 7 || h / 10 == 7 || m % 10 == 7 || m / 10 == 7;
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
    int x;
    cin >> x;
    int h, m;
    cin >> h >> m;
    int k = 0;
    while (!good(h, m)) {
        k++;
        m -= x;
        if (m < 0) {
            m += 60;
            h--;
        }
        if (h < 0) {
            h += 24;
        }
        //cout << h << " " << m << "\n";
    }
    cout << k;
}