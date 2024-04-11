#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int h1, m1, h2, m2;
    char tr;
    cin >> h1 >> tr >>  m1 >> h2 >> tr >> m2;
    int a = h1 * 60 + m1, b = h2 * 60 + m2;
    int d = (a + b) / 2;
    if (d / 60 < 10) {
        cout << "0";
    }
    cout << d / 60 << ":";
    if (d % 60 < 10) {
        cout << "0";
    }
    cout << d % 60 << "\n";
}