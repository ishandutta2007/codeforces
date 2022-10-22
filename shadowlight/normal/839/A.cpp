#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int bal = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int otd = min(x + bal, 8);
        sum += otd;
        bal += x - otd;
        if (sum >= k) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}