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
    int n, a, b;
    cin >> n >> a >> b;
    int cnta = -1;
    int cntb;
    for (int x = 0; x * a <= n; x++) {
        int y = n - x * a;
        if (y % b) continue;
        cnta = x;
        cntb = y / b;
        break;
    }
    if (cnta == -1) {
        cout << -1;
        return 0;
    }
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    int now = 0;
    for (int i = 0; i < cnta; i++) {
        p[now + a - 1] = now;
        now += a;
    }
    for (int i = 0; i < cntb; i++) {
        p[now + b - 1] = now;
        now += b;
    }
    for (int x : p) {
        cout << x + 1 << " ";
    }
}